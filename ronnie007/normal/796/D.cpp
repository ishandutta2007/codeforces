#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , k , mxlen ;
bool fl[ MAXN ] ;
vector < int > v[ MAXN ] ;

pair < int , int > edges[ MAXN ] ;
int dist[ MAXN ] ;
int ori[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &k , &mxlen ) ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x ; scanf ( "%d" , &x ) ;
        fl[ x ] = true ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &edges[ i ].first , &edges[ i ].second ) ;
        int x = edges[ i ].first , y = edges[ i ].second ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    queue < int > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl[ i ] == true ) {
            dist[ i ] = 1 ;
            ori[ i ] = i ;
            q.push ( i ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        if ( dist[ x ] == mxlen + 1 ) { continue ; }
        for ( auto to : v[ x ] ) {
            if ( dist[ to ] == 0 ) {
                ori[ to ] = ori[ x ] ;
                dist[ to ] = dist[ x ] + 1 ;
                q.push ( to ) ;
            }
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ans += ( ori[ edges[ i ].first ] != ori[ edges[ i ].second ] ) ;
    }
    printf ( "%d\n" , ans ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( ori[ edges[ i ].first ] != ori[ edges[ i ].second ] ) {
            printf ( "%d " , i ) ;
        }
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}