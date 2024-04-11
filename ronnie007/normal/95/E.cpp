#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int prv[ MAXN ] ;
int comp_sz[ MAXN ] ;
int rnk[ MAXN ] ;

int num[ MAXN ] ;

int dp[ MAXN ] ;

vector < pair < int , int > > v ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            if ( rnk[ k1 ] == rnk[ k2 ] ) { ++ rnk[ k1 ] ; }
            prv[ k2 ] = k1 ;
            comp_sz[ k1 ] += comp_sz[ k2 ] ;
        }
        else {
            prv[ k1 ] = k2 ;
            comp_sz[ k2 ] += comp_sz[ k1 ] ;
        }
    }
}

void input ( ) {
    int m ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        comp_sz[ i ] = 1 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        unite ( x , y ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( prv[ i ] == -1 ) {
            ++ num[ comp_sz[ i ] ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( num[ i ] > 0 ) {
            int h = 1 ;
            int sm = 0 ;
            while ( h < num[ i ] ) {
                sm += h ;
                v.push_back ( { h * i , h } ) ;
                h *= 2 ;
            }
            if ( num[ i ] > sm ) {
                v.push_back ( { ( num[ i ] - sm ) * i , num[ i ] - sm } ) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ] = MAXN ;
    }
    dp[ 0 ] = 0 ;
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( int j = n - v[ i ].first ; j >= 0 ; -- j ) {
            if ( dp[ j ] == MAXN ) { continue ; }
            dp[ j + v[ i ].first ] = min ( dp[ j + v[ i ].first ] , dp[ j ] + v[ i ].second ) ;
        }
    }
    int ans = MAXN ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        bool fl = true ;
        int aux = i ;
        while ( aux > 0 ) {
            int r = ( aux % 10 ) ;
            aux /= 10 ;
            if ( r != 4 && r != 7 ) {
                fl = false ;
                break ;
            }
        }
        if ( fl == true ) {
            ans = min ( ans , dp[ i ] - 1 ) ;
        }
    }
    if ( ans > n ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}