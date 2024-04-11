#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007
#define MAXVAL 1000007

int n , k ;
int a[ MAXN ] ;
int pr[ MAXVAL ] ;
vector < pair < int , int > > v[ MAXVAL ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;

int aux = 0 ;

vector < int > ch ;

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
        ch.push_back ( k1 ) ;
        ch.push_back ( k2 ) ;
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
        ++ aux ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        prv[ i ] = -1 ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            if ( v[ a[ j ] - a[ i ] ].size ( ) > k ) { continue ; }
            v[ a[ j ] - a[ i ] ].push_back ( { i , j } ) ;
        }
    }
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        pr[ i ] = v[ i ].size ( ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        bool ret = true ;
        aux = 0 ;
        ch.clear ( ) ;
        for ( int j = i ; j < MAXVAL ; j += i ) {
            int len = pr[ j ] ;
            for ( int t = 0 ; t < len ; ++ t ) {
                unite ( v[ j ][ t ].first , v[ j ][ t ].second ) ;
                if ( aux > k ) {
                    ret = false ;
                    break ;
                }
            }
            if ( ret == false ) { break ; }
        }
        if ( ret == true ) {
            printf ( "%d\n" , i ) ;
            return ;
        }
        for ( auto x : ch ) {
            prv[ x ] = -1 ;
            rnk[ x ] = 0 ;
        }
        ch.clear ( ) ;
    }
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