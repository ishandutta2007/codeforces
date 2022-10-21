#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std ;

long long n , k , m ;
long long a[ 57 ] ;

long long tot = 0 ;

void input ( ) {
    cin >> n >> k >> m ;
    long long i ;
    for ( i = 1 ; i <= k ; i ++ ) {
        cin >> a[ i ] ;
        tot += a[ i ] ;
    }
    sort ( a + 1 , a + k + 1 ) ;
}

void solve ( ) {
    long long i , j ;
    long long ans = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        long long cur = i * ( k + 1 ) ;
        long long lft = m - i * tot ;
        if ( lft < 0 ) { continue ; }
        int h = ( n - i ) ;
        if ( h != 0 ) {
            for ( j = 1 ; j <= k ; j ++ ) {
                if ( h * a[ j ] <= lft ) {
                    lft -= h * a[ j ] ;
                    cur += h ;
                }
                else {
                    cur += lft / a[ j ] ;
                    break ;
                }
            }
        }
        if ( ans < cur ) { ans = cur ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}