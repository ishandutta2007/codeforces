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

#define MAXN 100007
#define inf 1000000007

int n , m ;
vector < int > v[ MAXN ] ;
vector < int > pref[ MAXN ] ;

int mn ;

bool cmp ( vector < int > v1 , vector < int > v2 ) {
    return ( v1.size ( ) < v2.size ( ) ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
    }
    sort ( v + 1 , v + m + 1 , cmp ) ;
    mn = n ;
    for ( i = 1 ; i <= m ; i ++ ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) , greater<int>() ) ;
        int sz = v[ i ].size ( ) ;
        mn = min ( mn , sz ) ;
        pref[ i ].resize ( sz + 1 ) ;
        pref[ i ][ 0 ] = 0 ;
        for ( int j = 1 ; j <= sz ; j ++ ) {
            pref[ i ][ j ] = ( pref[ i ][ j - 1 ] + v[ i ][ j - 1 ] ) ;
        }
    }
}

void solve ( ) {
    int i , j ;
    int ans = 0 ;
    int st = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int cur = 0 ;
        for ( j = st ; j <= m ; j ++ ) {
            if ( v[ j ].size ( ) < i ) { st = j + 1 ; continue ; }
            cur = ( pref[ j ][ i ] > 0 ) ? cur + pref[ j ][ i ] : cur ;
        }
        if ( cur > ans ) { ans = cur ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}