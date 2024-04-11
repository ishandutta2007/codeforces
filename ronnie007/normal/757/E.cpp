#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000027
#define MOD 1000000007


int q ;
vector < pair < int , int > > v[ MAXN + 5 ] ;

int v_sz[ MAXN + 5 ] ;


int f[ MAXN + 5 ][ 21 ] ;


void input ( ) {
    scanf ( "%d" , &q ) ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( v[ i ].size ( ) != 0 ) { continue ; }
        for ( int j = i ; j < MAXN ; j += i ) {
            int aux = j ;
            int cnt = 0 ;
            while ( ( aux % i ) == 0 ) {
                aux /= i ;
                ++ cnt ;
            }
            v[ j ].push_back ( { i , cnt } ) ;
        }
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        v_sz[ i ] = v[ i ].size ( ) ;
    }
    f[ 0 ][ 0 ] = 1 ;
    for ( int j = 1 ; j < 20 ; ++ j ) {
        f[ 0 ][ j ] = 2 ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < 20 ; ++ j ) {
            for ( int t = 0 ; t <= j ; ++ t ) {
                f[ i ][ j ] += f[ i - 1 ][ t ] ;
                if ( f[ i ][ j ] >= MOD ) { f[ i ][ j ] -= MOD ; }
            }
        }
    }
}

void solve ( ) {
    while ( q -- ) {
        int len , x ;
        scanf ( "%d%d" , &len , &x ) ;
        long long ans = 1 ;
        for ( int i = 0 ; i < v_sz[ x ] ; ++ i ) {
            ans = ( ans * f[ len ][ v[ x ][ i ].second ] ) % MOD ;
        }
        printf ( "%d\n" , ans ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}