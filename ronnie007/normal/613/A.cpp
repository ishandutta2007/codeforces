#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define PI acos ( -1 ) 
#define eps 0.00000001

int n ;
pair < double , double > ori ;
pair < double , double > a[ MAXN ] ;

double dist ( pair < double , double > p1 , pair < double , double > p2 ) {
    return ( p1.first - p2.first ) * ( p1.first - p2.first ) + ( p1.second - p2.second ) * ( p1.second - p2.second ) ;
}

double det ( pair < double , double > p1 , pair < double , double > p2 , pair < double , double > p3 ) {
    double ret = p1.first * p2.second + p1.second * p3.first + p2.first * p3.second ;
    ret -= p3.first * p2.second + p3.second * p1.first + p2.first * p1.second ;
    return ret ;
}

int dot ( pair < double , double > p1 , pair < double , double > p2 , pair < double , double > p3 ) {
    double aux = ( p1.first - p2.first ) * ( p3.first - p2.first ) + ( p1.second - p2.second ) * ( p3.second - p2.second ) ;
    if ( aux < -eps ) { return -1 ; }
    if ( aux > eps ) { return 1 ; }
    return 0 ;
}

void input ( ) {
    scanf ( "%d%lf%lf" , &n , &ori.first , &ori.second ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lf%lf" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    double mn , mx ;
    mn = mx = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        double sr = dist ( a[ i ] , ori ) ;
        if ( i == 1 ) {
            mn = mx = sr ;
        }
        mn = min ( mn , sr ) ;
        mx = max ( mx , sr ) ;
        int nxt = i + 1 ;
        if ( i == n ) { nxt = 1 ; }
        if ( dot ( ori , a[ i ] , a[ nxt ] ) < 0 ) { continue ; }
        if ( dot ( ori , a[ nxt ] , a[ i ] ) < 0 ) { continue ; }
        
        double aux = det ( a[ i ] , a[ nxt ] , ori ) ;
        if ( aux < 0 ) { aux = -aux ; }
        aux /= sqrt ( dist ( a[ i ] , a[ nxt ] ) ) ;
        aux = ( aux * aux ) ;
        mn = min ( mn , aux ) ;
    }
    printf ( "%.12lf\n" , PI * ( mx - mn ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}