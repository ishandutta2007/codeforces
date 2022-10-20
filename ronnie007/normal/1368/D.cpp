#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MXBIT 21
int n ;
int a[ MAXN ] ;
int cnt[ MXBIT + 1 ] ;

long long h[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        for ( int j = 0 ; j < MXBIT ; ++ j ) {
            if ( ( a[ i ] & (1<<j) ) > 0 ) {
                ++ cnt[ j ] ;
            }
        }
    }
}

void solve ( ) {
    for ( int i = MXBIT - 1 ; i >= 0 ; -- i ) {
        for ( int j = 1 ; j <= cnt[ i ] ; ++ j ) {
            h[ j ] += (1<<i) ;
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += h[ i ] * h[ i ] ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}