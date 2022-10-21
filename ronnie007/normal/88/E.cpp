#include<iostream>
#include<stdio.h>
#include<set>
using namespace std ;

int sg[ 100007 ] ;
int bestmove[ 100007 ] ;

int main ( )
    {
    sg[ 1 ] = 0 ;
    sg[ 2 ] = 0 ;
    int i , j , t ;
    int n ;
    scanf ( "%d" , &n ) ;
    set < int > s ;
    int st , en ;
    int h ;
    for ( i = 3 ; i <= n ; i ++ )
        {
        s.clear ( ) ;
        for ( j = 2 ; j * ( j + 1 ) / 2 <= i ; j ++ )
            {
            if ( ( 2 * i ) % j == 0 )
                {
                int ans = 0 ;
                h = ( 2 * i ) / j ;
                if ( ( h - j + 1 ) % 2) continue;
                st = ( h - j + 1 ) / 2;
                en = h - st ;
                ///s.insert( prefix[ b ] ^ prefix[ a ] ) ;
                ///if ( ( prefix[ b ] ^ prefix[ a ] ) == 0 ) bestmove[ i ] =
                if ( st > 0 && en > st )
                    {
                    for ( t = st ; t <= en ; t ++ )
                        {
                        ans = ans ^ sg[ t ] ;
                        }
                    s.insert ( ans ) ;
                    if ( ans == 0 && bestmove[ i ] == 0 ) bestmove[ i ] = j ;
                    }
                }
            }
        for ( j = 0 ; j <= 10000 ; j ++ )
            {
            if ( s.find( j ) == s.end( )  ) break ;
            }
        sg[ i ] = j ;
        }
    if ( sg[ n ] == 0 ) printf ( "-1\n" ) ;
    else printf ( "%d\n", bestmove[ n ] ) ;
    return 0 ;
    }