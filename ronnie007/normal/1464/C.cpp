#include<bits/stdc++.h>
using namespace std ;

int n ;
long long sr ;
string a ;
int cnt[ 27 ] ;

void input ( ) {
    cin >> n >> sr ;
    cin >> a ;
    sr -= ( 1 << ( a[ n - 1 ] -'a' ) ) ;
    sr += ( 1 << ( a[ n - 2 ] - 'a' ) ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < n - 2 ; ++ i ) {
        ++ cnt[ ( a[ i ] - 'a' ) ] ;
    }
    for ( int i = 25 ; i >= 0 ; -- i ) {
        int add = ( 1 << i ) ;
        while ( cnt[ i ] -- ) {
            if ( sr < 0 ) { sr += add ; }
            else { sr -= add ; }
        }
    }
    if ( sr == 0 ) { cout << "Yes\n" ; }
    else { cout << "No\n" ; }
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