#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int prv[ MAXN ] ;

bool used[ MAXN ] ;
vector < pair < int , int > > ans ;

vector < vector < int > > v ;

bool cmp ( vector < int > v1 , vector < int > v2 ) {
    return ( v1.size ( ) < v2.size ( ) ) ;
}

int find ( int vertex ) {
    if ( prv[ vertex ] == -1 ) { return vertex ; }
    int y = find ( prv[ vertex ] ) ;
    prv[ vertex ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
        ans.push_back ( make_pair ( k1 , k2 ) ) ;
    }
}

void input ( ) {
    scanf ( "%d", &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d", &a[ i ] ) ;
    }
}

void solve ( ) {
    if ( n == 1 ) { printf ( "YES\n" ) ; return ; }
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        prv[ i ] = -1 ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        vector < int > cycle ;
        if ( used[ i ] == true ) { continue ; }
        cycle.clear ( ) ;
        int x = i ;
        while ( 1 ) {
            cycle.push_back ( x ) ;
            used[ x ] = true ;
            x = a[ x ] ;
            if ( used[ x ] == true ) { break ; }
        }
        int sz = cycle.size ( ) ;
        v.push_back ( cycle ) ;
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    int g = v.size ( ) ;
    for ( i = 0 ; i < g ; i ++ ) {
        if ( v[ i ].size ( ) % v[ 0 ].size ( ) != 0) { printf ( "NO\n" ) ; return ; }
    }
    int sz = v[ 0 ].size ( ) ;
    if ( g == 1 && sz != 2 ) { printf ( "NO\n" ) ; return ; }
    if ( sz > 2 ) { printf ( "NO\n" ) ; return ; }
    printf ( "YES\n" ) ;
    for ( i = 0 ; i < sz - 1 ; i ++ ) {
        printf ( "%d %d\n" , v[ 0 ][ i ] , v[ 0 ][ i + 1 ] ) ;
    }
    for ( i = 1 ; i < g ; i ++ ) {
        int id = 0 ;
        for ( j = 0 ; j < v[ i ].size ( ) ; j ++ ) {
            printf ( "%d %d\n" , v[ 0 ][ id ] , v[ i ][ j ] ) ;
            id ++ ;
            id %= v[ 0 ].size ( ) ;
        }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}