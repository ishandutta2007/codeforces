#include<bits/stdc++.h>
using namespace std ;

#define MAXN 7007

#define WIN 1
#define LOSE -1
#define UNKNOWN 0

int n ;
int sz1 , sz2 ;
vector < int > a ;
vector < int > b ;

int dp[ MAXN ][ 2 ] ;
int lft[ MAXN ][ 2 ] ;

void bfs ( ) {
    queue < pair < int , int > > q ;
    q.push ( make_pair ( 1 , 0 ) ) ;
    q.push ( make_pair ( 1 , 1 ) ) ;
    pair < int , int > p ;
    int i ;
    while ( q.empty ( ) == false ) {
        p = q.front ( ) ;
        q.pop ( ) ;
        if ( p.second == 0 ) {
            for ( i = 0 ; i < sz2 ; i ++ ) {
                int h = p.first - b[ i ] ;
                if ( h < 1 ) { h += n ; }
                if ( dp[ p.first ][ p.second ] == LOSE ) {
                    if ( dp[ h ][ 1 ] == UNKNOWN ) {
                        dp[ h ][ 1 ] = WIN ;
                        lft[ h ][ 1 ] = -1 ;
                        q.push ( make_pair ( h , 1 ) ) ;
                    }
                }
                else {
                    lft[ h ][ 1 ] -- ;
                    if ( lft[ h ][ 1 ] == 0 ) {
                        dp[ h ][ 1 ] = LOSE ;
                        q.push ( make_pair ( h , 1 ) ) ;
                    }
                }
            }
        }
        else {
            for ( i = 0 ; i < sz1 ; i ++ ) {
                int h = p.first - a[ i ] ;
                if ( h < 1 ) { h += n ; }
                if ( dp[ p.first ][ p.second ] == LOSE ) {
                    if ( dp[ h ][ 0 ] == UNKNOWN ) {
                        dp[ h ][ 0 ] = WIN ;
                        lft[ h ][ 0 ] = -1 ;
                        q.push ( make_pair ( h , 0 ) ) ;
                    }
                }
                else {
                    lft[ h ][ 0 ] -- ;
                    if ( lft[ h ][ 0 ] == 0 ) {
                        dp[ h ][ 0 ] = LOSE ;
                        q.push ( make_pair ( h , 0 ) ) ;
                    }
                }
            }
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    scanf ( "%d" , &sz1 ) ;
    a.resize ( sz1 ) ;
    int i ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &sz2 ) ;
    b.resize ( sz2 ) ;
    for ( i = 0 ; i < sz2 ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    for ( i = 2 ; i <= n ; i ++ ) {
        dp[ i ][ 0 ] = dp[ i ][ 1 ] = UNKNOWN ;
        lft[ i ][ 0 ] = sz1 ;
        lft[ i ][ 1 ] = sz2 ;
    }
    dp[ 1 ][ 0 ] = dp[ 1 ][ 1 ] = LOSE ;
    lft[ 1 ][ 0 ] = lft[ 1 ][ 1 ] = -1 ;
}

void solve ( ) {
    bfs ( ) ;
    int i ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( dp[ i ][ 0 ] == WIN ) {
            printf ( "Win " ) ;
        }
        else if ( dp[ i ][ 0 ] == LOSE ) {
            printf ( "Lose " ) ;
        }
        else {
            printf ( "Loop " ) ;
        }
    }
    printf ( "\n" ) ;
     for ( i = 2 ; i <= n ; i ++ ) {
        if ( dp[ i ][ 1 ] == WIN ) {
            printf ( "Win " ) ;
        }
        else if ( dp[ i ][ 1 ] == LOSE ) {
            printf ( "Lose " ) ;
        }
        else {
            printf ( "Loop " ) ;
        }
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}