#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 200007
int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;
struct edge {
    int x , y ;
    int cost ;
    edge ( ) { x = y = cost = 0 ; }
    edge ( int _x , int _y , int _cost ) {
        x = _x ; y = _y ;
        cost = _cost ;
    }
};
vector < edge > v ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;

long long ans ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( edge aux ) {
    int k1 = find ( aux.x ) ;
    int k2 = find ( aux.y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
    else {
        ans += aux.cost ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int x ;
            scanf ( "%d" , &x ) ;
            v.push_back ( edge ( i , x + n , a[ i ] + b[ x ] ) ) ;
        }
    }
}

void solve ( ) {
    auto cmp = [&] ( edge p1 , edge p2 ) {
        return p1.cost > p2.cost ;
    };
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    for ( int i = 1 ; i <= n + m ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        UNITE ( v[ i ] ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}