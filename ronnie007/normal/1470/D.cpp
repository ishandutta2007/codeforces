#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , m ;

vector < int > v[ MAXN ] ;

int rnk[ MAXN ] ;
int prv[ MAXN ] ;

int col[ MAXN ] ;
bool proc[ MAXN ] ;


int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    prv[ x ] = find ( prv[ x ] ) ;
    return prv[ x ] ;
}

void unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        v[ i ].clear ( ) ;
        col[ i ] = 0 ; proc[ i ] = false ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        unite ( x , y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}




void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( find ( i ) != find ( 1 ) ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    vector < int > ans ;
    queue < int > q ;
    q.push ( 1 ) ;
    col[ 1 ] = 1 ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        proc[ x ] = true ;
        if ( col[ x ] == 1 ) {
            bool fl = false ;
            for ( auto y : v[ x ] ) {
                if ( col[ y ] == 1 && proc[ y ] == true ) { fl = true ; break ; }
            }
            if ( fl == true ) { col[ x ] = 2 ; }
            else { ans.push_back ( x ) ; }
        }
        for ( auto y : v[ x ] ) {
            if ( col[ y ] == 0 ) {
                col[ y ] = 3 - col[ x ] ;
                q.push ( y ) ;
            }
        }
    }
        
    printf ( "YES\n" ) ;
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
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