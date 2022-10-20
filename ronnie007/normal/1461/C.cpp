#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
int a[ MAXN ] ;

int mx ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    mx = n ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] == i ) { mx = i - 1 ; }
        else { break ; }
    }
    double ans = 1.0 ;
    if ( mx == 0 ) { ans = 0.0 ; }
    while ( m -- ) {
        int x ;
        double coef ;
        cin >> x >> coef ;
        if ( x >= mx ) {
            ans = ( ans * ( 1.0 - coef ) ) ;
        }
    }
    cout << fixed ;
    cout << setprecision ( 11 ) << 1.0 - ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}