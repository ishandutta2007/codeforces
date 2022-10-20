#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;

int st[ MAXN ] , en[ MAXN ] ;
int cnt[ MAXN ] ;

int dp[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        en[ a[ i ] ] = i ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        st[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    dp[ 0 ] = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int val = a[ i + 1 ] ;
        if ( i + 1 == st[ val ] ) {
            dp[ en[ val ] ] = max ( dp[ en[ val ] ] , dp[ i ] + cnt[ val ] ) ;
        }
        dp[ i + 1 ] = max ( dp[ i + 1 ] , dp[ i ] ) ;
    }
    int ans , mx ;
    ans = mx = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) { -- cnt[ a[ i ] ] ; }

    for ( int i = n ; i >= 1 ; -- i ) {
        ans = max ( ans , dp[ i ] + mx ) ;
        ++ cnt[ a[ i ] ] ;
        mx = max ( mx , cnt[ a[ i ] ] ) ;
    }
    cout << n - ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}