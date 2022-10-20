#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int st = 0 ;
    int wh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != i ) { st = i ; break ; }
    }
    if ( st != 0 ) {
        for ( int i = st + 1 ; i <= n ; ++ i ) {
            if ( a[ i ] == st ) { wh = i ; break ; }
        }
        while ( st < wh ) {
            swap ( a[ st ] , a[ wh ] ) ;
            ++ st , -- wh ;
        }
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// t = 1 ;
    /// scanf ( "%d" , &t ) ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}