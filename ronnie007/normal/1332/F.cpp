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
#include<random>
using namespace std ;

#define MOD 998244353
#define MAXN 300007

int n ;
vector < int > v[ MAXN ] ;

long long dp[ MAXN ][ 2 ] ;

long long unused[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    dp[ vertex ][ 0 ] = dp[ vertex ][ 1 ] = 0 ;
    unused[ vertex ] = 1 ;
    
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
        long long h0 , h1 ;
        
        long long coef1 = ( dp[ v[ vertex ][ i ] ][ 1 ] + dp[ v[ vertex ][ i ] ][ 0 ] + unused[ v[ vertex ][ i ] ] ) % MOD ;

        h0 = ( dp[ vertex ][ 0 ] * coef1 ) % MOD ;
        h1 = ( dp[ vertex ][ 1 ] * coef1 ) % MOD ;

        dp[ vertex ][ 0 ] = ( ( dp[ vertex ][ 0 ] + unused[ vertex ] ) * ( coef1 + unused[ v[ vertex ][ i ] ] ) ) % MOD ;
        coef1 = ( dp[ v[ vertex ][ i ] ][ 0 ] + unused[ v[ vertex ][ i ] ] ) % MOD ;        
        dp[ vertex ][ 1 ] = ( ( dp[ vertex ][ 1 ] + unused[ vertex ] ) * coef1 ) % MOD ;

        coef1 = ( dp[ v[ vertex ][ i ] ][ 1 ] + dp[ v[ vertex ][ i ] ][ 0 ] + unused[ v[ vertex ][ i ] ] ) % MOD ;
        unused[ vertex ] = ( unused[ vertex ] * coef1 ) % MOD ;

        dp[ vertex ][ 0 ] = ( dp[ vertex ][ 0 ] + h0 ) % MOD ;
        dp[ vertex ][ 1 ] = ( dp[ vertex ][ 1 ] + h1 ) % MOD ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , ( dp[ 1 ][ 0 ] + dp[ 1 ][ 1 ] + unused[ 1 ] - 1 + MOD ) % MOD ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}