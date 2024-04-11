#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int nxt[ MAXN ] ;
bool f[ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( i == n ) { nxt[ i ] = 1 ; }
        else { nxt[ i ] = i + 1 ; }
        f[ i ] = false ;
    }
}

void solve ( ) {
    queue < int > q ;
    vector < int > ans ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        q.push ( i ) ;
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        if ( f[ x ] == true ) { continue ; }
        if ( __gcd ( a[ x ] , a[ nxt[ x ] ] ) == 1 ) {
            ans.push_back ( nxt[ x ] ) ;
            f[ nxt[ x ] ] = true ;
            nxt[ x ] = nxt[ nxt[ x ] ] ;
            q.push ( x ) ;
        }
    }
    cout << ans.size ( ) ;
    for ( auto x : ans ) {
        cout << " " << x ;
    }
    cout << "\n" ;
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