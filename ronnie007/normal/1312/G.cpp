#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

struct node {
    int to[ 26 ] ;
    int subtree ;
    node ( ) {
        for ( int i = 0 ; i < 26 ; ++ i ) {
            to[ i ] = 0 ;
        }
        subtree = 0 ;
    }
};

vector < node > v ;

int n , q ;
int query_pos[ MAXN ] ;
int ans[ MAXN ] ;

int dp[ MAXN ] ;

void init ( int vertex ) {
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( v[ vertex ].to[ i ] == 0 ) { continue ; }
        init ( v[ vertex ].to[ i ] ) ;
        v[ vertex ].subtree += v[ v[ vertex ].to[ i ] ].subtree ;
    }
}

void dfs ( int vertex , int mintp ) {
    int coef = 0 ;
    if ( query_pos[ vertex ] > 0 ) {
        dp[ vertex ] = min ( dp[ vertex ] , mintp + 1 ) ;
        coef = 1 ;
        ans[ query_pos[ vertex ] ] = dp[ vertex ] ;
    }
    mintp += coef ;
    if ( mintp > dp[ vertex ] + coef ) {
        mintp = dp[ vertex ] + coef ;
    }
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( v[ vertex ].to[ i ] == 0 ) { continue ; }
        dp[ v[ vertex ].to[ i ] ] = dp[ vertex ] + 1 ;
        dfs ( v[ vertex ].to[ i ] , mintp ) ;
        mintp += v[ v[ vertex ].to[ i ] ].subtree ;
    }
}

void input ( ) {
    cin >> n ;
    v.resize ( n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int prv ;
        char c ;
        cin >> prv >> c ;
        v[ prv ].to[ ( c - 'a' ) ] = i ;
    }
    cin >> q ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x ;
        cin >> x ;
        query_pos[ x ] = i ;
        v[ x ].subtree = 1 ;
    }
}

void solve ( ) {
    init ( 0 ) ;
    dfs ( 0 , 0 ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}