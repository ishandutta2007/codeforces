#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int val[ MAXN ] ;
vector < int > v[ MAXN ] ;

int deg[ MAXN ] ;

pair < int , int > edges[ MAXN ] ;
int cost[ MAXN ] ;

priority_queue < pair < int , int > > q ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        deg[ i ] = 0 ;
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &val[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &edges[ i ].first , &edges[ i ].second ) ;
        ++ deg[ edges[ i ].first ] ;
        ++ deg[ edges[ i ].second ] ;
    }
}

void solve ( ) {
    long long init = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        init += val[ i ] ;
    }
    if ( n == 2 ) {
        printf ( "%lld\n" , init ) ;
        return ;
    }
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( deg[ i ] > 1 ) {
            q.push ( { val[ i ] , deg[ i ] - 1 } ) ;
        }
    }
    printf ( "%lld " , init ) ;
    for ( int i = 1 ; i < n - 1 ; ++ i ) {
        pair < int , int > aux = q.top ( ) ;
        q.pop ( ) ;
        init += aux.first ;
        -- aux.second ;
        if ( aux.second > 0 ) { q.push ( aux ) ; }
        printf ( "%lld " , init ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    scanf ( "%d" , &t ) ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}