#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
long long mx ;
long long c1 , c2 ;
long long br ;

long long a[ MAXN ] ;
pair < long long , int > b[ MAXN ] ;
long long c[ MAXN ] ;

long long f ( int x ) {
    if ( x > n ) { return -1 ; }
    int i ;
    long long tot = 0 ;
    c[ n + 1 ] = mx ;
    for ( i = 1 ; i <= n ; i ++ ) {
        c[ i ] = b[ i ].first ;
    }
    for ( i = 0 ; i < x ; i ++ ) {
        tot += ( mx - c[ n - i ] ) ;
        c[ n - i ] = mx ;
    }
    if ( tot > br ) { return -1 ; }
    long long lft = br - tot ;
    int cur = 1 ;
    long long k = c[ 1 ] ;
    for ( i = 2 ; i <= n + 1 ; i ++ ) {
        long long p = lft / cur ;
        if ( p > ( c[ i ] - c[ i - 1 ] ) ) { p = c[ i ] - c[ i - 1 ] ; }
        k += p ;
        lft -= p * cur ;
        cur ++ ;
    }
    return ( c1 * x + c2 * k ) ;
}

void get ( int x ) {
    int i , j ;
    long long tot = 0 ;
    c[ n + 1 ] = mx ;
    for ( i = 1 ; i <= n ; i ++ ) {
        c[ i ] = b[ i ].first ;
    }
    for ( i = 0 ; i < x ; i ++ ) {
        tot += ( mx - c[ n - i ] ) ;
        c[ n - i ] = mx ;
    }

    long long lft = br - tot ;
    int cur = 1 ;
    long long k = c[ 1 ] ;
    for ( i = 2 ; i <= n + 1 ; i ++ ) {
        long long p = lft / cur ;
        if ( p > ( c[ i ] - c[ i - 1 ] ) ) { p = c[ i ] - c[ i - 1 ] ; }
        k += p ;
        if ( p != c[ i ] - c[ i - 1 ] ) { break ; }
        lft -= p * cur ;
        cur ++ ;
    }
    for ( j = 1 ; j < i ; j ++ ) {
        a[ b[ j ].second ] = k ;
    }
    for ( j = i ; j <= n - x ; j ++ ) {
        a[ b[ j ].second ] = b[ j ].first ;
    }
    for ( j = 0 ; j < x ; j ++ ) {
        a[ b[ n - j ].second ] = mx ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        cout << a[ i ] ;
        if ( i == n ) { cout << "\n" ; }
        else { cout << " " ; }
    }
}

void input ( ) {
    cin >> n >> mx >> c1 >> c2 >> br ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
        b[ i ].first = a[ i ] ;
        b[ i ].second = i ;
    }
    sort ( b + 1 , b + n + 1 ) ;
}

void solve ( ) {
    int l = 0 ;
    int r = n ;
    int mid ;
    if ( r - l >= 10000 ) {
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            long long h1 = f ( mid ) ;
            long long h2 = f ( mid + 1 ) ;
            if ( h1 >= h2 ) { r = mid ; }
            else { l = mid ; }
        }
    }

    int i ;
    long long mx = f ( l ) ;
    int id = l ;
    for ( i = l + 1 ; i <= r ; i ++ ) {
        long long u = f ( i ) ;
        if ( u > mx ) { mx = u ; id = i ; }
    }
    cout << mx << "\n" ;
    get ( id ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}