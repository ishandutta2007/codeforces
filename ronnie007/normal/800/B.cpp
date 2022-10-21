#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
struct tuhla {
    double x , y ;
};

tuhla a[ MAXN ] ;

double dist ( tuhla p1 , tuhla p2 ) {
    return ( sqrt ( ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y ) ) ) ;
}

double dot ( tuhla p1 , tuhla p2 ) {
    return ( p1.x * p2.x + p1.y * p2.y ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lf%lf" , &a[ i ].x , &a[ i ].y ) ;
    }
}

void solve ( ) {
    double ans = dist ( a[ n ] , a[ 1 ] ) / 2 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ans = min ( ans , dist ( a[ i ] , a[ i + 1 ] ) / 2 ) ;
    }
    a[ n + 1 ] = a[ 1 ] ;
    a[ n + 2 ] = a[ 2 ] ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        tuhla aux1 , aux2 ;
        aux1 = a[ i + 1 ] ;
        aux2 = a[ i + 2 ] ;
        aux1.x -= a[ i ].x ; aux2.x -= a[ i ].x ;
        aux1.y -= a[ i ].y ; aux2.y -= a[ i ].y ;

        double ret = dot ( aux1 , aux2 ) ;
        ret /= dist ( a[ i + 2 ] , a[ i ] ) ;
        ret /= dist ( a[ i + 1 ] , a[ i ] ) ;

        ret = sqrt ( 1 - ret * ret ) ;
        ret *= dist ( a[ i + 1 ] , a[ i ] ) ;
        ans = min ( ans , ret / 2 ) ;
    }
    printf ( "%.16lf\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}