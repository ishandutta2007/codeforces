#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int cnt[ 2 ] ;

void input ( ) {
    cin >> n ;
    cnt[ 0 ] = cnt[ 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ ( a[ i ] % 2 ) ] ;
    }
}

vector < int > v[ 2 ] ;

void solve ( ) {
    long long ans = -1 ;
    for ( int st = 0 ; st < 2 ; ++ st ) {
        v[ 0 ].clear ( ) ; v[ 1 ].clear ( ) ;
        for ( int i = 1 ; i <= n ; i += 2 ) {
            v[ st ].push_back ( i ) ;
        }
        for ( int i = 2 ; i <= n ; i += 2 ) {
            v[ ( st ^ 1 ) ].push_back ( i ) ;
        }

        if ( (int)v[ 0 ].size ( ) != cnt[ 0 ] ) { continue ; }
        if ( (int)v[ 1 ].size ( ) != cnt[ 1 ] ) { continue ; }

        long long aux = 0 ;
        int pos[ 2 ] ;
        pos[ 0 ] = pos[ 1 ] = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            int hh = ( a[ i ] % 2 ) ;
            aux += abs ( i - v[ hh ][ pos[ hh ] ++ ] ) ;
        }
        aux /= 2 ;
        if ( ans < 0 || ans > aux ) { ans = aux ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
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