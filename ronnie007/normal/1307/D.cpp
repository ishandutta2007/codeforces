#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std ;

#define MAXN 200007
int n , m , k ;
vector < int > w ;
vector < int > v[ MAXN ] ;

int dist[ MAXN ][ 2 ] ;
int mn[ MAXN ] ;

void f ( int st , int id ) {
    queue < int > q ;
    q.push ( st ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ][ id ] = -1 ;
    }
    dist[ st ][ id ] = 0 ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( dist[ v[ x ][ i ] ][ id ] == -1 ) {
                dist[ v[ x ][ i ] ][ id ] = dist[ x ][ id ] + 1 ;
                q.push ( v[ x ][ i ] ) ;
            }
        }
    }
}

bool cmp ( int x , int y ) {
    return ( dist[ x ][ 0 ] < dist[ y ][ 0 ] ) ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    w.resize ( k ) ;
    for ( int i = 0 ; i < k ; ++ i ) {
        scanf ( "%d" , &w[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) , v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    f ( 1 , 0 ) ;
    f ( n , 1 ) ;
    sort ( w.begin ( ) , w.end ( ) , cmp ) ;
    int ans = 0 ;
    mn[ k - 1 ] = dist[ w[ k - 1 ] ][ 1 ] ;
    for ( int i = k - 2 ; i >= 0 ; -- i ) {
        mn[ i ] = max ( mn[ i + 1 ] , dist[ w[ i ] ][ 1 ] ) ;
    }
    for ( int i = 0 ; i < k - 1 ; ++ i ) {
        ans = max ( ans , min ( dist[ n ][ 0 ] , dist[ w[ i ] ][ 0 ] + mn[ i + 1 ] + 1 ) ) ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}