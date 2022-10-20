#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 500007

int n ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;
int tr[ MAXN ] ;

void upd ( int id , int x ) {
    for ( int i = id ; i <= n ; i += ( i & ( -i ) ) ) {
        tr[ i ] += x ;
    }
}
int get ( int id ) {
    int ans = 0 ;
    for ( int i = id ; i >= 1 ; i -= ( i & ( -i ) ) ) {
        ans += tr[ i ] ;
    }
    return ans ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = tr[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ; 
    }
}   

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] >= 2 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    int hh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        hh = ( hh + ( i - 1 - get ( a[ i ] ) ) ) % 2 ;
        upd ( a[ i ] , 1 ) ;
    }
    if ( ( hh % 2 ) == 0 ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}