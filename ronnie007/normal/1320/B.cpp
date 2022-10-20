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

int n , m ;
vector < int > v[ MAXN ] ;
int f[ MAXN ] ;
int cnt[ MAXN ] ;

int len ;
int seq[ MAXN ] ;

void bfs ( int st ) {
    queue < int > q ;
    f[ st ] = 1 ;
    cnt[ st ] = 0 ;
    q.push ( st ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( f[ v[ x ][ i ] ] == 0 ) {
                f[ v[ x ][ i ] ] = f[ x ] + 1 ;
                q.push ( v[ x ][ i ] ) ;
            }
            if ( f[ v[ x ][ i ] ] == f[ x ] + 1 ) {
                ++ cnt[ v[ x ][ i ] ] ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ y ].push_back ( x ) ;
    }
    scanf ( "%d" , &len ) ;
    for ( int i = 1 ; i <= len ; ++ i ) {
        scanf ( "%d" , &seq[ i ] ) ;
    }
}

void solve ( ) {
    bfs ( seq[ len ] ) ;
    int x , y ;
    x = y = 0 ;
    for ( int i = 1 ; i < len ; ++ i ) {
        if ( f[ seq[ i + 1 ] ] != f[ seq[ i ] ] - 1 ) { ++ x ; ++ y ; }
        else {
            if ( cnt[ seq[ i ] ] != 1 ) { ++ y ; }
        }
    }
    printf ( "%d %d\n" , x , y ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}