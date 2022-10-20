#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

long long pref[ MAXN ] ;

int used[ MAXN ] ;

int ans = 0 ;

void dfs ( int vertex ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    if ( pref[ vertex ] > a[ vertex ] ) { used[ vertex ] = 1 ; }
    for ( i = 0 ; i < sz ; i ++ ) {
        long long aux = max ( pref[ vertex ] , 0LL ) ;
        aux += v[ vertex ][ i ].second ;
        pref[ v[ vertex ][ i ].first ] = aux ;
        dfs ( v[ vertex ][ i ].first ) ;
    }
}
void mark ( int vertex ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    if ( used[ vertex ] == 1 ) { return ; }
    ans ++ ;
    for ( i = 0 ; i < sz ; i ++ ) {
        mark ( v[ vertex ][ i ].first ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 2 ; i <= n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( make_pair ( i , y ) ) ;
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    mark ( 1 ) ;
    printf ( "%d\n" , n - ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}