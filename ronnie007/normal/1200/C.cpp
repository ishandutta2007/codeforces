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

long long n , m , q ;


long long w ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

long long find ( long long x , long long y ) {
    return ( ( x - 1 ) / y + 1 ) ;
}

void input ( ) {
    cin >> n >> m >> q ;
}

void solve ( ) {
    long long aux = w ( n , m ) ;
    long long x = ( n / aux ) , y = ( m / aux ) ;
    while ( q -- ) {
        long long a , b , c , d ;
        cin >> a >> b >> c >> d ;
        long long comp1 , comp2 ;
        comp1 = comp2 = 0 ;
        if ( a == 1 ) {
            comp1 = find ( b , x ) ;
        }
        else {
            comp1 = find ( b , y ) ;
        }
        if ( c == 1 ) {
            comp2 = find ( d , x ) ;
        }
        else {
            comp2 = find ( d , y ) ;
        }
        if ( comp1 == comp2 ) { cout << "YES\n" ; }
        else { cout << "NO\n" ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}