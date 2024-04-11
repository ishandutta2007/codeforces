#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;
int prv[ MAXN ] ;
int a[ MAXN ] ;
int ans[ MAXN ] ;

bool dfs ( int vertex ) {
    if ( a[ vertex ] == -1 ) {
        int mn = -1 ;
        for ( auto x : v[ vertex ] ) {
            if ( mn == -1 ) { mn = a[ x ] ; }
            if ( mn > a[ x ] ) { mn = a[ x ] ; } 
        }
        if ( mn == -1 ) { mn = a[ prv[ vertex ] ] ; }
        if ( a[ prv[ vertex ] ] > mn ) { return false ; }
        ans[ vertex ] = mn - a[ prv[ vertex ] ] ;
        a[ vertex ] = ans[ vertex ] + a[ prv[ vertex ] ] ;
        for ( auto x : v[ vertex ] ) {
            ans[ x ] = a[ x ] - a[ vertex ] ;
        }
    }
    for ( auto x : v[ vertex ] ) {
        bool ret = dfs ( x ) ;
        if ( ret == false ) { return false ; }
    }
    return true ;
}


void input ( ) {
    cin >> n ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        cin >> prv[ i ] ;
        v[ prv[ i ] ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    ans[ 1 ] = a[ 1 ] ;
    bool ret = dfs ( 1 ) ;
    if ( ret == false ) {
        cout << "-1\n" ;
        return ;
    }
    long long val = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        val += ans[ i ] ;
    }
    cout << val << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}