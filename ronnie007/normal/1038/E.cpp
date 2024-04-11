#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 107

int n ;
struct tuhla {
    int x , y ;
    int val ;
};
tuhla a[ MAXN ] ;

int add[ 7 ] ;
int deg[ 7 ] ;

int mn[ 7 ][ 7 ] ;


int prv[ 7 ] ;

int totsm[ 7 ][ 7 ] ;
bool used[ 7 ] ;


int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= 4 ; i ++ ) {
        prv[ i ] = -1 ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].val , &a[ i ].y ) ;
        UNITE ( a[ i ].x , a[ i ].y ) ;
        if ( mn[ a[ i ].x ][ a[ i ].y ] == 0 ) { mn[ a[ i ].x ][ a[ i ].y ] = a[ i ].val ; }
        if ( mn[ a[ i ].x ][ a[ i ].y ] > a[ i ].val ) { mn[ a[ i ].x ][ a[ i ].y ] = a[ i ].val ; }

        if ( mn[ a[ i ].y ][ a[ i ].x ] == 0 ) { mn[ a[ i ].y ][ a[ i ].x ] = a[ i ].val ; }
        if ( mn[ a[ i ].y ][ a[ i ].x ] > a[ i ].val ) { mn[ a[ i ].y ][ a[ i ].x ] = a[ i ].val ; }
        totsm[ a[ i ].x ][ a[ i ].y ] += a[ i ].val ;
        if ( a[ i ].x != a[ i ].y ) { totsm[ a[ i ].y ][ a[ i ].x ] += a[ i ].val ; }
    }
}

void solve ( ) {
    int i , j ;
    int mask ;
    int ans = 0 ;
    for ( mask = 1 ; mask < (1<<4) ; mask ++ ) {
        vector < int > v ;
        v.clear ( ) ;
        for ( i = 0 ; i < 4 ; i ++ ) {
            used[ i + 1 ] = false ;
            if ( (mask&(1<<i)) != 0 ) { v.push_back ( i + 1 ) ; used[ i + 1 ] = true ; }
        }
        int sz = v.size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            if ( find ( v[ i ] ) != find ( v[ 0 ] ) ) { break ; }
        }
        if ( i < sz ) { continue ; }
        int h = 0 ;
        for ( i = 1 ; i <= 4 ; i ++ ) { deg[ i ] = 0 ; }
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( a[ i ].x != a[ i ].y ) {
                if ( used[ a[ i ].x ] == true && used[ a[ i ].y ] == true ) {
                    deg[ a[ i ].x ] ++ ;
                    deg[ a[ i ].y ] ++ ;
                }
            }
        }
        for ( i = 0 ; i < sz ; i ++ ) {
            if ( ( deg[ v[ i ] ] % 2 ) == 1 ) { h ++ ; }
        }
        if ( h == 1 || h == 3 ) { continue ; }
        int cur = 0 ;
        if ( h == 4 ) {
            int subtr = -1 ;
            for ( i = 1 ; i <= 4 ; i ++ ) {
                for ( j = i + 1 ; j <= 4 ; j ++ ) {
                    if ( mn[ i ][ j ] > 0 && deg[ i ] > 1 && deg[ j ] > 1 ) {
                        if ( subtr < 0 ) { subtr = mn[ i ][ j ] ; }
                        if ( subtr > mn[ i ][ j ] ) { subtr = mn[ i ][ j ] ; }
                    }
                }
            }
            if ( subtr == -1 ) { continue ; }
            cur -= subtr ;
        }
        for ( i = 0 ; i < sz ; i ++ ) {
            for ( j = i ; j < sz ; j ++ ) {
                cur += totsm[ v[ i ] ][ v[ j ] ] ;
            }
        }
        if ( ans < cur ) { ans = cur ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}