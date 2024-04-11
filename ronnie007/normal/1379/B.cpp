#include<bits/stdc++.h>
using namespace std ;

long long l , r , m ;

long long mn , mx ;

void input ( ) {
    cin >> l >> r >> m ;
}

void solve ( ) {
    mn = m + l - r ;
    mx = m + r - l ;
    for ( long long a = l ; a <= r ; ++ a ) {
        if ( ( mx / a ) - ( ( mn - 1 ) / a ) == 0 ) { continue ; }
        long long aux = ( mx / a ) ;
        aux *= a ;
        long long coef1 , coef2 ;
        coef1 = l ;
        coef2 = r ;
        while ( mx > aux ) {
            if ( coef2 > l ) { -- coef2 ; }
            else { ++ coef1 ; }
            -- mx ;
        }
        cout << a << " " << coef1 << " " << coef2 << "\n" ;
        return ;
    }
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