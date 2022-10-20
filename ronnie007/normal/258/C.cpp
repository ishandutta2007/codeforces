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

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int get ( int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ] <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( a[ r ] > sr ) { r -- ; }
    return r ;
}

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

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i < MAXN ; i ++ ) {
        for ( j = i ; j < MAXN ; j += i ) {
            v[ j ].push_back ( i ) ;
        }
    }
    long long ans = 0 ;
    for ( i = 1 ; i <= a[ n ] ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        long long cur = 1 ;
        long long aux = 1 ;
        int id = 0 ;
        for ( j = 0 ; j < sz - 1 ; j ++ ) {
            int lst = v[ i ][ j ] - 1 ;
            int st = get ( lst ) ;
            int en = get ( v[ i ][ j + 1 ] - 1 ) ;
            id = en ;
            long long nw = fastpow ( j + 1 , ( en - st ) ) ;
            cur = ( cur * nw ) % MOD ;
            aux = ( aux * nw ) % MOD ;
        }
        long long u1 = fastpow ( sz , ( n - id ) ) ;
        long long u2 = fastpow ( sz - 1 , ( n - id ) ) ;
        cur = ( cur * u1 ) % MOD ;
        aux = ( aux * u2 ) % MOD ;
        ans = ( ans + cur - aux + MOD ) % MOD ;
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