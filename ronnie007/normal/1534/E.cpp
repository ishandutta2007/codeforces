#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 507

int n , k ;
int dist[ MAXN ][ MAXN ] ;
pair < int , int > prv[ MAXN ][ MAXN ] ;
int take[ MAXN ][ MAXN ] ;

int f[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    queue < pair < int , int > > q ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            dist[ i ][ j ] = MAXN ;
        }
    }
    dist[ n ][ 0 ] = 0 ;
    q.push ( { n , 0 } ) ;
    while ( q.empty ( ) == false ) {
        auto [ x , y ] = q.front ( ) ;
        q.pop ( ) ;
        for ( int i = 0 ; i <= k ; ++ i ) {
            int nx = x - i + ( k - i ) ;
            int ny = y - ( k - i ) + i ;
            if ( x - i < 0 || y - ( k - i ) < 0 ) { continue ; }
            if ( nx < 0 || n < nx ) { continue ; }
            if ( ny < 0 || n < ny ) { continue ; }
            if ( dist[ nx ][ ny ] == MAXN ) {
                dist[ nx ][ ny ] = dist[ x ][ y ] + 1 ;
                prv[ nx ][ ny ] = { x , y } ;
                take[ nx ][ ny ] = i ;
                q.push ( { nx , ny } ) ;
            }
        }
    }
    if ( dist[ 0 ][ n ] == MAXN ) {
        printf ( "-1\n" ) ;
        fflush ( stdout ) ;
        return ;
    }
    int x = 0 , y = n ;
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ] = 0 ;
    }
    vector < int > v ;
    while ( x != n || y != 0 ) {
        v.push_back ( take[ x ][ y ] ) ;
        int nx , ny ;
        nx = prv[ x ][ y ].first ;
        ny = prv[ x ][ y ].second ;
        x = nx , y = ny ;
    }
    int sz = v.size ( ) ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        int cnt1 = v[ i ] ;
        int cnt2 = k - v[ i ] ;
        printf ( "?" ) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( f[ j ] == 0 && cnt1 > 0 ) {
                f[ j ] ^= 1 , -- cnt1 ;
                printf ( " %d" , j ) ;
            }
            else if ( f[ j ] == 1 && cnt2 > 0 ) {
                f[ j ] ^= 1 , -- cnt2 ;
                printf ( " %d" , j ) ;
            }
        }
        printf ( "\n" ) ;
        fflush ( stdout ) ;
        int ret ; scanf ( "%d" , &ret ) ;
        ans ^= ret ;
    }
    printf ( "! %d\n" , ans ) ;
    fflush ( stdout ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}