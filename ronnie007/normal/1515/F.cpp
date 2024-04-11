#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , c ;
long long a[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

int prv[ MAXN ] ;
bool fl[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}


void input ( ) {
    int m ;
    scanf ( "%d%d%d" , &n , &m , &c ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lld" , &a[ i ] ) ;
        prv[ i ] = -1 ; 
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
}

void solve ( ) {
    priority_queue < pair < long long , int > > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        q.push ( { a[ i ] , i } ) ;
    }
    vector < int > ans ;
    while ( q.empty ( ) == false ) {
        if ( ans.size ( ) == n - 1 ) { break ; }
        auto [ sm , vertex ] = q.top ( ) ;
        q.pop ( ) ;
        if ( vertex != get ( vertex ) ) { continue ; }
        if ( sm != a[ get ( vertex ) ] ) { continue ; }
        while ( v[ vertex ].empty ( ) == false ) {
            if ( get ( v[ vertex ].back ( ).first ) == vertex ) {
                v[ vertex ].pop_back ( ) ;
            }
            else { break ; }
        }
        if ( v[ vertex ].empty ( ) == true ) {
            printf ( "NO\n" ) ;
            return ;
        }
        int wh = get ( v[ vertex ].back ( ).first ) ;
        ans.push_back ( v[ vertex ].back ( ).second ) ;
        v[ vertex ].pop_back ( ) ;

        if ( sm + a[ wh ] < c ) {
            printf ( "NO\n" ) ;
            return ;
        }
        if ( v[ vertex ].size ( ) < v[ wh ].size ( ) ) {
            swap ( vertex , wh ) ;
        }
        for ( auto aux : v[ wh ] ) {
            v[ vertex ].push_back ( aux ) ;
        }
        a[ vertex ] += a[ wh ] - c ;
        a[ wh ] = 0 ;
        prv[ wh ] = vertex ;
        fl[ wh ] = true ;
        q.push ( { a[ vertex ] , vertex } ) ;
    }
    printf ( "YES\n" ) ;
    for ( auto x : ans ) {
        printf ( "%d\n" , x ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}