#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MOD 1000000007

#define MAXN 100007
#define LOG 20


int n ;
long long a[ MAXN ] ;

vector < int > v[ MAXN ] ;

int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
long long gcd_vals[ MAXN ][ LOG ] ;

long long ans = 0 ;


long long w ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

long long cur_gcd ;

int lift ( int vertex ) {
    int init = vertex ;
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( (1<<i) <= lvl[ vertex ] ) {
            long long aux = w ( cur_gcd , gcd_vals[ vertex ][ i ] ) ;
            if ( aux == cur_gcd ) {
                ans += ( cur_gcd * (1<<i) ) % MOD ;
                if ( ans >= MOD ) { ans -= MOD ; }
                vertex = LCA[ vertex ][ i ] ;
            }
        }
    }
    if ( init == vertex ) {
        vertex = LCA[ vertex ][ 0 ] ;
        ans += cur_gcd % MOD ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    cur_gcd = w ( cur_gcd , a[ vertex ] ) ;
    return vertex ;
}

void calc ( int vertex ) {
    cur_gcd = a[ vertex ] ;
    while ( vertex > 0 ) {
        vertex = lift ( vertex ) ;
    }
}

void dfs ( int vertex , int prv ) {
    if ( prv != -1 ) {
        for ( int i = 1 ; i < LOG ; ++ i ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
            gcd_vals[ vertex ][ i ] = w ( gcd_vals[ vertex ][ i - 1 ] , gcd_vals[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ) ;
        }
    }
    calc ( vertex ) ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        gcd_vals[ v[ vertex ][ i ] ][ 0 ] = a[ vertex ] ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }

}

void solve ( ) {
    lvl[ 1 ] = 1 ;
    dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}