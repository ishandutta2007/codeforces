#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 700007

int n ;
string a[ 3 ] ;

int cnt[ 3 ][ 2 ] ;

int hh[ MAXN ] ;

void unite ( int x , int y , int sr ) {
    for ( int i = 0 ; i <= 4 * n ; ++ i ) {
        hh[ i ] = 0 ;
    }
    int mx = max ( cnt[ x ][ sr ] , cnt[ y ][ sr ] ) ;
    int wh = 0 ;
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        if ( ( a[ x ][ i ] - '0' ) == sr ) {
            ++ wh ;
        }
        else {
            ++ hh[ wh ] ;
        }
    }
    wh = 0 ;
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        if ( ( a[ y ][ i ] - '0' ) == sr ) {
            ++ wh ;
        }
        else {
            ++ hh[ wh ] ;
        }
    }
    for ( int i = 0 ; i <= mx ; ++ i ) {
        while ( hh[ i ] -- ) {
            if ( sr == 1 ) { cout << "0" ; }
            else { cout << "1" ; }
        }
        if ( i != mx ) {
            if ( sr == 1 ) { cout << "1" ; }
            else { cout << "0" ; }
        }
    }
    cout << "\n" ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> a[ i ] ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            cnt[ i ][ j ] = 0 ;
        }
        for ( int j = 0 ; j < 2 * n ; ++ j ) {
            ++ cnt[ i ][ ( a[ i ][ j ] - '0' ) ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = i + 1 ; j < 3 ; ++ j ) {
            if ( cnt[ i ][ 0 ] >= n && cnt[ j ][ 0 ] >= n ) {
                unite ( i , j , 0 ) ;
                return ;
            }
            if ( cnt[ i ][ 1 ] >= n && cnt[ j ][ 1 ] >= n ) {
                unite ( i , j , 1 ) ;
                return ;
            }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}