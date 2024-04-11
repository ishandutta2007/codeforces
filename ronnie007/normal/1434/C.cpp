#include<bits/stdc++.h>
using namespace std ;

long long dmg , heal , coef , d ;

long long f ( long long cnt ) {
    long long sm = dmg * cnt ;
    long long mx = coef / d ;
    if ( mx > cnt - 1 ) { mx = cnt - 1 ; }
    sm -= ( mx * ( mx + 1 ) / 2 ) * d * heal ;
    sm -= ( cnt - 1 - mx ) * coef * heal ;
    return sm ;
}

void input ( ) {
    cin >> dmg >> heal >> coef >> d ;
}

void solve ( ) {
    if ( dmg > heal * coef ) {
        cout << "-1\n" ;
        return ;
    }
    long long l , r , mid ;
    l = 1 ;
    r = 1e6 + 15 ;
    while ( r - l > 3 ) {
        long long mid1 = ( l * 2 + r ) / 3 ;
        long long mid2 = ( l + r * 2 ) / 3 ;
        if ( f ( mid1 ) < f ( mid2 ) ) { l = mid1 ; }
        else { r = mid2 ; }
    }
    long long ans = f ( l ) ;
    for ( long long i = l + 1 ; i <= r ; ++ i ) {
        ans = max ( ans , f ( i ) ) ;
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