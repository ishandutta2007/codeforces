#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int n , m ;
string a ;

void solve ( ) {
    cin >> n >> m ;
    cin >> a ;
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cnt += ( a[ i ] - '0' ) ;
    }
    ll aux = 1LL * cnt * m ;
    if ( aux % n != 0 ) {
        cout << "-1\n" ;
        return ;
    }
    int targ = aux / n , sm = 0 ;
    int st = -1 ;
    for ( int i = 0 ; i < m ; ++ i ) {
        sm += ( a[ i ] - '0' ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( sm == targ ) {
            st = i ;
            break ;
        }
        sm -= ( a[ i ] - '0' ) ;
        sm += ( a[ ( i + m ) % n ] -'0' ) ;
    }
    if ( st == -1 ) {
        cout << "-1\n" ;
        return ;
    }
    if ( st + m - 1 < n ) {
        cout << "1\n" ;
        cout << st + 1 << " " << st + m << "\n" ;
    }
    else {
        cout << "2\n" ;
        cout << "1 " << ( st + m - 1 ) % n + 1 << "\n" ;
        cout << st + 1 << " " << n << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}