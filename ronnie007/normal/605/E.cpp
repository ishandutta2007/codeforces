#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007
#define eps 0.000000001


int n ;
double p[ MAXN ][ MAXN ] ;

double ex[ MAXN ] ;
double coef[ MAXN ] ;
bool vis[ MAXN ] ;

double ans[ MAXN ] ;

priority_queue < pair < double , int > > q ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            int x ;
            scanf ( "%d" , &x ) ;
            p[ i ][ j ] = ( x / 100.0 ) ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans[ i ] = -1.0 ;
        ex[ i ] = 0.0 ;
        coef[ i ] = 1.0 ;
    }
    ex[ n ] = ans[ n ] = 0.0 ;
    q.push ( { -ans[ n ] , n } ) ;
    while ( q.empty ( ) == false ) {
        auto [ cost , x ] = q.top ( ) ;
        q.pop ( ) ;
        cost = -cost ;
        if ( vis[ x ] == true ) { continue ; }
        vis[ x ] = true ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( vis[ i ] == false && p[ i ][ x ] > 0.0 ) {
                ex[ i ] += coef[ i ] * p[ i ][ x ] * ( 1.0 + ans[ x ] ) ;
                coef[ i ] *= ( 1.0 - p[ i ][ x ] ) ;
                if ( ans[ i ] < 0 || ( ex[ i ] + coef[ i ] ) / ( 1.0 - coef[ i ] ) < ans[ i ] ) {
                    ans[ i ] = ( ex[ i ] + coef[ i ] ) / ( 1.0 - coef[ i ] ) ;
                    // printf ( "%d -> %.12lf\n" , i , ans[ i ] ) ;
                    q.push ( { -ans[ i ] , i } ) ;
                }
            }
        }
    }
    printf ( "%.12lf\n" , ans[ 1 ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}