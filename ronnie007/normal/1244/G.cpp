#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1e6 + 7 ;
int n ;
ll k ;

int ans[ MAXN ] ;

void solve ( ) {
    cin >> n >> k ;
    ll mn = 1LL * n * ( n + 1 ) / 2 ;
    if ( k < mn ) {
        cout << "-1\n" ;
        return ;
    }
    ll mx = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx += max ( i , n - i + 1 ) ;
    }
    if ( k > mx ) { k = mx ; }
    ll diff = k - mn ;
    int init = 0 , aft = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        int sub = ( i - init - 1 ) ;
        if ( diff >= sub ) { diff -= sub ; ++ init ; }
        else {
            aft = i - 1 ;
            while ( diff > 0 ) {
                if ( init + aft < i ) { -- diff ; }
                -- aft ;                
            }
            break ;
        }
    }
    cout << k << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << i << " " ;
    }
    cout << "\n" ;
    for ( int i = 0 ; i < init ; ++ i ) {
        cout << n - i << " " ;
    }
    for ( int i = 1 ; i <= aft ; ++ i ) {
        cout << i << " " ;
    }
    if ( init < n ) {
        cout << n - init << " " ;
    }
    for ( int i = aft + 1 ; i < n - init ; ++ i ) {
        cout << i << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}