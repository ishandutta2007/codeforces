#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MOD 1000000007
#define MAXN 1000007

int n , k ;

int used[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int i ;
    long long ans = 1 ;
    if ( k == 0 ) {
        for ( i = 2 ; i <= n ; i ++ ) {
            ans = ( ans * n ) % MOD ;
        }
    }
    else {
        for ( i = 0 ; i < n ; i ++ ) {
            if ( used[ i ] == 1 ) { continue ; }
            long long h = i ;
            int br = 0 ;
            long long aux = 1 ;
            while ( used[ h ] == 0 ) {
                br ++ ;
                used[ h ] = 1 ;
                h = ( h * k ) % n ;
                aux = ( aux * k ) % n ;
            }
            if ( aux == 1 ) { ans *= n ; ans %= MOD ; }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}