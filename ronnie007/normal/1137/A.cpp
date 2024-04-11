#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;

int a[ MAXN ][ MAXN ] ;

int s[ MAXN ][ MAXN ] ;
int g[ MAXN ][ MAXN ] ;


void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        vector < pair < int , int > > v ;
        for ( int j = 1 ; j <= m ; ++ j ) {
            v.push_back ( { a[ i ][ j ] , j } ) ;
        }
        sort ( v.begin ( ) , v.end ( ) ) ;
        set < int > aux ;
        int pos = 0 ;
        for ( int t = 0 ; t < m ; ++ t ) {
            int val = v[ t ].first , j = v[ t ].second ;
            while ( v[ pos ].first < val ) { aux.insert ( v[ pos ].first ) ; ++ pos ; }
            s[ i ][ j ] = max ( s[ i ][ j ] , (int)aux.size ( ) ) ;
        }
        aux.clear ( ) ;
        pos = m - 1 ;
        for ( int t = m - 1 ; t >= 0 ; -- t ) {
            int val = v[ t ].first , j = v[ t ].second ;
            while ( v[ pos ].first > val ) { aux.insert ( v[ pos ].first ) ; -- pos ; }
            g[ i ][ j ] = max ( g[ i ][ j ] , (int)aux.size ( ) ) ;
        }
    }

    for ( int j = 1 ; j <= m ; ++ j ) {
        vector < pair < int , int > > v ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            v.push_back ( { a[ i ][ j ] , i } ) ;
        }
        sort ( v.begin ( ) , v.end ( ) ) ;
        set < int > aux ;
        int pos = 0 ;
        for ( int t = 0 ; t < n ; ++ t ) {
            int val = v[ t ].first , i = v[ t ].second ;
            while ( v[ pos ].first < val ) { aux.insert ( v[ pos ].first ) ; ++ pos ; }
            s[ i ][ j ] = max ( s[ i ][ j ] , (int)aux.size ( ) ) ;
        }
        aux.clear ( ) ;
        pos = n - 1 ;
        for ( int t = n - 1 ; t >= 0 ; -- t ) {
            int val = v[ t ].first , i = v[ t ].second ;
            while ( v[ pos ].first > val ) { aux.insert ( v[ pos ].first ) ; -- pos ; }
            g[ i ][ j ] = max ( g[ i ][ j ] , (int)aux.size ( ) ) ;
        }
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cout << s[ i ][ j ] + g[ i ][ j ] + 1 << " " ;
        }
        cout << "\n" ;
    }
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