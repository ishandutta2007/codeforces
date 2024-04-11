#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 200007
int n ;
vector < int > v[ MAXN ] ;

int h[ MAXN ] ;
set < int > s[ MAXN ] ;

bool used[ MAXN ] ;
int lft[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    if ( n == 2 ) {
        printf ( "1\n" ) ;
        return ;
    }
    queue < int > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].size ( ) == 1 ) {
            q.push ( i ) ;
            h[ i ] = 0 ;
            s[ i ].insert ( 1 ) ;
        }
        else { lft[ i ] = v[ i ].size ( ) - 1 ; }
    }
    int cnt = n - 1 ;
    while ( cnt > 0 && q.empty ( ) == false ) {
        -- cnt ;
        int x = q.front ( ) ;
        q.pop ( ) ;
        used[ x ] = true ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( used[ v[ x ][ i ] ] == true ) { continue ; }
            -- lft[ v[ x ][ i ] ] ;
            h[ v[ x ][ i ] ] = h[ x ] + 1 ;
            s[ v[ x ][ i ] ].insert ( h[ v[ x ][ i ] ] ) ;
            if ( lft[ v[ x ][ i ] ] == 0 && s[ v[ x ][ i ] ].size ( ) == 1 ) {
                q.push ( v[ x ][ i ] ) ;
            }
        }
    }
    if ( cnt == 0 ) {
        int root ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( used[ i ] == false ) { root = i ; }
        }
        if ( s[ root ].size ( ) > 2 ) { printf ( "-1\n" ) ; return ; }
        set < int > :: iterator it ;
        int ans = 0 ;
        for ( it = s[ root ].begin ( ) ; it != s[ root ].end ( ) ; ++ it ) {
            ans += (*it) ;
        }
        while ( ( ans % 2 ) == 0 ) { ans /= 2 ; }
        printf ( "%d\n" , ans ) ;
    }
    else { printf ( "-1\n" ) ; }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}