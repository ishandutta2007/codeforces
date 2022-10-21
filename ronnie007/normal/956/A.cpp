#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 57

int n , m ;
string a[ MAXN ] ;
bool used[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( used[ i ] == true ) { continue ; }
        for ( j = i + 1 ; j < n ; j ++ ) {
            for ( t = 0 ; t < m ; t ++ ) {
                if ( a[ i ][ t ] != a[ j ][ t ] ) { break ; }
            }
            if ( t == m ) { used[ j ] = true ; continue ; }
            for ( t = 0 ; t < m ; t ++ ) {
                if ( a[ i ][ t ] == '#' && a[ j ][ t ] == '#' ) {
                    printf ( "No\n" ) ;
                    return ;
                }
            }
        }
    }
    printf ( "Yes\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}