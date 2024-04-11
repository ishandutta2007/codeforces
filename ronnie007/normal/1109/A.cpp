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

int n ;
int a[ MAXN ] ;
int cnt[ 2 ][ 4 * MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    cnt[ 0 ][ 0 ] = 1 ;
    int aux = 0 ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux ^= a[ i ] ;
        ans += cnt[ ( i & 1 ) ][ aux ] ;
        ++ cnt[ ( i & 1 ) ][ aux ] ;
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