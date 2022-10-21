#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , p ;
pair < int , int > a[ MAXN ] ;

bool f ( double sr ) {
    double aux = 0.0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( sr * a[ i ].first <= a[ i ].second ) { continue ; }
        aux += ( sr * a[ i ].first - a[ i ].second ) ;
    }
    return ( sr * p > aux ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &p ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    long long sr = p ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sr -= a[ i ].first ;
        if ( sr < 0 ) { break ; }
    }
    if ( sr >= 0 ) {
        printf ( "-1\n" ) ;
        return ;
    }
    double l = 0.00 ;
    double r = 0.00 ;
    double mid ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        r += a[ i ].second ;
    }
    for ( int i = 0 ; i <= 60 ; ++ i ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    printf ( "%.16lf\n" , ( l + r ) / 2 ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}