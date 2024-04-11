#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<stack>
using namespace std ;

#define MAXN 1000007
#define MOD 1000000007

int n , k ;
int a[ MAXN ] ;

int l[ MAXN ] ;
int r[ MAXN ] ;

long long f[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    stack < int > s ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        while ( s.empty ( ) == false && a[ s.top ( ) ] < a[ i ] ) {
            s.pop ( ) ;
        }
        if ( s.empty ( ) == true ) { l[ i ] = 0 ; }
        else { l[ i ] = s.top ( ) ; }
        s.push ( i ) ;
    }
    while ( s.empty ( ) == false ) { s.pop ( ) ; }
    for ( i = n ; i >= 1 ; i -- ) {
        while ( s.empty ( ) == false && a[ s.top ( ) ] <= a[ i ] ) {
            s.pop ( ) ;
        }
        if ( s.empty ( ) == true ) { r[ i ] = ( n + 1 ) ; }
        else { r[ i ] = s.top ( ) ; }
        s.push ( i ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i < k ) { f[ i ] = 0 ; continue ; }
        f[ i ] = ( i - k + 1 ) ;
        long long val = ( i - k ) / ( k - 1 ) ;
        long long aux = ( ( val * ( i - k + 1 ) ) % MOD ) - ( ( ( val * ( val + 1 ) / 2 ) * ( k - 1 ) ) % MOD ) ;
        if ( aux < 0 ) { aux += MOD ; }
        f[ i ] = ( f[ i ] + aux ) % MOD ;
    }
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x = i - l[ i ] - 1 ;
        int y = r[ i ] - i - 1 ;
        long long cur = ( f[ x + y + 1 ] - ( ( f[ x ] + f[ y ] ) % MOD ) + MOD ) % MOD ;
        ans += ( cur * a[ i ] ) % MOD ;
        ans %= MOD ;
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