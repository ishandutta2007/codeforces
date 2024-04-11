#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int q ;

void input ( ) {
    cin >> q ;
}

void solve ( ) {
    long long x , y , k ;
    while ( q != 0 ) {
        q -- ;
        cin >> x >> y >> k ;
        if ( x > k || y > k ) { cout << "-1\n" ; continue ; }
        long long a , b ;
        a = x + ( 2 * ( ( k - x ) / 2 ) ) ;
        b = y + ( 2 * ( ( k - y ) / 2 ) ) ;
        b = b - ( k - a ) ;
        if ( b < 0 ) { cout << "-1\n" ; continue ; }
        else if ( b > k ) { b = k ; }
        cout << b << "\n" ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}