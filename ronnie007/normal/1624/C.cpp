#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n ;
int a[ MAXN ] ;

int cnt[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        while ( a[ i ] > n ) {
            a[ i ] /= 2 ;
        }
        ++ cnt[ a[ i ] ] ;
    }
}

void solve ( ) {
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( cnt[ i ] == 0 ) {
            cout << "NO\n" ;
            return ;
        }
        int lft = cnt[ i ] - 1 ;
        cnt[ i ] = 1 ;
        cnt[ ( i / 2 ) ] += lft ;
    }
    cout << "YES\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}