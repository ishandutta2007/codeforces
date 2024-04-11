#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2007

int n , p ;
int a[ MAXN ] ;

vector < int > ans ;

void f ( int x ) {
    int init = x ;
    long long h = 1 ;
    int id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( id < n && a[ id + 1 ] <= x ) { ++ id ; }
        h = ( h * ( id - ( i - 1 ) ) ) % p ;
        ++ x ;
    }
    if ( h != 0 ) {
        ans.push_back ( init ) ;
    }
}

void input ( ) {
    cin >> n >> p ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= 2000 ; ++ i ) {
        f ( i ) ;
    }
    int sz = ans.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}