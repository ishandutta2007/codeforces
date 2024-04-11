#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007
int n ;
long long x[ MAXN ] ;
long long y[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> x[ i ] >> y[ i ] ;
    }
    sort ( x + 1 , x + n + 1 ) ;
    sort ( y + 1 , y + n + 1 ) ;
}

void solve ( ) {
    long long coef1 , coef2 ;
    int mid = ( n / 2 ) ;
    if ( ( n % 2 ) == 1 ) { cout << "1\n" ; return ; }
    coef1 = ( x[ mid + 1 ] - x[ mid ] + 1 ) ;
    coef2 = ( y[ mid + 1 ] - y[ mid ] + 1 ) ;
    cout << coef1 * coef2 << "\n" ;
}

int main ( ) {
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