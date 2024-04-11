#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

long long ans = 0 ;

int mx = -1 , root ;

priority_queue < int > q ;

int dp[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( prv == x ) { continue ; }
        dfs ( x , vertex ) ;
    }
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    q.push ( 0 ) ;
    q.push ( 0 ) ;
    for ( auto x : v[ vertex ] ) {
        if ( prv == x ) { continue ; }
        q.push ( dp[ x ] ) ;
    }
    if ( vertex == root && v[ vertex ].size ( ) == 1 ) {
        ans += a[ vertex ] ;
        if ( q.top ( ) < a[ vertex ] ) {
            ans += a[ vertex ] - q.top ( ) ;
        }
        return ;
    }
    int take = 1 ;
    if ( vertex == root ) { take = 2 ; }
    dp[ vertex ] = a[ vertex ] ;
    while ( take > 0 ) {
        int x = q.top ( ) ;
        q.pop ( ) ;
        dp[ vertex ] = max ( dp[ vertex ] , x ) ;
        if ( x < a[ vertex ] ) { ans += a[ vertex ] - x ; }
        -- take ;
    }
}

void input ( ) {
    cin >> n ;
    mx = root = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < a[ i ] ) {
            mx = a[ i ] , root = i ;
        }
    }
}

void solve ( ) {
    if ( n == 2 ) {
        cout << 2 * max ( a[ 1 ] , a[ 2 ] ) << "\n" ;
        return ;
    }
    dfs ( root , -1 ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}