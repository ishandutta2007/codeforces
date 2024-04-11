#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 2007
int n , m ;
int profit[ 2 * MAXN ] ;

long long dp[ 2 * MAXN ][ MAXN ] ;

struct tuhla {
    int val ;
    int cost ;
    bool operator < ( tuhla other ) const {
        return val < other.val ;
    }
};
tuhla a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].val ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].cost ) ;
    }
    for ( int i = 1 ; i <= n + m ; ++ i ) {
        scanf ( "%d" , &profit[ i ] ) ;
    }
    //sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    long long inf = 1 ;
    for ( int i = 1 ; i <= 18 ; ++ i ) { inf *= 10 ; }
    for ( int i = 0 ; i <= n + m ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = -inf ;
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = n - 1 ; j >= 0 ; -- j ) {
            if ( dp[ a[ i ].val ][ j ] > -inf ) {
                dp[ a[ i ].val ][ j + 1 ] = max ( dp[ a[ i ].val ][ j + 1 ] , dp[ a[ i ].val ][ j ] + profit[ a[ i ].val ] - a[ i ].cost ) ;
            }
        }
        for ( int j = n ; j >= 0 ; -- j ) {
            int id = a[ i ].val ;
            int cnt = j ;
            while ( cnt > 0 ) {
                if ( dp[ id ][ cnt ] > -inf ) {
                    dp[ id + 1 ][ ( cnt >> 1 ) ] = max ( dp[ id + 1 ][ ( cnt >> 1 ) ] , dp[ id ][ cnt ] + ( cnt >> 1 ) * profit[ id + 1 ] ) ;
                }
                ++ id , cnt >>= 1 ;
            }
        }        
        for ( int j = 1 ; j <= n + m ; ++ j ) {
            dp[ j ][ 0 ] = max ( dp[ j ][ 0 ] , dp[ j - 1 ][ 0 ] ) ;
            dp[ j ][ 0 ] = max ( dp[ j ][ 0 ] , dp[ j - 1 ][ 1 ] ) ;            
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n + m ; ++ i ) {
        ans = max ( ans , dp[ i ][ 1 ] ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}