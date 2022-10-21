#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;

pair < int , int > c[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        c[ i ].first = ( a[ i ] - b[ i ] ) ;
        c[ i ].second = i ;
    }
    sort ( c + 1 , c + n + 1 ) ;
}

void solve ( ) {
    int i ;
    long long ans = 0 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        ans += a[ c[ i ].second ] ;
    }
    for ( i = k + 1 ; i <= n ; i ++ ) {
        if ( c[ i ].first <= 0 ) { ans += a[ c[ i ].second ] ; }
        else { ans += b[ c[ i ].second ] ; }
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