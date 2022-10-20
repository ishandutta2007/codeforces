#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

int n ;
string a ;
int d[ (1<<20) ][ 27 ] ; 
int c[ (1<<20) ] ;
int val[ (1<<20) ] ;


void input ( )
    {
    cin >> a ; 
    n = a.size ( ) ;
    }

void getRMQ ( ) 
    {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( a[ i - 1 ] == '(' ) val[ i ] = 1 ;
        else val[ i ] = -1 ;
        }
    c[ 0 ] = 0 ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        c[ i ] = c[ i - 1 ] + val[ i ] ; 
        d[ i ][ 0 ] = c[ i ] ; 
        }
    for ( j = 1 ; j <= 20 ; j ++ ) 
        {
        for ( i = 1 ; i <= n ; i ++ ) 
            {
            d[ i ][ j ] = d[ i ][ j - 1 ] ; 
            if ( i + (1<<(j-1)) <= n ) 
                {
                d[ i ][ j ] = min ( d[ i ][ j ] , d[ i + (1<<(j-1)) ][ j - 1 ] ) ;
                }
            }
        }
    ///printf ( "%d\n" , d[ 7 ][ 2 ] ) ;
    }

int getmin ( int l , int r ) 
    {
    int i ;
    int ans = (1<<30) ;
    
    for (i = 20 ; i >= 0 ; i-- ) 
        {
        if (l + (1 << i) - 1 <= r ) 
            {
            ans = min ( ans, d[l][i] ) ;
            l += 1 << i ;
            }
        }
    
    return ans ;
    }



void solve ( ) 
    {
    int m ; 
    int l , r ; 
    int br ;
    int mn ;
    int sbal ;
    int ebal ;
    int ans = 0 ; 
    int i ;
    scanf ( "%d" , &m ) ;
    while ( m > 0 ) 
        {
        scanf ( "%d%d" , &l , &r ) ;
        /**
        for ( i = l ; i <= r ; i ++ ) 
            {
            cout << a[ i - 1 ] ;
            }
        cout << "\n" ;
        **/
        mn = getmin ( l , r ) ;
        br = r - l + 1 ;
        sbal = c[ l - 1 ] ;
        ebal = c[ r ] ;
        ///cout << mn << "\n" ;
        mn -= sbal ;
        ebal -= sbal ;
        ///printf ( "SBAL = %d ,  MN = %d\n" ,sbal ,  mn ) ;
        if ( mn < 0 ) 
            {
            br += mn ;
            ebal -= mn ;
            }
        ans = br - ebal ;
        printf ( "%d\n" , ans ) ;
        ///system( "pause" ) ;
        m -- ;
        }
    }


int main ( ) 
    {
    input ( ) ;
    getRMQ ( ) ;
    solve ( ) ;
    return 0 ; 
    }