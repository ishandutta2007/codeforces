#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 1007
#define MOD 1000000007

int n , k ;
string a ;
int brbits[ MAXN ] ;
int ops[ MAXN ] ;

long long dp[ MAXN ][ MAXN ][ 2 ] ;

void init_dp ( ) {
    int i , j , t ;
    dp[ 0 ][ 0 ][ 1 ] = 1 ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j <= n ; j ++ ) {
            for ( t = 0 ; t < 2 ; t ++ ) {
                if ( dp[ i ][ j ][ t ] == 0 ) { continue ; }
                int nw = t ;
                if ( 0 < ( a[ i ] - '0' ) ) { nw = 0 ; }
                dp[ i + 1 ][ j ][ nw ] += dp[ i ][ j ][ t ] ;
                if ( dp[ i + 1 ][ j ][ nw ] >= MOD ) {
                    dp[ i + 1 ][ j ][ nw ] -= MOD ;
                }
                if ( a[ i ] == '0' && t == 1 ) { continue ; }
                nw = t ;
                if ( 1 < ( a[ i ] - '0' ) ) { nw = 0 ; }
                dp[ i + 1 ][ j + 1 ][ nw ] += dp[ i ][ j ][ t ] ;
                if ( dp[ i + 1 ][ j + 1 ][ nw ] >= MOD ) {
                    dp[ i + 1 ][ j + 1 ][ nw ] -= MOD ;
                }
            }
        }
    }
}

void input ( ) {
    cin >> a ;
    cin >> k ;
    n = a.size ( ) ;
}

void solve ( ) {
    if ( k == 0 ) { cout << "1\n" ; return ; }
    int i ;
    for ( i = 1 ; i <= 1000 ; i ++ ) {
        brbits[ i ] = brbits[ ( i / 2 ) ] + ( i % 2 ) ;
    }
    ops[ 1 ] = 0 ;
    for ( i = 2 ; i <= 1000 ; i ++ ) {
        ops[ i ] = ops[ brbits[ i ] ] + 1 ;
    }
    init_dp ( ) ;
    long long ans = 0 ;
    k -- ;
    for ( i = 1 ; i <= 1000 ; i ++ ) {
        if ( ops[ i ] == k ) {
            ans += dp[ n ][ i ][ 0 ] ;
            if ( ans >= MOD ) { ans -= MOD ; }
        }
    }
    int cur = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '1' ) { cur ++ ; }
    }
    if ( ops[ cur ] == k ) { ans ++ ; }
    ans %= MOD ;
    if ( k == 0 ) {
        ans = ( ans - 1 + MOD ) % MOD ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}