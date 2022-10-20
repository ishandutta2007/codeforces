#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std ;

int n , m ;
vector < string > v ;
int bestdist = 0 ;
int dist ;
int tp = 0 ;
int used[ 2007 ][ 2007 ] ;

vector < pair < int , int > > b ;


void dfs ( int  x , int y , int sx , int sy ) {
    dist = 0 ;
    while ( v[ x ][ y ] != '#' ) {
        used[ x ][ y ] = 1 ;
        if ( v[ x ][ y ] == '^' ) x -- ;
        else if ( v[ x ][ y ] == '<' ) y -- ;
        else if ( v[ x ][ y ] == '>' ) y ++ ;
        else x ++ ;
        if ( x == sx && y == sy ) {
            printf ( "-1\n" ) ;
            exit ( 0 ) ;
        }
        dist ++ ;
    }
    if ( dist < bestdist ) return ;
    if ( dist > bestdist ) b.clear ( ) ;
    bestdist = dist ;
    b.push_back ( make_pair ( sx , sy ) ) ;
}


void input ( ) {
    int i , j ;
    string p ;
    cin >> n >> m ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> p ;
        v.push_back ( p ) ;
    }
}


bool chk ( int ind1 , int ind2 ) {

    int x , y ;
    int x1 , y1 ;
    x = b[ ind1 ].first ;
    y = b[ ind1 ].second  ;
    x1 = b[ ind2 ].first ;
    y1 = b[ ind2 ].second  ;

    while ( v[ x ][ y ] != '#' ) {
        if ( x == x1 && y == y1 ) return false ;
        if ( v[ x ][ y ] == '^' ) x -- ;
        else if ( v[ x ][ y ] == '<' ) y -- ;
        else if ( v[ x ][ y ] == '>' ) y ++ ;
        else x ++ ;

        if ( v[ x1 ][ y1 ] == '^' ) x1 -- ;
        else if ( v[ x1 ][ y1 ] == '<' ) y1 -- ;
        else if ( v[ x1 ][ y1 ] == '>' ) y1 ++ ;
        else x1 ++ ;
        if ( v[ x ][ y ] == '#' ) continue ;
        if ( x == x1 && y == y1 ) return false ;
    }
    return true ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            if ( ( used[ i ][ j ] == 0 ) && v[ i ][ j ] != '#' ) {
                dfs ( i , j , i , j ) ;
            }
        }
    }
    if ( bestdist == 0 ) {
        printf ( "0\n" ) ;
        return  ;
    }
    for ( i = 0 ; i < b.size ( ) ; i ++ ) {
        for ( j = i + 1  ; j < b.size ( ) ; j ++ ) {
            if ( chk( i , j ) == true ) {
            printf ( "%d\n" , 2 * bestdist ) ;
            return  ;
            }
        }
    }
    printf ( "%d\n" , 2 * bestdist - 1 ) ;
}

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }