#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int a , b , c , d ;

void input ( ) {
    cin >> a >> b >> c >> d ;
}

void solve ( ) {
    while ( b <= 5000000 || d <= 5000000 ) {
        if ( b == d ) {
            cout << b << "\n" ;
            return ;
        }
        if ( b < d ) {
            b += a ;
        }
        else {
            d += c ;
        }
    }
    cout << "-1\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}