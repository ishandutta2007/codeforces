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

int n ;
vector < int > v[ MAXN ] ;
pair < int , int > dp[ MAXN ] ;
int depth[ MAXN ] ;
bool leaf[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    bool h = false ;
    int mx = 1 ;
    leaf[ vertex ] = true ;
    depth[ vertex ] = 0 ;
    int chk = -1 ;
    bool fl = false ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        leaf[ vertex ] = false ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
        mx = max ( mx , dp[ v[ vertex ][ i ] ].first ) ;
        if ( chk == -1 ) { chk = depth[ v[ vertex ][ i ] ] ^ 1 ; }
        if ( chk == depth[ v[ vertex ][ i ] ] ) {
            fl = true ;
        }
        if ( leaf[ v[ vertex ][ i ] ] == false ) {
            dp[ vertex ].second += dp[ v[ vertex ][ i ] ].second + 1 ;
        }
        else {
            if ( h == false ) {
                ++ dp[ vertex ].second ;
                h = true ;
            }
        }
    }
    if ( chk == -1 ) { chk = 0 ; }
    depth[ vertex ] = chk ;
    if ( fl == true ) { dp[ vertex ].first = 3 ; }
    else { dp[ vertex ].first = mx ; }
}

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
    int root = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].size ( ) > 1 ) { root = i ; break ; }
    }
    dfs ( root , -1 ) ;
    printf ( "%d %d\n" , dp[ root ].first , dp[ root ].second ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}