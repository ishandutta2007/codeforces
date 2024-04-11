#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;
long long sm = 0 ;

void input ( ) {
    cin >> n ;
    sm = 0 ; 
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
}


void solve ( ) {
    long long lft = ( sm % n ) ;
    cout << lft * ( n - lft ) << "\n" ;
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