#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

int n ;


void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int i ;
    int br = 2 ;
    int id = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( id == 0 ) {
            cout << "a" ;
        }
        else {
            cout << "b" ;
        }
        br -- ;
        if ( br == 0 ) {
            id ^= 1 ;
            br = 2 ;
        }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}