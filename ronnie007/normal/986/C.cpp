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

#define MAXN 10000007
#define MAXBIT 24

int n , m ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;
int used[ MAXN ] ;

void bfs ( int x ) {
    queue < int > q ;
    q.push ( x ) ;
    used[ x ] = 1 ;
    while ( q.empty ( ) == false ) {
        x = q.front ( ) ;
        q.pop ( ) ;
        if ( x <= m ) {
            if ( used[ m + a[ x ] + 1 ] == 0 ) {
                used[ m + a[ x ] + 1 ] = 1 ;
                q.push ( m + a[ x ] + 1 ) ;
            }
        }
        else {
            for ( int i = 0 ; i < n ; ++ i ) {
                if ( ( ( x - m - 1 ) & (1<<i) ) == 0 ) {
                    if ( used[ x + (1<<i) ] == 0 ) {
                        used[ x + (1<<i) ] = 1 ;
                        q.push ( x + (1<<i) ) ;
                    }
                }
            }
        }
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( used[ v[ x ][ i ] ] == 0 ) {
                used[ v[ x ][ i ] ] = 1 ;
                q.push ( v[ x ][ i ] ) ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        v[ m + ( ( (1<<n) - 1 ) ^ a[ i ] ) + 1 ].push_back ( i ) ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( used[ i ] == 0 ) {
            ++ ans ;
            bfs ( i ) ;
        }
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