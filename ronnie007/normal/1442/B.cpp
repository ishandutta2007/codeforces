#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int pos[ MAXN ] ;
bool used[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        used[ b[ i ] ] = true ;
    }
}

void solve ( ) {
    long long ans = 1 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int coef = 0 ;
        int where = pos[ b[ i ] ] ;
        if ( where > 1 && used[ a[ where - 1 ] ] == false ) { ++ coef ; }
        if ( where < n && used[ a[ where + 1 ] ] == false ) { ++ coef ; }
        ans = ( ans * coef ) % MOD ;
        used[ b[ i ] ] = false ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}