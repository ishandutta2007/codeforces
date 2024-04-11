#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;

#define MAXN 300007

int n , m , k ;

int par[ MAXN ] ;
int rnk[ MAXN ] ;
int diam[ MAXN ] ;
int used[ MAXN ] ;
int dist[ MAXN ] ;
pair < int , int > p ;

vector < int > v[ MAXN ] ;

int find ( int x ) {
    if ( par[ x ] == -1 ) return x ;
    int ret = find ( par[ x ] ) ;
    par[ x ] = ret ;
    return ret ;
}

void unite ( int x , int y , bool fl ) {
    int e1 = find ( x ) ;
    int e2 = find ( y ) ;
    if ( e1 != e2 ) {
        if ( rnk[ e1 ] >= rnk[ e2 ] ) {
            par[ e2 ] = e1 ;
            if ( rnk[ e1 ] == rnk[ e2 ] ) rnk[ e1 ] ++ ;
            if ( fl == true ) {
                diam[ e1 ] = max ( diam[ e2 ] , max ( diam[ e1 ] , 1 + diam[ e1 ] / 2 + diam[ e2 ] / 2 + diam[ e1 ] % 2 + diam[ e2 ] % 2 ) ) ;
            }
        }
        else {
            par[ e1 ] = e2 ;
            if ( fl == true ) {
                diam[ e2 ] =max ( diam[ e1 ] ,  max ( diam[ e2 ] , 1 + diam[ e1 ] / 2 + diam[ e2 ] / 2 + diam[ e1 ] % 2 + diam[ e2 ] % 2 ) ) ;
            }
        }
    }
}


void dfs ( int vertex , int par , int depth ) {
    int i , sz ;
    sz = v[ vertex ].size ( ) ;
    used[ vertex ] = 1 ;
    if ( p.first < depth ) {
        p.first = depth ;
        p.second = vertex ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] != par ) {
            dfs ( v[ vertex ][ i ] , vertex , depth + 1 ) ;
        }
    }
}

void input ( ) ;
void solve ( ) ;

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= n ; i ++ ) par[ i ] = -1 ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        unite ( x , y , false ) ;
    }
}

void solve ( ) {
    int i ;
    int x , y ;
    int e ;

    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            p.first = -1 ;
            dfs ( i , -1 , 0 ) ;
            p.first = -1 ;
            dfs ( p.second , -1 , 0 ) ;
            e = find ( i ) ;
            diam[ e ] = p.first ;
        }
    }
    int t ;
    while ( k > 0 ) {
        k -- ;
        scanf ( "%d" , &t ) ;
        if ( t == 1 ) {
            scanf ( "%d" , &x ) ;
            e = find ( x ) ;
            printf ( "%d\n" , diam[ e ] ) ;
        }
        else {
            scanf ( "%d%d" , &x , &y ) ;
            unite ( x , y , true ) ;
        }
    }
}