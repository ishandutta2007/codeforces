#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

string s ;

void input ( ) {
    cin >> s ;
}

void solve ( ) {
    int aux = 0 ;
    int sz = s.size ( ) ;
    if ( ( sz & 1 ) != 0 ) {
        aux = -1 ;
        for ( int i = 1 ; i < sz ; ++ i ) {
            if ( s[ i ] == '1' ) { aux = 0 ; break ; }
        }
    }
    cout << ( sz + 1 + aux ) / 2 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}