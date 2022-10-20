#include<bits/stdc++.h>
using namespace std ;

long long k ;
int n ;
string a = "codeforces" ;
long long cnt[ 13 ] ;

void input ( ) {
    cin >> k ;
    n = a.size ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 1 ;
    }
}

void solve ( ) {
    long long aux = 1 ;
    while ( 1 ) {
        if ( aux >= k ) { break ; }
        for ( int i = 1 ; i <= n ; ++ i ) {
            aux /= cnt[ i ] ;
            ++ cnt[ i ] ;
            aux *= cnt[ i ] ;
            if ( aux >= k ) { break ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( cnt[ i ] > 0 ) {
            -- cnt[ i ] ;
            cout << a[ i - 1 ] ;
        }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}