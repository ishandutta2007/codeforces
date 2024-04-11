#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int val[ MAXN ] ;
int deg[ MAXN ] ;

queue < int > q ;

bool bfs ( ) {
    for ( int i = 1 ; i <= n  ; ++ i ) {
        val[ i ] = 0 ;
        if ( deg[ i ] == 0 ) { q.push ( i ) ; }
    }
    int cnt = 0 ;
    int id = n;
    while ( q.empty ( ) == false ) {
        ++ cnt ;
        int x = q.front ( ) ;
        q.pop ( ) ;
        val[ x ] = id -- ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int h = v[ x ][ i ] ;
            -- deg[ h ] ;
            if ( deg[ h ] == 0 ) {
                q.push ( h ) ;
            }
        }
    }
    return ( cnt == n ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        deg[ i ] = 0 ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == -1 || a[ i ] > n ) { continue ; }
        v[ a[ i ] ].push_back ( i ) ;
        ++ deg[ i ] ;
    }
    priority_queue < int > pq ;
    while ( pq.empty ( ) == false ) { pq.pop ( ) ; }

    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( pq.empty ( ) == false && a[ pq.top ( ) ] <= i ) { pq.pop ( ) ; }

        if ( pq.empty ( ) == false ) {
            v[ pq.top ( ) ].push_back ( i ) ;
            ++ deg[ i ] ;
        }
        if ( a[ i ] != -1 ) {
            pq.push ( i ) ;
        }
    }
    if ( bfs ( ) == false ) {
        printf ( "-1\n" ) ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , val[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}