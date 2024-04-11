#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

int n , m ;
vector < int > v[ 107 ] ;
int ans = 0 ;
int used[ 107 ] ;
int cur ;

void dfs ( int vertex , int depth )
    {
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    int x ;
    for ( i = 0 ; i < v[ vertex ].size ( ) ; i ++ )
        {
        x = v[ vertex ][ i ] ;
        if ( x == cur && depth % 2 == 0 ) ans ++ ;
        if ( used[ x ] == 0 )
            {
            dfs ( x , depth + 1 ) ;
            }
        }
    }

int main ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        }
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( used[ i ] == 0 )
            {
            int j ;
            cur = i ;
            dfs ( i , 0 ) ;
            for ( j = 0 ; j < v[ i ].size ( ) ; j ++ ) if ( used[ v[ i ][ j ] ] % 2 == 0 ) ans ++ ;
            }

        }
    if ( ( n - ans ) % 2 == 1 ) ans ++ ;
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }