#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 1007

int n , m ;
string a[ MAXN ] ;
int c[ MAXN ] ;
int f[ MAXN ][ 6 ] ;


void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
        for ( int j = 0 ; j < m ; ++ j ) {
            ++ f[ j ][ ( a[ i ][ j ] - 'A' ) ] ;
        }
    }
    for ( int i = 0 ; i < m ; ++ i ) {
        cin >> c[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i < m ; i ++ ) {
        int mx = 0 ;
        for ( int j = 0 ; j < 5 ; ++ j ) {
            if ( mx < f[ i ][ j ] ) {
                mx = f[ i ][ j ] ;
            }
        }
        ans += mx * c[ i ] ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}