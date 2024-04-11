#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ MAXN ] ;
long long total_cnt ;
vector < long long > v ;


long long calc ( long long k ) {
    long long curr = 0 ;
    long long ret = 0 ;
    long long id = ( k >> 1 ) + ( k & 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long h = ( a[ i ] % k ) ;
        ret += min ( curr , k - curr ) ;
        curr += h ;
        if ( curr >= k ) { curr -= k ; }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) , total_cnt += a[ i ] ;
    }
    long long h = 2 ;
    while (  h * h <= total_cnt ) {
        if ( ( total_cnt % h ) == 0 ) {
            v.push_back ( h ) ;
            while ( ( total_cnt % h ) == 0 ) {
                total_cnt /= h ;
            }
        }
        ++ h ;
    }
    if ( total_cnt > 1 ) { v.push_back ( total_cnt ) ; }
}

void solve ( ) {
    long long ans = -1 ;
    for ( auto x : v ) {
        long long ret = calc ( x ) ;
        if ( ans < 0 ) { ans = ret ; }
        ans = min ( ans , ret ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}