#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
int cnt[ MAXN ] ;
int type[ MAXN ] ;

bool dp[ MAXN ] ;
pair < int , int > prv[ MAXN ] ;
vector < int > cnt_list[ MAXN ] ;
vector < int > dep_list[ MAXN ] ;
int mxdep ;

void dfs ( int vertex ) {
    ++ cnt[ lvl[ vertex ] ] ;
    mxdep = max ( mxdep , lvl[ vertex ] ) ;
    dep_list[ lvl[ vertex ] ].push_back ( vertex ) ;
    for ( auto x : v[ vertex ] ) {
        lvl[ x ] = lvl[ vertex ] + 1 ;
        dfs ( x ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ; scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    map < int , int > w ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ++ w[ cnt[ i ] ] ;
        cnt_list[ cnt[ i ] ].push_back ( i ) ;
    }
    dp[ 0 ] = true ;
    for ( auto [ x , y ] : w ) {
        for ( int rem = 0 ; rem < x ; ++ rem ) {
            deque < int > q ;
            for ( int i = rem ; i <= n ; i += x ) {
                if ( dp[ i ] == true ) { q.push_back ( i ) ; }
                while ( q.empty ( ) == false && q.front ( ) < i - y * x ) { q.pop_front ( ) ; }
                if ( q.empty ( ) == false && dp[ i ] == false ) {
                    dp[ i ] = true ;
                    prv[ i ] = make_pair ( x , ( i - q.front ( ) ) / x ) ;
                }
            }
        }
    }
    if ( dp[ k ] == true ) {
        printf ( "%d\n" , mxdep + 1 ) ;
        int dummy = k ;
        while ( dummy > 0 ) {
            auto [ coef , h ] = prv[ dummy ] ;
            dummy -= coef * h ;
            for ( int i = 0 ; i < h ; ++ i ) {
                for ( auto j : dep_list[ cnt_list[ coef ][ i ] ] ) {
                    type[ j ] = 2 ;
                }
            }
        }
    }
    else {
        printf ( "%d\n" , mxdep + 2 ) ;
        int lft1 = n - k , lft2 = k ;
        for ( int i = 0 ; i <= n ; ++ i ) {
            int hh = 0 ;
            int tot = dep_list[ i ].size ( ) ;
            for ( auto j : dep_list[ i ] ) {
                hh += ( v[ j ].size ( ) > 0 ) ;
            }
            if ( lft1 >= tot ) {
                lft1 -= tot ;
            }
            else if ( lft2 >= tot ) {
                lft2 -= tot ;
                for ( auto j : dep_list[ i ] ) {
                    type[ j ] = 2 ;
                }
            }
            else {
                if ( lft1 >= hh ) {
                    lft1 -= hh ;
                }
                else {
                    lft2 -= hh ;
                    for ( auto j : dep_list[ i ] ) {
                        if ( v[ j ].size ( ) > 0 ) {
                            type[ j ] = 2 ;
                        }
                    }
                }
                for ( auto j : dep_list[ i ] ) {
                    if ( v[ j ].size ( ) == 0 ) {
                        if ( lft1 > 0 ) { -- lft1 ; }
                        else { -- lft2 ; type[ j ] = 2 ; }
                    }
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( type[ i ] == 2 ) { printf ( "a" ) ; }
        else { printf ( "b" ) ; }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}