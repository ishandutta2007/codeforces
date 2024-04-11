#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n , r ;

struct tuhla {
    int x , y ;
    int prob ;
};
tuhla a[ MAXN ] ;


double dp[ MAXN ][ 100 * MAXN ] ;
int sm ;

double f ( double val ) {
    int i , j ;
    for ( i = 1 ; i <= sm ; i ++ ) {
        if ( i <= r ) { dp[ n ][ i ] = 0.00000000 ; }
        else { dp[ n ][ i ] = val ; }
    }
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        for ( j = sm ; j >= 0 ; j -- ) {
            dp[ i ][ j ] = ( dp[ i + 1 ][ j + a[ i + 1 ].x ] + a[ i + 1 ].x ) * a[ i + 1 ].prob * 0.01 + ( dp[ i + 1 ][ j + a[ i + 1 ].y ] + a[ i + 1 ].y ) * ( 100 - a[ i + 1 ].prob ) * 0.01 ;
            if ( i != 0 && dp[ i ][ j ] > val ) { dp[ i ][ j ] = val ; }
        }
    }
    return dp[ 0 ][ 0 ] ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &r ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].prob ) ;
        sm += a[ i ].y ;
    }
}

void solve ( ) {
    double l , r , mid ;
    l = 0.0000000 ;
    r = 1000000000.000000 ;
    int i ;
    for ( i = 1 ; i <= 200 ; i ++ ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) > mid ) {
            l = mid ;
        }
        else {
            r = mid ;
        }
    }
    printf ( "%.12lf\n" , l ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}