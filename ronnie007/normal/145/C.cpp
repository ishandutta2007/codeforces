#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007
#define MOD 1000000007
#define lim 1000000000

int n , k ;
int a[ MAXN ] ;

vector < int > v ;

long long dp[ MAXN ] ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long fastpow ( long long val , long long x ) {
    long long ret = 1 ;
    while ( x != 0 ) {
        if ( ( x % 2 ) == 0 ) {
            val = ( val * val ) % MOD ;
            x /= 2 ;
        }
        else {
            ret = ( ret * val ) % MOD ;
            x -- ;
        }
    }
    return ret ;
}

void dfs ( long long x ) {
    if ( x > lim ) { return ; }
    v.push_back ( x ) ;
    dfs ( x * 10 + 4 ) ;
    dfs ( x * 10 + 7 ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    dfs ( 0 ) ;
    sort ( v.begin ( ) , v.end ( ) ) ;
    int sz = v.size ( ) ;
    int br = 0 ;
    int i , j ;
    j = 1 ;
    dp[ 0 ] = 1 ;
    int h = n ;
    fac[ 0 ] = inv[ 0 ] = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
        inv[ i ] = fastpow ( fac[ i ] , MOD - 2 ) ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        int cur = 0 ;
        while ( j <= n && a[ j ] <= v[ i ] ) {
            if ( a[ j ] == v[ i ] ) { cur ++ ; }
            j ++ ;
        }
        if ( cur == 0 ) { continue ; }
        h -= cur ;
        for ( j = k - 1 ; j >= 0 ; j -- ) {
            dp[ j + 1 ] += ( cur * dp[ j ] ) % MOD ;
            if ( dp[ j + 1 ] >= MOD ) { dp[ j + 1 ] -= MOD ; }
        }
    }
    long long ans = 0 ;
    for ( i = 0 ; i <= min ( h , k ) ; i ++ ) {
        long long cur = fac[ h ] ;
        cur = ( cur * inv[ i ] ) % MOD ;
        cur = ( cur * inv[ h - i ] ) % MOD ;
        cur = ( cur * dp[ k - i ] ) % MOD ;
        ans += cur ;
        if ( ans >= MOD ) { ans -= MOD ; }
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