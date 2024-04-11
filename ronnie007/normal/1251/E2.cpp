#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;

int n ;
vector < int > v[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 , x , y ; i <= n ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
    }
    ll ans = 0 ;
    priority_queue < int > q ;
    int lft = n , aux = 0 ; 
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        for ( auto x : v[ i ] ) {
            q.push ( -x ) ;
            -- lft ;
        }
        while ( aux + lft < i ) {
            ans -= q.top ( ) ;
            q.pop ( ) ;
            ++ aux ;
        }
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