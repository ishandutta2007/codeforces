#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
string a ;

int cnt[ 3 ][ MAXN ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 3 ; ++ j ) {
            cnt[ j ][ i ] = cnt[ j ][ i - 1 ] ;
        }
        if ( a[ i - 1 ] == 'x' ) { ++ cnt[ 0 ][ i ] ; }
        if ( a[ i - 1 ] == 'y' ) { ++ cnt[ 1 ][ i ] ; }
        if ( a[ i - 1 ] == 'z' ) { ++ cnt[ 2 ][ i ] ; }
    }
}

void solve ( ) {
    int q ;
    cin >> q ;
    while ( q -- ) {
        int x , y ;
        cin >> x >> y ;
        int mn = n + 2 ;
        int mx = 0 ;
        for ( int i = 0 ; i < 3 ; ++ i ) {
            mn = min ( mn , cnt[ i ][ y ] - cnt[ i ][ x - 1 ] ) ;
            mx = max ( mx , cnt[ i ][ y ] - cnt[ i ][ x - 1 ] ) ;
        }
        if ( mx - mn <= 1 || y - x + 1 < 3 ) { cout << "YES\n" ; }
        else { cout << "NO\n" ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}