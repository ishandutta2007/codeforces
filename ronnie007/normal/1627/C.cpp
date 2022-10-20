#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < pair < int , int > > v[ MAXN ] ;

int ans[ MAXN ] ;

void dfs ( int x , int prv , int c ) {
    for ( auto [ y , wh ] : v[ x ] ) {
        if ( y == prv ) { continue ; }
        if ( c == 0 ) { ans[ wh ] = 2 ; } 
        else { ans[ wh ] = 3 ; }
        dfs ( y , x , c ^ 1 ) ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        if ( sz > 2 ) {
            cout << "-1\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].size ( ) == 1 ) {
            dfs ( i , -1 , 0 ) ;
        }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        cout << ans[ i ] << " " ; 
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}