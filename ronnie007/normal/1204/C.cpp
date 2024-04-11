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

#define MAXN 107
#define LEN 1000007


int n , m ;
string a[ MAXN ] ;
int path[ LEN ] ;

int dist[ MAXN ][ MAXN ] ;
int lst[ MAXN ] ;
int dp[ LEN ] ;
int prv[ LEN ] ;


void bfs ( int st ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        dist[ st ][ i ] = MAXN ;
    }
    dist[ st ][ st ] = 0 ;
    queue < int > q ;
    q.push ( st ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( a[ x ][ i ] == '1' && dist[ st ][ i ] == MAXN ) {
                dist[ st ][ i ] = dist[ st ][ x ] + 1 ;
                q.push ( i ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    cin >> m ;
    for ( int i = 0 ; i < m ; ++ i ) {
        cin >> path[ i ] ;
        -- path[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        bfs ( i ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        lst[ i ] = -1 ;
    }
    dp[ 0 ] = 1 ;
    lst[ path[ 0 ] ] = 0 ;
    prv[ 0 ] = -1 ;

    for ( int i = 1 ; i < m ; ++ i ) {
        dp[ i ] = LEN + 1 ;
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( lst[ j ] == -1 ) { continue ; }
            if ( dist[ j ][ path[ i ] ] == i - lst[ j ] ) {
                if ( dp[ i ] > dp[ lst[ j ] ] + 1 ) {
                    dp[ i ] = dp[ lst[ j ] ] + 1 ;
                    prv[ i ] = lst[ j ] ;
                }
            }
        }
        lst[ path[ i ] ] = i ;
    }
    printf ( "%d\n" , dp[ m - 1 ] ) ;
    vector < int > v ;
    int x = m - 1 ;
    while ( x != -1 ) {
        v.push_back ( path[ x ] + 1 ) ;
        x = prv[ x ] ;
    }
    for ( int i = dp[ m - 1 ] - 1 ; i >= 0 ; -- i ) {
        printf ( "%d " , v[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}