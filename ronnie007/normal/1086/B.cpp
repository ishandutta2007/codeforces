#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
int deg[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        ++ deg[ x ] ; ++ deg[ y ] ;
    }
}

void solve ( ) {
    double ans = 0.0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( deg[ i ] == 1 ) { ans += 1.0 ; }
    }
    ans = ( k / ans ) * 2 ;
    printf ( "%.16lf\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}