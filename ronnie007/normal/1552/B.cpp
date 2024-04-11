#include<bits/stdc++.h>
using namespace std ;

#define MAXN 50007

int n ;
int a[ MAXN ][ 7 ] ;

bool f ( int x , int y ) {
    int cnt = 0 ;
    for ( int i = 0 ; i < 5 ; ++ i ) {
        if ( a[ x ][ i ] < a[ y ][ i ] ) { ++ cnt ; }
    }
    return ( cnt >= 3 ) ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 5 ; ++ j ) {
            cin >> a[ i ][ j ] ; 
        }
    }
}

void solve ( ) {
    int ans = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( f ( ans , i ) == true ) { continue ; }
        ans = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == ans ) { continue ; }
        if ( f ( ans , i ) == false ) {
            cout << "-1\n" ;
            return ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}