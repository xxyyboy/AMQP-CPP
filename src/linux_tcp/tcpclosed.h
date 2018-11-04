/**
 *  TcpClosed.h
 *
 *  Class that is used when the TCP connection ends up in a closed state
 *
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2015 - 2018 Copernica BV
 */

/**
 *  Include guard
 */
#pragma once

/**
 *  Set up namespace
 */
namespace AMQP {
    
/**
 *  Class definition
 */
class TcpClosed : public TcpState
{
public:
    /**
     *  Constructor
     *  @param  parent      The parent object
     */
    TcpClosed(TcpParent *parent) : 
        TcpState(parent) {}

    /**
     *  Constructor
     *  @param  state       The to-be-copied state
     */
    TcpClosed(const TcpState *state) : 
        TcpState(state) {}
    
    /**
     *  Destructor
     */
    virtual ~TcpClosed() noexcept = default;
        
    /**
     *  Abort the operation
     *  @param  monitor     Monitor that can be used to check if the tcp connection is still alive
     *  @return TcpState
     */
    virtual TcpState *abort(const Monitor &monitor) override
    {
        // connection was closed and stays closed
        return this;
    }
};
    
/**
 *  End of namespace
 */
}

