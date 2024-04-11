#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , p , k ;
string a ;
int x , y ;

long long suff[ MAXN ] ;

void input ( ) {
    cin >> n >> p >> k ;
    cin >> a ;
    a = '#' + a ;
    cin >> x >> y ;
}

void solve ( ) {
    for ( int i = n ; i >= 1 ; -- i ) {
        suff[ i ] = ( a[ i ] == '0' ) * x ;
        if ( i + k <= n ) { suff[ i ] += suff[ i + k ] ; }
    }
    long long ans = -1 ;
    for ( int i = 0 ; i <= n - p ; ++ i ) {
        long long h = 1LL * i * y + suff[ i + p ] ;
        if ( ans < 0 ) { ans = h ; }
        ans = min ( ans , h ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// scanf ( "%d" , &t ) ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}