#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;


int n ;
map < string , int > ZX ;

void input ( ) {
    cin >> n ;
    ZX.clear ( ) ;
}

void solve ( ) {
    int i ;
    string x ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> x ;
        if ( ZX.find ( x ) != ZX.end ( ) ) {
            cout << "YES\n" ;
        }
        else {
            cout << "NO\n" ;
        }
        ZX[ x ] = 1 ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}