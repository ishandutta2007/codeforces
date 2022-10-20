#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;

long long proc ( int i ) {
    if ( ( a[ i ] % n ) == 0 ) { return 0 ; }
    long long rem = 0 ;
    if ( a[ i ] >= 0 ) { rem = ( a[ i ] % n ) ; }
    else {
        long long aux = a[ i ] / n ;
        rem = n - ( aux * n - a[ i ] ) ;
    }
    long long hh = rem * n - rem ;
    a[ i ] += hh ;
    return hh ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "1 1\n" ;
        cout << - a[ 1 ] << "\n" ;

        cout << "1 1\n" ;
        cout << "0\n" ;

        cout << "1 1\n" ;
        cout << "0\n" ;
        return ;
    }
    cout << "1 " << n - 1 << "\n" ;
    for ( int i = 1 ; i < n ; ++ i ) {
        cout << proc ( i ) << " " ;
    }
    cout << "\n" ;
    
    cout << "2 " << n << "\n" ;
    for ( int i = 2 ; i < n ; ++ i ) {
        cout << "0 " ;
    }
    cout << proc ( n ) ;
    cout << "\n" ;
    
    cout << "1 " << n << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << 0LL - a[ i ] << " " ;
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