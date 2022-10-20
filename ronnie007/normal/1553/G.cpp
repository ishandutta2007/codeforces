#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MXVAL 1000001

int n , q ;
int a[ MAXN ] ;
vector < int > divs[ MAXN ] ;
bool pr[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;
vector < int > comp[ MAXN ] ;

set < pair < int , int > > s ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = get ( x ) ;
    int k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 2 ; i <= MXVAL ; ++ i ) {
        if ( pr[ i ] == true ) { continue ; }
        for ( int j = i ; j <= MXVAL ; j += i ) {
            divs[ j ].push_back ( i ) ;
            pr[ j ] = true ;
        }
    }
}

void solve ( ) {
    for ( int i = 2 ; i <= MXVAL ; ++ i ) {
        if ( divs[ i ].size ( ) != 1 ) { continue ; }
        prv[ i ] = -1 , rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = divs[ a[ i ] ].size ( ) ;
        for ( int j = 0 ; j + 1 < sz ; ++ j ) {
            unite ( divs[ a[ i ] ][ j ] , divs[ a[ i ] ][ j + 1 ] ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = a[ i ] + 1 ;
        int k1 = get ( divs[ a[ i ] ].front ( ) ) ;
        int k2 ;
        for ( auto x : divs[ aux ] ) {
            k2 = get ( x ) ;
            s.insert ( { k1 , k2 } ) ;
            s.insert ( { k2 , k1 } ) ;
        }
        int sz = divs[ aux ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            k1 = get ( divs[ aux ][ j ] ) ;
            for ( int t = j + 1 ; t < sz ; ++ t ) {
                k2 = get ( divs[ aux ][ t ] ) ;
                s.insert ( { k1 , k2 } ) ;
                s.insert ( { k2 , k1 } ) ;
            }
        }
    }
    while ( q > 0 ) {
        -- q ;
        int x , y ; cin >> x >> y ;
        int k1 = get ( divs[ a[ x ] ].front ( ) ) ;
        int k2 = get ( divs[ a[ y ] ].front ( ) ) ;
        if ( k1 == k2 ) {
            cout << "0\n" ;
            continue ; 
        }
        if ( s.find ( { k1 , k2 } ) != s.end ( ) ) {
            cout << "1\n" ;
            continue ;
        }
        cout << "2\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}