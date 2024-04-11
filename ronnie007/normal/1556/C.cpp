#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int l = 1 ; l <= n ; l += 2 ) {
        long long sm = 0 , mn = 0 ;
        for ( int r = l + 1 ; r <= n ; r += 2 ) {
            long long hh1 = max ( a[ l ] - (-mn) + 1 , 0LL ) ;
            long long hh2 = max ( a[ r ] - (sm-mn) + 1 , 0LL ) ;
            if ( l + 1 == r ) {
                ans -- ;
            }
            ans += min ( hh1 , hh2 ) ;

            sm -= a[ r ] ;
            mn = min ( mn , sm ) ;
            sm += a[ r + 1 ] ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}