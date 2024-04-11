#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > aux[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int comp[ MAXN ] ;

long long ans[ MAXN ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y , int id ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 == k2 ) { return ; }
    ans[ id ] += 1LL * comp[ k1 ] * comp[ k2 ] ;
    if ( rnk[ k1 ] >= rnk[ k2 ] ) {
        rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        prv[ k2 ] = k1 ;
        comp[ k1 ] += comp[ k2 ] ;
    }
    else {
        prv[ k1 ] = k2 ;
        comp[ k2 ] += comp[ k1 ] ;
    }
}

void add ( int x , int gcd ) {
    int sz = v[ x ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( a[ v[ x ][ i ] ] % gcd != 0 ) { continue ; }
        unite ( x , v[ x ][ i ] , gcd ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        aux[ a[ i ] ].push_back ( i ) ;
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        comp[ i ] = 1 ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = MAXN - 1 ; i >= 1 ; -- i ) {
        for ( int j = i ; j < MAXN ; j += i ) {
            int sz = aux[ j ].size ( ) ;
            for ( int t = 0 ; t < sz ; ++ t ) {
                add ( aux[ j ][ t ] , i ) ;
            }
        }
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            ans[ i ] -= ans[ j ] ;
        }
        for ( int j = i ; j < MAXN ; j += i ) {
            int sz = aux[ j ].size ( ) ;
            for ( int t = 0 ; t < sz ; ++ t ) {
                prv[ aux[ j ][ t ] ] = -1 ;
                rnk[ aux[ j ][ t ] ] = 0 ;
                comp[ aux[ j ][ t ] ] = 1 ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ ans[ a[ i ] ] ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        if ( ans[ i ] > 0 ) {
            printf ( "%d %I64d\n" , i , ans[ i ] ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}