#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007

int n ;
pair < int , int > a[ MAXN ] ;

long double pw[ MAXN ] ;

long double coef[ 66 ] ;

long long det ( pair < int , int > p1 , pair < int , int > p2 , pair < int , int > p3 ) {
    long long ret = 1LL * p1.first * p2.second + 1LL * p1.second * p3.first + 1LL * p2.first * p3.second ;
    ret -= 1LL * p3.first * p2.second + 1LL * p3.second * p1.first + 1LL * p2.first * p1.second ;
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    pw[ 0 ] = 1.0 ;
    for ( int i = 1 ; i <= n ; ++ i ) { pw[ i ] = pw[ i - 1 ] * 2 ; }
}

void solve ( ) {
    long double ans = 0.0 ;
    pair < int , int > ori = { 0 , 0 } ;
    double tot = ( pw[ n ] - 1 - n - 1LL * n * ( n - 1 ) / 2 ) ;
    for ( int i = 1 ; i <= min ( n - 1 , 60 ) ; ++ i ) {
        if ( n > 70 ) { coef[ i ] = 1 / pw[ i + 1 ] ; }
        else {
            coef[ i ] = ( pw[ n - i - 1 ] - 1 ) / tot ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int add = 1 ; add <= min ( n - 1 , 60 ) ; ++ add ) {
            int j = i + add ;
            if ( j > n ) { j -= n ; }
            double aux = det ( ori , a[ i ] , a[ j ] ) ;
            int pts = __gcd ( abs ( a[ i ].first - a[ j ].first ) , abs ( a[ i ].second - a[ j ].second ) ) ;
            ans += coef[ add ] * ( aux / 2.0 - pts / 2.0 ) ;
        }
    }
    printf ( "%.16Lf\n" , ans + 1 ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}