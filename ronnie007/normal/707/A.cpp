#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n , m ;
bool fl ;

void input ( ) {
    cin >> n >> m ;
    int i ;
    fl = false ;
    for ( i = 0 ; i < n * m ; i ++ ) {
        char c ;
        cin >> c ;
        if ( c != 'W' && c != 'B' && c != 'G' ) { fl = true ; }
    }
}

void solve ( ) {
    if ( fl == false ) { printf ( "#Black&White\n" ) ; }
    else { printf ( "#Color\n" ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}