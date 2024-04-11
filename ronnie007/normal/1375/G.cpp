#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int cnt ;

void dfs ( int vertex , int prv , int c ) {
    cnt += c ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex , c ^ 1 ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 , 0 ) ;
    if ( cnt > n - cnt ) { cnt = n - cnt ; }
    printf ( "%d\n" , cnt - 1 ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}