#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}


void solve ( ) {
    int mn , mx ;
    mn = mx = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] < a[ mn ] ) { mn = i ; }
        if ( a[ i ] > a[ mx ] ) { mx = i ; } 
    }
    cout << mn << " " << mx << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}