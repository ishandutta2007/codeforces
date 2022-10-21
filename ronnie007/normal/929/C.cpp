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

#define MAXN 1007

int n , m , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int c[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
        scanf ( "%d" , &c[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    sort ( b + 1 , b + m + 1 ) ;
    sort ( c + 1 , c + k + 1 ) ;
}

void solve ( ) {
    int i , j ;
    long long ans = 0 ;
    // min --> A
    for ( i = 1 ; i <= n ; i ++ ) {
        int br2 , br3 ;
        br2 = br3 = 0 ;
        for ( j = 1 ; j <= m ; j ++ ) {
            if ( b[ j ] >= a[ i ] && b[ j ] <= 2 * a[ i ] ) { br2 ++ ; }
        }
        for ( j = 1 ; j <= k ; j ++ ) {
            if ( c[ j ] >= a[ i ] && c[ j ] <= 2 * a[ i ] ) { br3 ++ ; }
        }
        long long cur = 1 ;
        cur *= br2 ;
        cur *= ( br2 - 1 ) ;
        cur /= 2 ;
        cur *= br3 ;
        cur *= ( br3 - 1 ) ;
        cur *= ( br3 - 2 ) ;
        cur /= 6 ;
        ans += cur ;
    }
    // min --> B
    for ( i = 1 ; i <= m ; i ++ ) {
        int br1 , br2 , br3 ;
        br1 = br2 = br3 = 0 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( a[ j ] >= b[ i ] && a[ j ] <= 2 * b[ i ] ) { br1 ++ ; }
        }
        for ( j = i + 1 ; j <= m ; j ++ ) {
            if ( b[ j ] >= b[ i ] && b[ j ] <= 2 * b[ i ] ) { br2 ++ ; }
        }
        for ( j = 1 ; j <= k ; j ++ ) {
            if ( c[ j ] >= b[ i ] && c[ j ] <= 2 * b[ i ] ) { br3 ++ ; }
        }
        long long cur = 1 ;
        cur *= br1 ;
        cur *= br2 ;
        cur *= br3 ;
        cur *= ( br3 - 1 ) ;
        cur *= ( br3 - 2 ) ;
        cur /= 6 ;
        ans += cur ;
    }
    // min --> C
    for ( i = 1 ; i <= k ; i ++ ) {
        int br1 , br2 , br3 ;
        br1 = br2 = br3 = 0 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( a[ j ] >= c[ i ] && a[ j ] <= 2 * c[ i ] ) { br1 ++ ; }
        }
        for ( j = 1 ; j <= m ; j ++ ) {
            if ( b[ j ] >= c[ i ] && b[ j ] <= 2 * c[ i ] ) { br2 ++ ; }
        }
        for ( j = i + 1 ; j <= k ; j ++ ) {
            if ( c[ j ] >= c[ i ] && c[ j ] <= 2 * c[ i ] ) { br3 ++ ; }
        }
        long long cur = 1 ;
        cur *= br1 ;
        cur *= br2 ;
        cur *= ( br2 - 1 ) ;
        cur /= 2 ;
        cur *= br3 ;
        cur *= ( br3 - 1 ) ;
        cur /= 2 ;
        ans += cur ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}