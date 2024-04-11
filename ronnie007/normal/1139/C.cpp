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

#define MAXN 100007
#define MOD 1000000007

int n , k ;
int prv[ MAXN ] ;
int sz[ MAXN ] ;


int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
        sz[ k2 ] += sz[ k1 ] ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        prv[ i ] = -1 ;
        sz[ i ] = 1 ;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( z == 0 ) {
            UNITE ( x , y ) ;
        }
    }
}

void solve ( ) {
    int i , j ;
    long long ans = 1 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        ans *= n ;
        ans %= MOD ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( prv[ i ] != -1 ) { continue ; }
        long long cur = 1 ;
        for ( j = 1 ; j <= k ; j ++ ) {
            cur = ( cur * sz[ i ] ) % MOD ;
        }
        ans = ( ans - cur + MOD ) % MOD ;
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