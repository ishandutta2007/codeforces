#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;


long long n , k ;

bool ask ( long long l , long long r ) {
    cout << l << " " << r << "\n" ;
    fflush ( stdout ) ;
    string ret ;
    cin >> ret ;
    return ( ret == "Yes" ) ;
}

void normalize ( long long &l , long long &r ) {
    while ( r - l > 30 ) {
        l = max ( 1LL , l - k ) ;
        r = min ( n , r + k ) ;
        long long mid = ( l + r ) / 2 ;
        if ( ask ( l , mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
}

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    srand ( 420 ) ;
    long long l , r ;
    l = 1 ;
    r = n ;
    while ( 1 ) {
        normalize ( l , r ) ;
        l = max ( 1LL , l - k ) ;
        r = min ( n , r + k ) ;
        int x = ( r - l + 1 ) ;
        long long h = l + ( rand ( ) % x ) ;
        if ( ask ( h , h ) == true ) { break ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}