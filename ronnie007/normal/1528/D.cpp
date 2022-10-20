#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 601
#define inf 2000000007

int n ;
unsigned int init[ MAXN ][ MAXN ] ;

unsigned int ans[ MAXN ][ MAXN ] ;

unsigned int h[ MAXN ] ;
bool done[ MAXN ] ;

unsigned aux[ MAXN ] ;

void calc ( int ori ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        h[ i ] = inf ;
        done[ i ] = false ;
    }
    h[ ori ] = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int pos = -1 , mn = inf ;
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( done[ j ] == false && mn > h[ j ] ) {
                pos = j , mn = h[ j ] ;
            }
        }
        done[ pos ] = true ;
        ans[ ori ][ pos ] = mn ;
        int lft = ( mn % n ) ;
        for ( int j = 0 ; j < n ; ++ j ) {
            aux[ ( j + lft ) % n ] = init[ pos ][ j ] + ans[ ori ][ pos ] ;
        }
        for ( int steps = 0 ; steps < 2 ; ++ steps ) {
            for ( int j = 0 ; j < n ; ++ j ) {
                int nxt = ( j + 1 ) % n ;
                if ( aux[ nxt ] > aux[ j ] + 1 ) {
                    aux[ nxt ] = aux[ j ] + 1 ;
                }
            }
        }
        for ( int j = 0 ; j < n ; ++ j ) {
            h[ j ] = min ( h[ j ] , aux[ j ] ) ;
        }
    }
}

void input ( ) {
    int m ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            init[ i ][ j ] = inf ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( init[ x ][ y ] > z ) { init[ x ][ y ] = z ; }
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        calc ( i ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            printf ( "%u " , ans[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
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