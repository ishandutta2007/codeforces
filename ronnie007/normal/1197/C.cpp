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

#define MAXN 300007

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( i > 1 ) { b[ i - 1 ] = a[ i ] - a[ i - 1 ] ; }
    }
    sort ( b + 1 , b + n ) ;
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= ( n - k ) ; ++ i ) {
        ans += b[ i ] ;
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