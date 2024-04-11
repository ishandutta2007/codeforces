#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 300007
#define MAXK 12

int n , m , k ;
int a[ MAXN ] ;

long long f[ MAXK ] ;
long long nw[ MAXK ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    if ( m == 1 ) {
        long long sm = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            a[ i ] -= k ;
            sm += a[ i ] ;
            if ( sm < 0 ) { sm = 0 ; }
            if ( ans < sm ) { ans = sm ; }
        }
    }
    else {
        for ( int j = 0 ; j < m ; ++ j ) { nw[ j ] = f[ j ] = 0 ; }
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 0 ; j < m ; ++ j ) {
                if ( j >= i ) { break ; }
                int nxt = j + 1 ;
                if ( nxt >= m ) { nxt -= m ; }
                nw[ nxt ] = f[ j ] + a[ i ] ;
            }
            if ( nw[ 1 ] < a[ i ] ) {
                nw[ 1 ] = a[ i ] ;
            }
            if ( nw[ 0 ] < 0 ) {
                nw[ 0 ] = 0 ;
            }
            nw[ 1 ] -= k ;
            for ( int j = 0 ; j < m ; ++ j ) {
                f[ j ] = nw[ j ] ;
                if ( ans < f[ j ] ) { ans = f[ j ] ; }
            }
        }
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