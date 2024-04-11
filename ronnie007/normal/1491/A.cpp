#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , q ;
int a[ MAXN ] ;
int cnt ;

void input ( ) {
    cin >> n >> q ;
    cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( a[ i ] == 1 ) { ++ cnt ; } 
    }
}

void solve ( ) {
    while ( q -- ) {
        int type , x ;
        cin >> type >> x ;
        if ( type == 1 ) {
            if ( a[ x ] == 1 ) { -- cnt ; }
            else { ++ cnt ; }
            a[ x ] ^= 1 ;
        }
        else {
            if ( cnt >= x ) { cout << "1\n" ; }
            else { cout << "0\n" ; }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}