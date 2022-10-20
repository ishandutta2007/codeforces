#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;
long long sm ;

struct op {
    int x , y ;
    long long z ;
    op ( ) { x = y = z = 0 ; }
    op ( int _x , int _y , long long _z ) {
        x = _x ; y = _y ;
        z = _z ;
    }
};
vector < op > v ;

void input ( ) {
    cin >> n ;
    sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
}

void solve ( ) {
    if ( ( sm % n ) != 0 ) {
        cout << "-1\n" ;
        return ;
    }
    v.clear ( ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        long long lft = i - ( a[ i ] % i ) ;
        lft %= i ;
        v.push_back ( op ( 1 , i , lft ) ) ;
        long long coef = ( a[ i ] + lft ) / i ;
        v.push_back ( op ( i , 1 , coef ) ) ;
    }
    sm /= n ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        v.push_back ( op ( 1 , i , sm ) ) ;
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ].x << " " << v[ i ].y << " " << v[ i ].z << "\n" ;
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