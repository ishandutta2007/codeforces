#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int n ;
int sz[ 107 ] ;
vector < int > v[ 107 ] ;

int main ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &sz[ i ] ) ;
        v[ i ].resize ( sz[ i ] ) ;
        for ( j = 0 ; j < sz[ i ] ; j ++ ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
        }
    }
    int ans1 = 0 , ans2 = 0 ;
    vector < int > v2 ;
    v2.clear ( ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < sz[ i ] / 2 ; j ++ ) {
            ans1 += v[ i ][ j ] ;
        }
        for ( j = 0 ; j < sz[ i ] / 2 ; j ++ ) {
            ans2 += v[ i ][ sz[ i ] - j - 1 ] ;
        }
        if ( sz[ i ] % 2 == 1 ) v2.push_back ( v[ i ][ sz[ i ] / 2 ] ) ;
    }
    int d = 1 ;
    sort ( v2.begin ( ) , v2.end ( ) ) ;
    for ( i = v2.size ( ) - 1 ; i >= 0 ; i -- ) {
        if ( d == 1 ) ans1 += v2[ i ] ;
        else ans2 += v2[ i ] ;
        d = 3 - d  ;
    }
    printf ( "%d %d\n" , ans1 , ans2 ) ;
    return 0 ;
}