#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 3000007

int n ;
vector < int > v[ 2 ] ;
int r ;

set < int > s ;
vector < int > a ;

bool blocked[ 2 ][ MAXN ] ;
int dp[ 2 ][ MAXN ] ;
bool turn[ 2 ][ MAXN ] ;

vector < int > turns ;
vector < pair < int , int > > shots ;

void proc ( int row ) {
    int x = n ;
    while ( x > 0 ) {
        if ( turn[ row ][ x ] == true ) {
            turns.push_back ( a[ x - 1 ] ) ;
            row ^= 1 ;
        }
        if ( blocked[ row ][ x ] == true ) {
            shots.push_back ( { a[ x - 1 ] - dp[ row ][ x ] , row + 1 } ) ;
        }
        -- x ;
    }
    reverse ( turns.begin ( ) , turns.end ( ) ) ;
    reverse ( shots.begin ( ) , shots.end ( ) ) ;
    printf ( "Yes\n" ) ;
    int sz = turns.size ( ) ; printf ( "%d\n" , sz ) ;
    for ( auto x : turns ) { printf ( "%d " , x ) ; }
    printf ( "\n" ) ;
    sz = shots.size ( ) ; printf ( "%d\n" , sz ) ;
    for ( auto [ x , y ] : shots ) { printf ( "%d %d\n" , x , y ) ; }
}

void input ( ) {
    int sz1 , sz2 ;
    scanf ( "%d%d%d%d" , &n , &sz1 , &sz2 , &r ) ;
    s.insert ( 0 ) ;
    v[ 0 ].resize ( sz1 ) ;
    v[ 1 ].resize ( sz2 ) ;
    s.insert ( 0 ) ;
    s.insert ( n ) ;
    for ( int i = 0 ; i < sz1 ; ++ i ) {
        scanf ( "%d" , &v[ 0 ][ i ] ) ;
        s.insert ( v[ 0 ][ i ] - 1 ) ;
        s.insert ( v[ 0 ][ i ] ) ;
        if ( v[ 0 ][ i ] < n ) {
            s.insert ( v[ 0 ][ i ] + 1 ) ;
        }
    }
    for ( int i = 0 ; i < sz2 ; ++ i ) {
        scanf ( "%d" , &v[ 1 ][ i ] ) ;
        s.insert ( v[ 1 ][ i ] - 1 ) ;
        s.insert ( v[ 1 ][ i ] ) ;
        if ( v[ 1 ][ i ] < n ) {
            s.insert ( v[ 1 ][ i ] + 1 ) ;
        }
    }
}

void solve ( ) {
    for ( auto x : s ) {
        a.push_back ( x ) ;
    }
    n = a.size ( ) ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        int hh = 0 ;
        for ( auto x : v[ i ] ) {
            while ( a[ hh ] < x ) { ++ hh ; }
            blocked[ i ][ hh + 1 ] = true ;
        }
    }
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ 0 ][ 1 ] = dp[ 1 ][ 1 ] = 0 ;
    turn[ 1 ][ 1 ] = true ;

    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            if ( blocked[ j ][ i ] == false ) {
                if ( dp[ j ][ i - 1 ] > -1 ) {
                    dp[ j ][ i ] = max ( dp[ j ][ i ] , dp[ j ][ i - 1 ] + a[ i - 1 ] - a[ i - 2 ] ) ;
                }
            }
            else {
                if ( dp[ j ][ i - 1 ] + a[ i - 1 ] - a[ i - 2 ] > r ) {
                    dp[ j ][ i ] = max ( dp[ j ][ i ] , dp[ j ][ i - 1 ] + a[ i - 1 ] - a[ i - 2 ] - r ) ;
                }
            }
        }
        for ( int j = 0 ; j < 2 ; ++ j ) {
            if ( blocked[ j ][ i ] == false ) {
                if ( dp[ j ^ 1 ][ i ] != -1 && min ( r , dp[ j ^ 1 ][ i ] ) > dp[ j ][ i ] ) {
                    dp[ j ][ i ] = min ( r , dp[ j ^ 1 ][ i ] ) , turn[ j ][ i ] = true ;
                }
            }
        }
    }

    if ( dp[ 0 ][ n ] == -1 && dp[ 1 ][ n ] == -1 ) {
        printf ( "No\n" ) ;
        return ;
    }
    if ( dp[ 0 ][ n ] > -1 ) {
        proc ( 0 ) ;
    }
    else { proc ( 1 ) ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}