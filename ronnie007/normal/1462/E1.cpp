#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 200007

int n , m , k ;
int cnt[ MAXN ] ;

long long comb ( int x , int y ) {
    long long ret = x ;
    ret *= ( x - 1 ) ;
    ret *= ( x - 2 ) ;
    ret /= 6 ;
    return ret ;
}

void input ( ) {
    cin >> n ; 
    m = 3 ; k = 2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ; 
        cin >> x ;
        ++ cnt[ x ] ;
    }
}

void solve ( ) {
    int aux = 0 ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux += cnt[ i ] ;
        if ( i > k + 1 ) {
            aux -= cnt[ i - k - 1 ] ;
        }

        ans += comb ( aux , m ) ;
        // ans -= comb ( aux - cnt[ i ] , m ) ;
        ans = ( ans - comb ( aux - cnt[ i ] , m ) ) ;
    }
    cout << ans << "\n" ;
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