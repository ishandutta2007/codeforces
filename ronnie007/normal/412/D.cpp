#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int n , m ;
vector < int > v[ 30007 ] ;
int used[ 30007 ] ;

void input ( ) ;
void solve ( ) ;

void dfs ( int vertex ) {
    int sz , i ;
    sz = v[ vertex ].size ( ) ;
    used[ vertex ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) dfs ( v[ vertex ][ i ]  ) ;
    }
    printf ( "%d " , vertex ) ;
}

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) dfs ( i ) ;
    }
    printf ( "\n" ) ;
}