#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < pair < int , int > > edgelist ;

int dist[ MAXN ] ;

int ans = MAXN ;

inline bool check ( int x , int y , int id ) {
    if ( x == edgelist[ id ].first && y == edgelist[ id ].second ) { return false ; }
    if ( y == edgelist[ id ].first && x == edgelist[ id ].second ) { return false ; }
    return true ;
}

void bfs ( int st , int id ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] = MAXN ;
    }
    dist[ st ] = 0 ;
    queue < int > q ;
    q.push ( st ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( dist[ v[ x ][ i ] ] == MAXN && check ( x , v[ x ][ i ] , id ) == true ) {
                dist[ v[ x ][ i ] ] = dist[ x ] + 1 ;
                q.push ( v[ x ][ i ] ) ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= 60 ; ++ i ) {
        vector < int > aux ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( a[ j ] & (1LL<<i) ) != 0 ) {
                aux.push_back ( j ) ;
            }
        }
        if ( aux.size ( ) >= 3 ) { printf ( "3\n" ) ; return ; }
        if ( aux.size ( ) == 2 ) {
            v[ aux[ 0 ] ].push_back ( aux[ 1 ] ) , v[ aux[ 1 ] ].push_back ( aux[ 0 ] ) ;
            edgelist.push_back ( { aux[ 0 ] , aux[ 1 ] } ) ;
        }
    }
    int sz = edgelist.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        bfs ( edgelist[ i ].second , i ) ;
        if ( ans > dist[ edgelist[ i ].first ] + 1 ) {
            ans = dist[ edgelist[ i ].first ] + 1 ;
        }
    }
    if ( ans == MAXN ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}