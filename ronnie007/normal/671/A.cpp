#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

typedef pair < long long , long long > type ;

type bin ;
type st1 , st2 ;


int n ;
type a[ MAXN ] ;

double pref[ MAXN ] ;
double suff[ MAXN ] ;

double dist ( type p1 , type p2 ) {
    double ret = ( p1.first - p2.first ) * ( p1.first - p2.first ) + ( p1.second - p2.second ) * ( p1.second - p2.second ) ;
    return ( sqrt ( ret ) ) ;
}


void input ( ) {
    cin >> st1.first >> st1.second ;
    cin >> st2.first >> st2.second ;
    cin >> bin.first >> bin.second ;
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
}

void solve ( ) {
    int i , j , t ;
    double ans = -1.000 ;
    double init = 0.000000 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        init += 2 * dist ( a[ i ] , bin ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        pref[ i ] = min ( pref[ i - 1 ] , dist ( st1 , a[ i ] ) - dist ( a[ i ] , bin ) ) ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        suff[ i ] = min ( suff[ i + 1 ] , dist ( st1 , a[ i ] ) - dist ( a[ i ] , bin ) ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        double cur = init ;
        cur += ( dist ( st2 , a[ i ] ) - dist ( a[ i ] , bin ) ) ;
        if ( ans < 0 ) { ans = cur ; }
        if ( ans > cur ) { ans = cur ; }
        cur += min ( pref[ i - 1 ] , suff[ i + 1 ] ) ;
        if ( ans < 0 ) { ans = cur ; }
        if ( ans > cur ) { ans = cur ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        double cur = init ;
        cur += ( dist ( st1 , a[ i ] ) - dist ( a[ i ] , bin ) ) ;
        if ( ans < 0 ) { ans = cur ; }
        if ( ans > cur ) { ans = cur ; }
    }
    printf ( "%.12lf\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}