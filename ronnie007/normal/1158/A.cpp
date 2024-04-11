#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    sort ( b + 1 , b + m + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    if ( a[ n ] > b[ 1 ] ) {
        printf ( "-1\n" ) ;
        return ;
    }
    if ( a[ n ] == b[ 1 ] ) {
        for ( int i = 1 ; i <= m ; ++ i ) {
            ans += b[ i ] ;
        }
        for ( int i = 1 ; i < n ; ++ i ) {
            ans += 1LL * a[ i ] * m ;
        }
    }
    else {
        for ( int i = 1 ; i <= m ; ++ i ) {
            ans += b[ i ] ;
        }
        ans += a[ n ] ;
        for ( int i = 1 ; i < n ; ++ i ) {
            ans += 1LL * a[ i ] * m ;
            if ( i == n - 1 ) {
                ans -= a[ i ] ;
            }
        }
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