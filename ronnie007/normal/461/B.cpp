#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

#define MOD 1000000007


// GNU Emacs 23 code

int n ;
// dp[ vertex ][ is there a black vertex in the current component ]
long long dp[ 100007 ][ 2 ] ;
int prev[ 100007 ] ;
int c[ 100007 ] ;
int used[ 100007 ] ;

vector < int > v[ 100007 ] ;



void dfs ( int vertex , int par ) {
    dp[ vertex ][ 0 ] = 0 ;
    dp[ vertex ][ 1 ] = 0 ;
    dp[ vertex ][ c[ vertex ] ] = 1 ; 
    int i , sz ;
    sz = v[ vertex ].size ( ) ;
    int h ; 
    long long p0 , p1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        h = v[ vertex ][ i ] ;
        if ( h != par ) {
            dfs ( h , vertex ) ;
            p0 = dp[ vertex ][ 0 ] ;
            p1 = dp[ vertex ][ 1 ] ;
            dp[ vertex ][ 0 ] = ( p0 * dp[ h ][ 0 ]  % MOD + p0 * dp[ h ][ 1 ] % MOD ) % MOD ;
            dp[ vertex ][ 1 ] = ( p1 * ( dp[ h ][ 0 ] + dp[ h ][ 1 ] ) % MOD + p0 * dp[ h ][ 1 ] % MOD ) % MOD ;
        }
    }
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> n ;
    int i ;
    int x ;
    for ( i = 1 ; i < n ; i ++ ) {
        cin >> x ;
        v[ x ].push_back ( i ) ;
        v[ i ].push_back ( x ) ;
        prev[ i ] = x ; 
    }
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> c[ i ] ;
    }
}

void solve ( )  {
    dfs ( 0 , -1 ) ;
    cout << dp[ 0 ][ 1 ] << "\n" ;
}