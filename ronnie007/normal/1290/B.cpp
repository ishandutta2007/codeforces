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

#define MAXN 200007

int n ;
string a ;

int cnt[ MAXN ][ 31 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            cnt[ i ][ j ] = cnt[ i - 1 ][ j ] ;
        }
        ++ cnt[ i ][ ( a[ i - 1 ] - 'a' ) ] ;
    }
}

void solve ( ) {
    int q ; 
    cin >> q ;
    while ( q -- ) {
        int x , y ;
        cin >> x >> y ;
        if ( x == y ) { cout << "Yes\n" ; continue ; }
        if ( a[ x - 1 ] != a[ y - 1 ] ) { cout << "Yes\n" ; continue ; }
        int h = 0 ;
        for ( int i = 0 ; i < 26 ; ++ i ) {
            h += ( cnt[ y ][ i ] != cnt[ x - 1 ][ i ] ) ;
        }
        if ( h >= 3 ) { cout << "Yes\n" ; continue ; }
        cout << "No\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}