#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
vector < int > out[ MAXN ] ;
vector < int > in[ MAXN ] ;

bool fl[ MAXN ] ;

stack < int > cand ;

void input ( ) {
    int m ; scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        out[ x ].push_back ( y ) ;
        in[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl[ i ] == true ) { continue ; }
        cand.push ( i ) ;
        for ( auto x : out[ i ] ) { fl[ x ] = true ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) { fl[ i ] = false ; }
    vector < int > ans ;
    while ( cand.empty ( ) == false ) {
        int x = cand.top ( ) ;
        cand.pop ( ) ;
        bool bad = false ;
        for ( auto y : in[ x ] ) {
            if ( fl[ y ] == true ) {
                bad = true ;
                break ;
            }
        }
        if ( bad == false ) {
            fl[ x ] = true ;
            ans.push_back ( x ) ;
        }
    }
    printf ( "%d\n" , ans.size ( ) ) ;
    for ( auto x : ans ) {
        printf ( "%d " , x ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}