#include<bits/stdc++.h>
using namespace std ;

pair < int , int > dir[ 6 ] = {
    { 1 , 1 } , { 0 , 1 } , { -1 , 0 } , { -1 , -1 } , { 0 , -1 } , { 1 , 0 }
};
long long x , y ;
long long cost[ 6 ] ;
long long ans = -1 ;

long long calc ( int h1 , int h2 ) {
    if ( ( h1 + 3 ) % 6 == h2 ) { return -1 ; }
    long long p , q ;
    if ( dir[ h1 ].first != 0 && dir[ h1 ].second != 0 ) { swap ( h1 , h2 ) ; }
    if ( dir[ h1 ].first == 0 ) {
        q = x / dir[ h2 ].first ;
        p = ( y - q * dir[ h2 ].second ) / dir[ h1 ].second ;
    }
    else {
        q = y / dir[ h2 ].second ;
        p = ( x - q * dir[ h2 ].first ) / dir[ h1 ].first ;
    }
    if ( p < 0 || q < 0 ) { return -1 ; }
    return p * cost[ h1 ] + q * cost[ h2 ] ;
}

void input ( ) {
    cin >> x >> y ;
    for ( int i = 0 ; i < 6 ; ++ i ) {
        cin >> cost[ i ] ;
    }
}

void solve ( ) {
    int hh ;
    if ( x > 0 && y > 0 ) { hh = 0 ; }
    else if ( x == 0 && y > 0 ) { hh = 1 ; }
    else if ( x < 0 && y == 0 ) { hh = 2 ; }
    else if ( x < 0 && y < 0 ) { hh = 3 ; }
    else if ( x == 0 && y < 0 ) { hh = 4 ; }
    else { hh = 5 ; }
    ans = -1 ;
    if ( x == 0 || y == 0 ) {
        long long aux = cost[ hh ] * ( abs ( x ) + abs ( y ) ) ;
        if ( ans < 0 || ans > aux ) { ans = aux ; }
    }
    else {
        if ( x == y ) {
            long long aux = cost[ hh ] * abs ( x ) ;
            if ( ans < 0 || ans > aux ) { ans = aux ; }
        }
    }
    for ( int i = 0 ; i < 6 ; ++ i ) {
        for ( int j = 0 ; j < 6 ; ++ j ) {
            if ( i == j ) { continue ; }
            long long sr = calc ( i , j ) ;
            if ( sr < 0 ) { continue ; }
            if ( ans < 0 || ans > sr ) { ans = sr ; }
        }
    }
    cout << ans << "\n" ;
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