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

#define MAXN 1007
#define MOD 998244353

int n , k ;
int a[ MAXN ] ;

long long ans = 0 ;

long long dp[ 2 ][ MAXN ] ;
long long pref[ MAXN ] ;

long long prv_ans ;

long long calc ( int sr ) {
    int curr = 0 , prv = 1 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        dp[ prv ][ i ] = 1 ;
    }
    for ( int j = 2 ; j <= k ; ++ j ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            pref[ i ] = pref[ i - 1 ] + dp[ prv ][ i ] ;
            pref[ i ] = ( pref[ i ] >= MOD ) ? pref[ i ] - MOD : pref[ i ] ;
        }
        int init = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            while ( init < n && a[ i ] - sr >= a[ init + 1 ] ) { ++ init ; }
            dp[ curr ][ i ] = pref[ init ] ;
        }
        prv ^= 1 ; curr ^= 1 ;
    }
    long long sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sm = ( sm + dp[ prv ][ i ] ) ;
        sm = ( sm >= MOD ) ? sm - MOD : sm ;
    }
    long long ret = ( sm - prv_ans ) ;
    ret = ( ret >= 0 ) ? ret : ret + MOD ;
    prv_ans = sm ;
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int mxval = ( a[ n ] - a[ 1 ] + k - 2 ) / ( k - 1 ) ;
    for ( int i = mxval ; i >= 1 ; -- i ) {
        ans = ( ans + ( calc ( i ) * i ) % MOD ) ;
        ans = ( ans >= MOD ) ? ans - MOD : ans ;
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