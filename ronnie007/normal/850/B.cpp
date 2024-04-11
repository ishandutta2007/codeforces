#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 500007

int n ;
long long x , y ;

long long aux ;

int a[ MAXN ] ;

bool pr[ 4 * MAXN ] ;
long long br[ 4 * MAXN ] ;
long long sm[ 4 * MAXN ] ;

long long getsm ( int l , int r ) {
    return ( sm[ r ] - sm[ l - 1 ] ) ;
}

long long getbr ( int l , int r ) {
    return ( br[ r ] - br[ l - 1 ] ) ;
}

void input ( ) {
    cin >> n >> x >> y ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
        br[ a[ i ] ] ++ ;
        sm[ a[ i ] ] += a[ i ] ;
    }
    for ( i = 1 ; i <= 2000000 ; i ++ ) {
        br[ i ] += br[ i - 1 ] ;
        sm[ i ] += sm[ i - 1 ] ;
    }
    aux = ( x / y ) ;
}

void solve ( ) {
    int i , j ;
    long long ans = x * ( n - 1 ) ;
    long long cur = 0 ;
    if ( br[ 1 ] == n ) { ans += y ; }
    for ( i = 2 ; i <= 1000000 ; i ++ ) {
        if ( pr[ i ] == true ) { continue ; }
        cur = 0 ;
        for ( j = i ; j <= 2000000 ; j += i ) {
            pr[ j ] = true ;
            if ( cur > ans ) { continue ; }
            if ( br[ j ] == br[ j - i ] ) { continue ; }
            int l = ( ( j - i ) + 1 ) ;
            int r = j - 1 ;
            int mid = j - aux ;
            if ( mid < l ) { mid = l ; }
            if ( mid <= r ) {
                long long u1 = getsm ( mid , r ) ;
                long long u2 = getbr ( mid , r ) ;
                long long g = u1 - u2 * ( j - i ) ;
                g = u2 * i - g ;
                cur += g * y ;
            }
            mid -- ;
            if ( l <= mid ) {
                long long u1 = getbr ( l , mid ) ;
                cur += u1 * x ;
            }
        }
        if ( ans > cur ) { ans = cur ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}