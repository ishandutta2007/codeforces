#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 1007

int n , m ;
int a[ 2 ][ MAXN ] ;

bool can[ 2 ][ 500 * MAXN ] ;
int prv[ 2 ][ 500 * MAXN ] ;
bool used[ 2 ][ MAXN ] ;

vector < int > v1[ 2 ] ;
vector < int > v2[ 2 ] ;

vector < int > ord[ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ 0 ][ i ] ) ;
    }
    scanf ( "%d" , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &a[ 1 ][ i ] ) ;
    }
}

void solve ( ) {
    if ( n != m ) {
        printf ( "No\n" ) ;
        return ;
    }
    for ( int wh = 0 ; wh < 2 ; ++ wh ) {
        int sm = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            sm += a[ wh ][ i ] ;
            used[ wh ][ i ] = false ;
        }
        if ( ( sm % 2 ) != 0 ) {
            printf ( "No\n" ) ;
            return ;
        }
        sm /= 2 ;
        for ( int i = 0 ; i <= sm ; ++ i ) {
            can[ wh ][ i ] = false ;
            prv[ wh ][ i ] = -1 ;
        }
        can[ wh ][ 0 ] = true ;
        int aux = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = sm - a[ wh ][ i ] ; j >= 0 ; -- j ) {
                if ( can[ wh ][ j ] == true && can[ wh ][ j + a[ wh ][ i ] ] == false ) {
                    can[ wh ][ j + a[ wh ][ i ] ] = true ;
                    prv[ wh ][ j + a[ wh ][ i ] ] = i ;
                }
            }
        }
        if ( can[ wh ][ sm ] == false ) {
            printf ( "No\n" ) ;
            return ;
        }
        while ( sm > 0 ) {
            used[ wh ][ prv[ wh ][ sm ] ] = true ;
            sm -= a[ wh ][ prv[ wh ][ sm ] ] ;
        }
        v1[ wh ].clear ( ) ; v2[ wh ].clear ( ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( used[ wh ][ i ] == true ) { v1[ wh ].push_back ( a[ wh ][ i ] ) ; }
            else { v2[ wh ].push_back ( a[ wh ][ i ] ) ; }
        }
    }
    ord[ 0 ].clear ( ) ;
    ord[ 1 ].clear ( ) ;
    sort ( v1[ 0 ].begin ( ) , v1[ 0 ].end ( ) , greater < int > ( ) ) ;
    sort ( v2[ 0 ].begin ( ) , v2[ 0 ].end ( ) , greater < int > ( ) ) ;
        
    if ( v1[ 0 ].size ( ) < v2[ 0 ].size ( ) ) {
        for ( auto x : v1[ 0 ] ) {
            ord[ 0 ].push_back ( x ) ;
        }
        for ( auto x : v2[ 0 ] ) {
            ord[ 0 ].push_back ( - x ) ;
        }
    }
    else {
        for ( auto x : v2[ 0 ] ) {
            ord[ 0 ].push_back ( x ) ;
        }
        for ( auto x : v1[ 0 ] ) {
            ord[ 0 ].push_back ( - x ) ;
        }
    }

    sort ( v1[ 1 ].begin ( ) , v1[ 1 ].end ( ) ) ;
    sort ( v2[ 1 ].begin ( ) , v2[ 1 ].end ( ) ) ;
    if ( v1[ 1 ].size ( ) > v2[ 1 ].size ( ) ) {
        for ( auto x : v1[ 1 ] ) {
            ord[ 1 ].push_back ( x ) ;
        }
        for ( auto x : v2[ 1 ] ) {
            ord[ 1 ].push_back ( - x ) ;
        }
    }
    else {
        for ( auto x : v2[ 1 ] ) {
            ord[ 1 ].push_back ( x ) ;
        }
        for ( auto x : v1[ 1 ] ) {
            ord[ 1 ].push_back ( - x ) ;
        }
    }
    printf ( "Yes\n" ) ;
    int x , y ;
    x = y = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        x += ord[ 0 ][ i ] ;
        printf ( "%d %d\n" , x , y ) ;
        y += ord[ 1 ][ i ] ;
        printf ( "%d %d\n" , x , y ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    // t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}