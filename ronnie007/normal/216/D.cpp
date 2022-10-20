#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std ;


int n ;
int ans = 0 ;
vector < int > v[ 1007 ] ;

int f ( int ind , int x )
    {
    int l , r ;
    l = 0 ;
    r = v[ ind ].size ( ) - 1 ;
    if ( v[ ind ][ r ] < x ) return r + 1  ;
    int mid ;
    while ( r - l > 1 )
        {
        mid = ( r + l ) / 2 ;
        if ( v[ ind ][ mid ] < x ) l = mid ;
        else r = mid ;
        }
    if ( v[ ind ][ l ] < x ) l ++ ;
    return l ;
    }


int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i , j ;
    int x ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        v[ i ].resize ( x ) ;
        for ( j = 0 ; j < x ; j ++ )
            {
            scanf ( "%d" , &v[ i ][ j ] ) ;
            }
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
        }
    int ind ;
    int p1 , p2 ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        for ( j = 0 ; j + 1 < v[ i ].size ( ) ; j ++ )
            {
            ind = i - 1 ;
            if ( ind == 0 ) ind = n ;
            p1 = f ( ind , v[ i ][ j + 1 ] ) - f ( ind , v[ i ][ j ] ) ;
            ind = i + 1 ;
            if ( ind == n + 1 ) ind = 1 ;
            p2 = f ( ind , v[ i ][ j + 1 ] ) - f ( ind , v[ i ][ j ] ) ;
            if ( p1 != p2 ) ans ++ ;
            }
        ///printf ( "%d\n" , ans ) ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }