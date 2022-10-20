#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    while ( n -- ) {
        long long x ;
        cin >> x ;
        if ( x < 15 ) { cout << "NO\n" ; continue ; }
        x %= 14 ;
        cout << ( ( x <= 6 && x > 0 ) ? "YES" : "NO" ) << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}