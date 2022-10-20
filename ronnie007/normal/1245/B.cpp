#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int n ;
int f[ 4 ] ;

string a ;

int get ( char c ) {
    if ( c == 'R' ) { return 0 ; }
    if ( c == 'P' ) { return 1 ; }
    return 2 ;
}

char rev ( int x ) {
    if ( x == 0 ) { return 'R' ; }
    if ( x == 1 ) { return 'P' ; }
    return 'S' ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> f[ i ] ;
    }
    cin >> a ;
}

void solve ( ) {
    string ret = "" ;
    int tot = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int x = get ( a[ i ] ) ;
        x = ( x + 1 ) % 3 ;
        if ( f[ x ] > 0 ) {
            ++ tot ;
            -- f[ x ] ;
            ret += rev ( x ) ;
        }
        else {
            ret += '_' ;
        }
    }
    if ( 2 * tot >= n ) {
        cout << "YES\n" ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ret[ i ] == '_' ) {
                for ( int j = 0 ; j < 3 ; ++ j ) {
                    if ( f[ j ] > 0 ) {
                        -- f[ j ] ;
                        ret[ i ] = rev ( j ) ;
                        break ;
                    }
                }
            }
        }
        cout << ret << "\n" ;
    }
    else {
        cout << "NO\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}