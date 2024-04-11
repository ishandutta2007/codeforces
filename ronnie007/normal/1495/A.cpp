#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
vector < long long > x ;
vector < long long > y ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    x.clear ( ) ;
    y.clear ( ) ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        int p , q ;
        scanf ( "%d%d" , &p , &q ) ;
        if ( p == 0 ) { y.push_back ( abs ( q ) ) ; }
        else { x.push_back ( abs ( p ) ) ; }
    }
}

void solve ( ) {
    sort ( x.begin ( ) , x.end ( ) ) ;
    sort ( y.begin ( ) , y.end ( ) ) ;
    double ans = 0.0 ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        long long aux = x[ i ] * x[ i ] + y[ i ] * y[ i ] ;
        ans += sqrt ( aux ) ;
    }
    printf ( "%.15lf\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    // cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}