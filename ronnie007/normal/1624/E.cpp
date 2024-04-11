#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1007

int n , m ;
string a ;
string b[ MAXN ] ;

struct str {
    int st , en ;
    int pos ;
    str ( ) { st = en = pos = 0 ; }
    str ( int _st , int _en , int _pos ) {
        st = _st , en = _en , pos = _pos ;
    }
};

str wh2[ MAXN ] ;
str wh3[ MAXN ] ;

bool dp[ MAXN ] ;
str prv[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
    cin >> a ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        wh2[ i ] = wh3[ i ] = str ( ) ;
    }
}

vector < str > aux ;

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j + 1 < m ; ++ j ) {
            int id = ( b[ i ][ j ] - '0' ) * 10 + ( b[ i ][ j + 1 ] - '0' ) ;
            wh2[ id ] = str ( j + 1 , j + 2 , i ) ;
        }
        for ( int j = 0 ; j + 2 < m ; ++ j ) {
            int id = ( b[ i ][ j ] - '0' ) * 100 + ( b[ i ][ j + 1 ] - '0' ) * 10 + ( b[ i ][ j + 2 ] - '0' ) ;
            wh3[ id ] = str ( j + 1 , j + 3 , i ) ;
        }
    }
    for ( int i = 0 ; i <= m ; ++ i ) {
        dp[ i ] = false ;
        prv[ i ] = str ( ) ;
    }
    dp[ 0 ] = true ;
    for ( int i = 0 ; i < m ; ++ i ) {
        if ( dp[ i ] == false ) { continue ; }
        if ( i + 1 < m ) {
            int id = ( a[ i ] - '0' ) * 10 + ( a[ i + 1 ] - '0' ) ;
            if ( wh2[ id ].pos != 0 ) {
                dp[ i + 2 ] = true ;
                prv[ i + 2 ] = wh2[ id ] ;
            }
        }
        if ( i + 2 < m ) {
            int id = ( a[ i ] - '0' ) * 100 + ( a[ i + 1 ] - '0' ) * 10 + ( a[ i + 2 ] - '0' ) ;
            if ( wh3[ id ].pos != 0 ) {
                dp[ i + 3 ] = true ;
                prv[ i + 3 ] = wh3[ id ] ;
            }
        }
    }
    if ( dp[ m ] == false ) {
        cout << "-1\n" ;
        return ;
    }
    aux.clear ( ) ;
    int x = m ;
    while ( x > 0 ) {
        str hh = prv[ x ] ;
        aux.push_back ( hh ) ;
        x -= ( hh.en - hh.st + 1 ) ;
    }
    int sz = aux.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        cout << aux[ i ].st << " " << aux[ i ].en << " " << aux[ i ].pos << "\n" ;
    }
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