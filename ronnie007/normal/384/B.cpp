#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


/// 0 - ascending
/// 1 - descending

vector < pair < int , int > > v ;
int n ;
int m ;
int dir ;
int a[ 1007 ][ 107 ] ;

void input ( ) ;
void solve ( ) ;

int main ( ) 
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( ) 
    {
    scanf ( "%d%d%d" , &n , &m , &dir ) ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            }
        }
    }

void solve ( ) 
    {
    int ind = 0 ;
    int i ;
    int j ;
    pair < int , int > c ;
    while ( ind != n ) {
        for ( i = 0 ; i < m ; i ++ ) {
            for ( j = i + 1 ; j < m ; j ++ ) {
                if ( dir == 0 ) {
                    if ( a[ ind ][ i ] > a[ ind ][ j ] ) {
                        c.first = i ;
                        c.second = j ;
                        break ;
                        }
                    }
                else {
                    if ( a[ ind ][ i ] < a[ ind ][ j ] ) {
                        c.first = j ;
                        c.second = i ;
                        break ;
                        }
                    }
                }
            if ( j != m ) break ;
            }
        if ( i == m ) ind ++ ;
        else {
            for ( i = 0 ; i < n ; i ++ ) {
                if ( a[ i ][ c.first ] > a[ i ][ c.second ] ) {
                    swap ( a[ i ][ c.first ] , a[ i ][ c.second ] ) ;
                    }
                }
            v.push_back ( c ) ;
            }
        }
    printf ( "%d\n" , v.size ( ) ) ;
    for ( i = 0 ; i < v.size ( ) ; i ++ ) 
        {
        printf ( "%d %d\n" , v[ i ].first + 1 , v[ i ].second + 1 ) ;
        }
    }