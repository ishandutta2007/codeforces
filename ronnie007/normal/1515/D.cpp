#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n ;
int l , r ;
int a[ MAXN ] ;
int cnt1[ MAXN ] ;
int cnt2[ MAXN ] ;

void input ( ) {
    cin >> n >> l >> r ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt1[ i ] = cnt2[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= l ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt1[ a[ i ] ] ;
    }
    for ( int i = l + 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt2[ a[ i ] ] ;
    }
}


void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        int hh = min ( cnt1[ i ] , cnt2[ i ] ) ;
        l -= hh ; r -= hh ; 
        cnt1[ i ] -= hh ;
        cnt2[ i ] -= hh ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( l > r && cnt1[ i ] >= 2 ) {
            l -= 2 ; cnt1[ i ] -= 2 ;
            ++ ans ;
        }
        while ( r > l && cnt2[ i ] >= 2 ) {
            r -= 2 ; cnt2[ i ] -= 2 ;
            ++ ans ;
        }
    }
    ans += abs ( ( l - r ) / 2 ) ;
    ans += ( l + r ) / 2 ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}