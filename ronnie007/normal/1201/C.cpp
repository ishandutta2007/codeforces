#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 200007

int n , k ;
long long a[ MAXN ] ;

bool f ( long long sr ) {
    long long sm = 0 ;
    for ( int i = ( n >> 1 ) ; i < n ; ++ i ) {
        sm += ( a[ i ] < sr ) ? sr - a[ i ] : 0 ;
    }
    return ( sm <= k ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
    sort ( a , a + n ) ;
}

void solve ( ) {
    long long l , r , mid ;
    l = a[ ( n >> 1 ) ] ;
    r = a[ n - 1 ] + k ;
    while ( r - l > 3 ) {
        mid = ( ( l + r ) >> 1 ) ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid - 1 ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    printf ( "%d\n" , r ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}