#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

long long a , b , x , y ;

void input ( ) {
    cin >> a >> b >> x >> y ;
}

void solve ( ) {
    long long g = __gcd ( x , y ) ;
    x /= g ;
    y /= g ;
    long long u = ( a / x ) ;
    long long w = ( b / y ) ;
    cout << min ( u , w ) << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}