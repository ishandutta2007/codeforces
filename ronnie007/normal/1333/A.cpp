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

int n , m ;

void input ( ) {
    cin >> n >> m ;
}

void solve ( ) {
    bool fl = false ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int h = ( i + j ) % 2 ;
            if ( ( n * m ) % 2 == 0 ) {
                if ( h == 1 && fl == false ) {
                    h = 0 ; fl = true ;
                }
            }
            if ( h == 0 ) { cout << "B" ; }
            else { cout << "W" ; }
        }
        cout << "\n" ;
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