#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , m , k ;
pair < int , int > a[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

int fr[ MAXN ] ;

int ans[ MAXN ] ;

bool del[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        v[ a[ i ].first ].push_back ( make_pair ( a[ i ].second , i ) ) ;
        v[ a[ i ].second ].push_back ( make_pair ( a[ i ].first , i ) ) ;
        fr[ a[ i ].first ] ++ ;
        fr[ a[ i ].second ] ++ ;
    }
}

void solve ( ) {
    int i , j ;
    queue < int > q ;
    int tot = n ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( fr[ i ] < k ) {
            q.push ( i ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        del[ x ] = true ;
        tot -- ;
        int sz = v[ x ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            int h = v[ x ][ i ].first ;
            fr[ h ] -- ;
            if ( fr[ h ] == ( k - 1 ) ) {
                q.push ( h ) ;
            }
        }
    }
    ans[ m ] = tot ;
    for ( i = m ; i >= 1 ; i -- ) {
        if ( del[ a[ i ].first ] == true || del[ a[ i ].second ] == true ) { ans[ i - 1 ] = tot ; continue ; }
        fr[ a[ i ].first ] -- ;
        fr[ a[ i ].second ] -- ;
        if ( fr[ a[ i ].first ] < k ) { q.push ( a[ i ].first ) ; }
        if ( fr[ a[ i ].second ] < k ) { q.push ( a[ i ].second ) ; }
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            del[ x ] = true ;
            tot -- ;
            int sz = v[ x ].size ( ) ;
            for ( j = 0 ; j < sz ; j ++ ) {
                int h = v[ x ][ j ].first ;
                if ( v[ x ][ j ].second >= i ) { continue ; }
                fr[ h ] -- ;
                if ( fr[ h ] == ( k - 1 ) ) {
                    q.push ( h ) ;
                }
            }
        }
        ans[ i - 1 ] = tot ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}