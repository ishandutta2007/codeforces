#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n , m ;
struct edge {
    int fi , se ;
    bool used ;
};
edge a[ MAXN ] ;

int prv[ MAXN ] , rnk[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

bool unite ( int x , int y ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
        return true ;
    }
    return false ;
}

set < int > s ;

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].fi >> a[ i ].se ;
        a[ i ].used = false ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 , rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        a[ i ].used = unite ( a[ i ].fi , a[ i ].se ) ;
    }
    if ( m <= n + 1 ) {
        for ( int i = 1 ; i <= m ; ++ i ) {
            if ( a[ i ].used == true ) { cout << "0" ; }
            else { cout << "1" ; }
        }
        cout << "\n" ;
        return ;
    }
    s.clear ( ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( a[ i ].used == false ) {
            s.insert ( a[ i ].fi ) ;
            s.insert ( a[ i ].se ) ;
        }
    }
    if ( (int) s.size ( ) > 3 ) {
        for ( int i = 1 ; i <= m ; ++ i ) {
            if ( a[ i ].used == true ) { cout << "0" ; }
            else { cout << "1" ; }
        }
        cout << "\n" ;
        return ;
    }
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 , rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( a[ i ].used == false ) {
            s.insert ( i ) ;
        }
        a[ i ].used = false ;
    }
    int spec = *s.begin ( ) ;
    a[ spec ].used = unite ( a[ spec ].fi , a[ spec ].se ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( s.find ( i ) != s.end ( ) ) { continue ; }
        a[ i ].used = unite ( a[ i ].fi , a[ i ].se ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( a[ i ].used == true ) { cout << "0" ; }
        else { cout << "1" ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}