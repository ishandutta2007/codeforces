#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

map < int , int > w ;

void input ( ) {
    scanf ( "%d%*d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d%*d" , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    int ans = 2 ;
    for ( int i = 0 ; i < 30 ; ++ i ) {
        int len = (1<<i) ;
        w.clear ( ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            int val = ( a[ i ] % ( 2 * len ) ) ;
            ++ w[ val ] ;
            if ( ans < w[ val ] ) { ans = w[ val ] ; }
        }
        for ( int i = 1 ; i <= m ; ++ i ) {
            int val = ( ( b[ i ] + len ) % ( 2 * len ) ) ;
            ++ w[ val ] ;
            if ( ans < w[ val ] ) { ans = w[ val ] ; }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}