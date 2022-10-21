#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 1007
#define inf 1000000007

int n ;
long long init , add , nxt ;

long long a[ MAXN ] ;
long long cost[ MAXN ] ;

long long dp[ MAXN ][ 10 * MAXN ] ;
int tot = 0 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    scanf ( "%I64d%I64d%I64d" , &init , &add , &nxt ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        tot += a[ i ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &cost[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= tot ; j ++ ) {
            dp[ i ][ j ] = -inf ;
        }
    }
    dp[ 0 ][ 0 ] = init ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j <= tot ; j ++ ) {
            if ( dp[ i ][ j ] < 0 ) { continue ; }
            for ( t = 0 ; t <= a[ i + 1 ] ; t ++ ) {
                if ( dp[ i ][ j ] - cost[ i + 1 ] * t < 0 ) { break ; }
                long long aux = dp[ i ][ j ] - cost[ i + 1 ] * t ;
                aux += nxt ;
                aux = min ( aux , init + add * ( j + t ) ) ;
                if ( dp[ i + 1 ][ j + t ] < aux ) {
                    dp[ i + 1 ][ j + t ] = aux ;
                }
            }
        }
    }
    int ans = 0 ;
    for ( i = 0 ; i <= tot ; i ++ ) {
        if ( dp[ n ][ i ] >= 0 ) { ans = i ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}