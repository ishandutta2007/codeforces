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

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "Impossible\n" ;
        return ;
    }
    for ( int i = 0 ; i < n / 2 ; ++ i ) {
        if ( a[ i ] != a[ 0 ] ) { break ; }
        if ( i == ( n / 2 - 1 ) ) {
            cout << "Impossible\n" ;
            return ;
        }
    }
    string aux ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        aux.clear ( ) ;
        for ( int j = i ; j < n ; ++ j ) {
            aux += a[ j ] ;
        }
        for ( int j = 0 ; j < i ; ++ j ) {
            aux += a[ j ] ;
        }
        if ( aux == a ) { continue ; }
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( aux[ j ] != aux[ n - j - 1 ] ) { break ; }
            if ( j == ( n - 1 ) ) {
                cout << "1\n" ;
                return ;
            }
        }
    }
    cout << "2\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}