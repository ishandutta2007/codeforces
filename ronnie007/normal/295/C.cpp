#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 57
#define MOD 1000000007

int n , k ;
int br50 ;
int br100 ;

long long dp[ MAXN ][ MAXN ][ 3 ] ;
long long ways[ MAXN ][ MAXN ][ 3 ] ;
bool vis[ MAXN ][ MAXN ][ 3 ] ;


long long comb[ MAXN ][ MAXN ] ;


struct tuhla {
    int left50 ;
    int left100 ;
    int right50 ;
    int right100 ;
    int side ;
    int dist ;
    tuhla ( ) { left50 = left100 = right50 = right100 = dist = 0 ; }
    tuhla ( int _left50 , int _left100 , int _right50 , int _right100 , int _side , int _dist ) {
        left50 = _left50 ;
        left100 = _left100 ;
        right50 = _right50 ;
        right100 = _right100 ;
        side = _side ;
        dist = _dist ;
    }
};

void bfs ( ) {
    queue < struct tuhla > q ;
    int i , j ;
    q.push ( tuhla ( br50 , br100 , 0 , 0 , 0 , 0 ) ) ;
    ways[ br50 ][ br100 ][ 0 ] = 1 ;
    vis[ br50 ][ br100 ][ 0 ] = true ;
    while ( q.empty ( ) == false ) {
        tuhla u = q.front ( ) ;
        q.pop ( ) ;
        if ( u.left50 == 0 && u.left100 == 0 ) { break ; }
        vis[ u.left50 ][ u.left100 ][ u.side ] = true ;
        if ( u.side == 0 ) {
            for ( i = 0 ; i <= u.left50 ; i ++ ) {
                for ( j = 0 ; j <= u.left100 ; j ++ ) {
                    if ( i == 0 && j == 0 ) { continue ; }
                    if ( 50 * i + 100 * j > k ) { continue ; }
                    tuhla e ;
                    e.left50 = u.left50 - i ;
                    e.left100 = u.left100 - j ;
                    e.right50 = u.right50 + i ;
                    e.right100 = u.right100 + j ;
                    e.side = ( u.side ^ 1 ) ;
                    e.dist = u.dist + 1 ;
                    ways[ e.left50 ][ e.left100 ][ e.side ] += ( ( ( ways[ u.left50 ][ u.left100 ][ u.side ] * comb[ u.left50 ][ i ] ) % MOD ) * comb[ u.left100 ][ j ] ) % MOD ;
                    ways[ e.left50 ][ e.left100 ][ e.side ] %= MOD ;
                    if ( vis[ e.left50 ][ e.left100 ][ e.side ] == false ) {
                        dp[ e.left50 ][ e.left100 ][ e.side ] = dp[ u.left50 ][ u.left100 ][ u.side ] + 1 ;
                        vis[ e.left50 ][ e.left100 ][ e.side ] = true ;
                        q.push ( e ) ;
                    }
                }
            }
        }
        else {
            for ( i = 0 ; i <= u.right50 ; i ++ ) {
                for ( j = 0 ; j <= u.right100 ; j ++ ) {
                    if ( i == 0 && j == 0 ) { continue ; }
                    if ( 50 * i + 100 * j > k ) { continue ; }
                    tuhla e ;
                    e.left50 = u.left50 + i ;
                    e.left100 = u.left100 + j ;
                    e.right50 = u.right50 - i ;
                    e.right100 = u.right100 - j ;
                    e.side = ( u.side ^ 1 ) ;
                    e.dist = u.dist + 1 ;


                    ways[ e.left50 ][ e.left100 ][ e.side ] += ( ( ( ways[ u.left50 ][ u.left100 ][ u.side ]  * comb[ u.right50 ][ i ] ) % MOD ) * comb[ u.right100 ][ j ] ) % MOD ;
                    ways[ e.left50 ][ e.left100 ][ e.side ] %= MOD ;
                    if ( vis[ e.left50 ][ e.left100 ][ e.side ] == false ) {
                        dp[ e.left50 ][ e.left100 ][ e.side ] = dp[ u.left50 ][ u.left100 ][ u.side ] + 1 ;
                        vis[ e.left50 ][ e.left100 ][ e.side ] = true ;
                        q.push ( e ) ;
                    }
                }
            }
        }
    }
}

void init_comb ( ) {
    comb[ 0 ][ 0 ] = 1 ;
    int i , j ;
    for ( i = 1 ; i <= 50 ; i ++ ) {
        for ( j = 0 ; j <= i ; j ++ ) {
            comb[ i ][ j ] = comb[ i - 1 ][ j ] ;
            if ( j != 0 ) {
                comb[ i ][ j ] += comb[ i - 1 ][ j - 1 ] ;
                if ( comb[ i ][ j ] >= MOD ) {
                    comb[ i ][ j ] -= MOD ;
                }
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        if ( x == 50 ) {
            br50 ++ ;
        }
        else {
            br100 ++ ;
        }
    }
}

void solve ( ) {
    init_comb ( ) ;
    bfs ( ) ;
    if ( dp[ 0 ][ 0 ][ 1 ] == 0 ) { dp[ 0 ][ 0 ][ 1 ] -- ; }
    printf ( "%d\n" , dp[ 0 ][ 0 ][ 1 ] ) ;
    printf ( "%I64d\n" , ways[ 0 ][ 0 ][ 1 ] ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}