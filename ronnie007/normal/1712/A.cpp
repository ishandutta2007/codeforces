#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 107 ;

int n , k ;
int a[ MAXN ] ;

void solve ( ) {
    cin >> n >> k ;
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( a[ i ] <= k && i > k ) { ++ ans ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}