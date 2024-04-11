#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , m ;
int k[ 107 ] ;
int l[ 107 ][ 107 ] ;
int emp[ 107 ][ 107 ] ;
vector < int > v[ 107 ] ;
int used[ 107 ] ;
bool fl = false ;

void dfs ( int vertex ) {
    int i ;
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs ( v[ vertex ][ i ] ) ;
        }
    }
}


void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j , t ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &k[ i ] ) ;
        if ( k[ i ] != 0 ) fl = true ;
        for ( j = 0  ; j < k[ i ] ; j ++ ) {
            scanf ( "%d" , &l[ i ][ j ] ) ;
            emp[ i ][ l[ i ][ j ] ] = 1 ;
        }
        for ( j = i - 1 ; j >= 0 ; j -- ) {
            for ( t = 0 ; t < k[ i ] ; t ++ ) {
                if ( emp[ j ][ l[ i ][ t ] ] == 1 ) {
                    v[ i ].push_back ( j ) ;
                    v[ j ].push_back ( i ) ;
                }
            }
        }
    }
}

void solve ( ) {
    int ans = 0 ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            ans ++ ;
            dfs ( i ) ;
        }
    }
    if ( fl == false ) printf ( "%d\n" , ans ) ;
    else printf ( "%d\n" , ans - 1 ) ;
}