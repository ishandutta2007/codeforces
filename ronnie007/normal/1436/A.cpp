#include<bits/stdc++.h>
using namespace std ;
 
int n , m ;
long long sm ;
 
void input ( ) {
    sm = 0 ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        cin >> x ;
        sm += x ;
    }
}
 
void solve ( ) {
    if ( sm == m ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
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