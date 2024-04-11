#include<bits/stdc++.h>
using namespace std ;

int x , y ;
long long ans = 0 ;

void input ( ) {
    cin >> x >> y ;
    ans = 0 ;
}

void solve ( ) {
    int lstbad = 1 ;
    for ( int k = 2 ; ( k - 1 ) * ( k + 1 ) <= x && k <= y ; ++ k ) {
        ans += k - 1 ;
        lstbad = k ;
    }
    while ( lstbad < y ) {
        int aux = lstbad + 1 ;
        if ( ( x / ( aux + 1 ) ) == ( x / ( y + 1 ) ) ) {
            ans += 1LL * ( ( x / ( aux + 1 ) ) ) * ( y - aux + 1 ) ;
            break ;
        }
        else {
            long long l , r , mid ;
            l = aux ;
            r = y ;
            while ( r - l > 3 ) {
                mid = ( l + r ) / 2 ;
                if ( ( x / ( aux + 1 ) ) == ( x / ( mid + 1 ) ) ) { l = mid ; }
                else { r = mid ; }
            }
            while ( ( x / ( r + 1 ) ) != ( x / ( aux + 1 ) ) ) { -- r ; }
            ans += 1LL * ( ( x / ( aux + 1 ) ) ) * ( r - aux + 1 ) ;
            lstbad = r ;
        }
    }
    cout << ans << "\n" ;
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