#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 300007

int n , p , k ;
long long a[ MAXN ] ;

long long ans = 0 ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &p , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    map < int , int > ZX ;
    auto sq = [ ] ( long long x ) {
        return ( x * x ) % p ;
    } ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long aux = ( sq ( sq ( a[ i ] ) ) - ( a[ i ] * k ) % p + p ) % p ;
        ans += ZX[ aux ] ++ ;
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