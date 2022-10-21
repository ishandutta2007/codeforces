#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , m ;
set < int > v[ MAXN ] ;

int used[ MAXN ] ;
set < int > s ;

int cur ;

void bfs ( int vertex ) {
    int i ;
    queue < int > q ;
    q.push ( vertex ) ;
    s.erase ( vertex ) ;
    while ( q.empty ( ) == false ) {
        vertex = q.front ( ) ;
        q.pop ( ) ;
        used[ vertex ] = 1 ;
        cur ++ ;
        set < int > :: iterator it ;
        vector < int > to_remove ;
        to_remove.clear ( ) ;
        int sz = 0 ;
        for ( it = s.begin ( ) ; it != s.end ( ) ; it ++ ) {
            int nw = (*it) ;
            if ( v[ vertex ].find ( nw ) == v[ vertex ].end ( ) ) {
                q.push ( nw ) ;
                to_remove.push_back ( nw ) ;
                sz ++ ;
            }
        }
        for ( i = 0 ; i < sz ; i ++ ) {
            s.erase ( to_remove[ i ] ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].insert ( y ) ;
        v[ y ].insert ( x ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        s.insert ( i ) ;
    }
}

void solve ( ) {
    int i ;
    vector < int > ret ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            cur = 0 ;
            bfs ( i ) ;
            ret.push_back ( cur ) ;
        }
    }
    sort ( ret.begin ( ) , ret.end ( ) ) ;
    int sz = ret.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d" , ret[ i ] ) ;
        if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}