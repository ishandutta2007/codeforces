#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 5007
int n , m ;
vector < pair < int , int > > v[ MAXN ] ;

int cl[ MAXN ] ;

int used[ MAXN ] ;
int ans = 1 ;

void dfs ( int vertex ) {
    used[ vertex ] = 2 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ v[ vertex ][ i ].first ] == 0 ) {
            dfs ( v[ vertex ][ i ].first ) ;
        }
        else if ( used[ v[ vertex ][ i ].first ] == 2 ) {
            cl[ v[ vertex ][ i ].second ] = 2 ;
            ans = 2 ;
        }
    }
    used[ vertex ] = 1 ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
        cl[ i ] = 1 ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            dfs ( i ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        printf ( "%d " , cl[ i ] ) ;
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