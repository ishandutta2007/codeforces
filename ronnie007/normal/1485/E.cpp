#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int val[ MAXN ] ;

int lvl[ MAXN ] ;
int prv[ MAXN ] ;
vector < int > dep_list[ MAXN ] ;

long long dp[ MAXN ] ;

void dfs ( int vertex ) {
    dep_list[ lvl[ vertex ] ].push_back ( vertex ) ;
    for ( auto x : v[ vertex ] ) {
        lvl[ x ] = lvl[ vertex ] + 1 ;
        dfs ( x ) ;
    }
}


void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        lvl[ i ] = 0 ;
        prv[ i ] = 0 ;
        val[ i ] = 0 ;
        dep_list[ i ].clear ( ) ;
        dp[ i ] = 0 ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        cin >> prv[ i ] ;
        v[ prv[ i ] ].push_back ( i ) ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        cin >> val[ i ] ;
    }
    lvl[ 1 ] = 1 ;
    dfs ( 1 ) ;
    auto cmp = [ & ] ( int x , int y ) {
        return ( val[ x ] < val[ y ] ) ;
    };
    for ( int i = 2 ; i <= n ; ++ i ) {
        sort ( dep_list[ i ].begin ( ) , dep_list[ i ].end ( ) , cmp ) ;
    }
}

void solve ( ) {
    dp[ 1 ] = 0 ;
    long long ans = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int sz = dep_list[ i ].size ( ) ;
        if ( sz == 0 ) { break ; }
        long long mx = dp[ prv[ dep_list[ i ][ 0 ] ] ] - val[ dep_list[ i ][ 0 ] ] ;
        for ( int j = 1 ; j < sz ; ++ j ) {
            int where = dep_list[ i ][ j ] ;
            dp[ where ] = max ( dp[ where ] , val[ where ] + mx ) ;
            mx = max ( mx , dp[ prv[ where ] ] - val[ where ] ) ;
        }
        mx = dp[ prv[ dep_list[ i ][ sz - 1 ] ] ] + val[ dep_list[ i ][ sz - 1 ] ] ;
        for ( int j = sz - 2 ; j >= 0 ; -- j ) {
            int where = dep_list[ i ][ j ] ;
            dp[ where ] = max ( dp[ where ] , mx - val[ where ] ) ;
            mx = max ( mx , dp[ prv[ where ] ] + val[ where ] ) ;
        }
        int st = dep_list[ i ][ 0 ] ;
        int en = dep_list[ i ][ sz - 1 ] ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int where = dep_list[ i ][ j ] ;
            dp[ where ] = max ( dp[ where ] , dp[ prv[ where ] ] + val[ where ] - val[ st ] ) ;
            dp[ where ] = max ( dp[ where ] , dp[ prv[ where ] ] + val[ en ] - val[ where ] ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = max ( ans , dp[ i ] ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}