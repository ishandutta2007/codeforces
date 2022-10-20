#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m , k ;

int prv[ MAXN ] ;

int val[ MAXN ] ;


int ans = -1 ;
struct tuhla {
    int x , y , z ;
    tuhla ( ) { x = y = z = 0 ; }
    tuhla ( int _x , int _y , int _z ) {
        x = _x ;
        y = _y ;
        z = _z ;
    }
};
vector < tuhla > v ;
bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( p1.z < p2.z ) ;
}

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( tuhla u ) {
    int k1 = find ( u.x ) ;
    int k2 = find ( u.y ) ;
    if ( k1 != k2 ) {
        if ( val[ k1 ] + val[ k2 ] == k ) {
            if ( ans == -1 ) { ans = u.z ; }
        }
        val[ k2 ] += val[ k1 ] ;
        prv[ k1 ] = k2 ;
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        prv[ i ] = -1 ;
        val[ i ] = 0 ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        val[ x ] = 1 ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v.push_back ( tuhla ( x , y , z ) ) ;
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    for ( i = 0 ; i < m ; i ++ ) {
        UNITE ( v[ i ] ) ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
        printf ( "%d " , ans ) ;
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