#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

#define MOD 1000000007

int n , m ;
set < int > s[ MAXN ] ;

long long h[ MAXN ][ 2 ] ;
long long base[ 2 ] = { 37 , 1000003 } ;

map < pair < long long , long long > , int > w ;

int a[ 4 * MAXN ] ;
int PI[ 4 * MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        -- x ; -- y ;
        if ( x > y ) { swap ( x , y ) ; }
        s[ x ].insert ( y - x ) ;
        s[ y ].insert ( n + x - y ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        h[ i ][ 0 ] = h[ i ][ 1 ] = 1 ;
        for ( auto x : s[ i ] ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                h[ i ][ t ] = ( h[ i ][ t ] * base[ t ] + x ) % MOD ;
            }
        }
    }
    int id = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( w.find ( { h[ i ][ 0 ] , h[ i ][ 1 ] } ) == w.end ( ) ) {
            w[ { h[ i ][ 0 ] , h[ i ][ 1 ] } ] = ++ id ;
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        a[ i + 1 ] = w[ { h[ i ][ 0 ] , h[ i ][ 1 ] } ] ;
    }
    a[ n + 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ n + i + 1 ] = a[ n + n + i + 1 ] = a[ i ] ;
    }
    PI[ 0 ] = 0 ;
    PI[ 1 ] = 0 ;
    int l = 0 ;
    int cnt = 0 ;
    for ( int i = 2 ; i <= 3 * n + 1 ; ++ i ) {
        while ( l > 0 && a[ l + 1 ] != a[ i ] ) {
            l = PI[ l ] ;
        }
        if ( a[ l + 1 ] == a[ i ] ) { ++ l ; }
        PI[ i ] = l ;
        if ( l == n ) {
            ++ cnt ;
        }
    }
    if ( cnt > 2 ) {
        printf ( "Yes\n" ) ;
    }
    else {
        printf ( "No\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}