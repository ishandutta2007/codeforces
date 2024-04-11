#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
using namespace std ;

#define MAXN 1007
#define PI 3.14159265358
int n ;
struct tuhla {
    int x , y ;
    int r ;
};
bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( p1.r > p2.r ) ;
}

tuhla a[ MAXN ] ;

int lvl[ MAXN ] ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;

double ans ;

double dist ( int p , int q ) {
    double dx = ( a[ p ].x - a[ q ].x ) ;
    double dy = ( a[ p ].y - a[ q ].y ) ;
    return ( dx * dx + dy * dy ) ;
}

double get_area ( int id ) {
    double ret = 0 ;
    ret = PI ;
    ret *= a[ id ].r ;
    ret *= a[ id ].r ;
    return ret ;
}

void dfs ( int vertex ) {
    int coef ;
    if ( used[ vertex ] == 1 || ( used[ vertex ] % 2 ) == 0 ) { coef = 1 ; }
    else { coef = -1 ; }
    ans += ( coef * get_area ( vertex ) ) ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        used[ v[ vertex ][ i ] ] = used[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].r ) ;
    }
    sort ( a + 1 , a + n + 1 , cmp ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = i + 1 ; j <= n ; j ++ ) {
            double aux = dist ( i , j ) ;
            double w = a[ i ].r ;
            w = ( w * w ) ;
            if ( aux < w ) {
                v[ i ].push_back ( j ) ;
            }
        }
    }
}

void solve ( ) {
    int i ;
    ans = 0.0000000000000000 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) { used[ i ] = 1 ; dfs ( i ) ; }
    }
    printf ( "%.12lf\n" , ans ) ;
}

int main ( ) {
    ///ios::sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}