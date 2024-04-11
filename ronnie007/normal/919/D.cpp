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
using namespace std ;

#define MAXN 300007

int n , m ;
string a ;
vector < int > v[ MAXN ] ;

int used[ MAXN ] ;
int f[ MAXN ] ;
int curval ;

bool fl ;

void check_cycle ( int vertex ) {
    if ( used[ vertex ] != 0 ) { return ; }
    used[ vertex ] = 2 ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == 2 ) { fl = true ; }
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            check_cycle ( v[ vertex ][ i ] ) ;
        }
    }
    used[ vertex ] = 1 ;
}

void dfs ( int vertex ) {
    if ( used[ vertex ] != 0 ) { return ; }
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    int mx = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs ( v[ vertex ][ i ] ) ;
        }
        if ( mx < f[ v[ vertex ][ i ] ] ) {
            mx = f[ v[ vertex ][ i ] ] ;
        }
    }
    if ( ( a[ vertex - 1 ] - 'a' ) == curval ) { mx ++ ; }
    f[ vertex ] = mx ;
}

void input ( ) {
    cin >> n >> m ;
    cin >> a ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
    }
}

void solve ( ) {
    int i , j ;
    int ans = 0 ;
    fl = false ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) { check_cycle ( i ) ; }
    }
    if ( fl == true ) { printf ( "-1\n" ) ; return ; }
    for ( i = 0 ; i < 26 ; i ++ ) {
        curval = i ;
        for ( j = 1 ; j <= n ; j ++ ) {
            used[ j ] = f[ j ] = 0 ;
        }
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( used[ j ] == 0 ) {
                dfs ( j ) ;
            }
        }
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( ans < f[ j ] ) {
                ans = f[ j ] ;
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}