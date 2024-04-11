#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

int n ;
int a[ 307 ] ;
int b[ 307 ] ;

vector < pair < int , int > > v ;

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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &b[ i ] ) ;
        }
    }

void solve ( )
    {
    int i ;
    int j ;
    int t ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( b[ i ] != a[ i ] )
            {
            for ( j = i + 1 ; j < n ; j ++ )
                {
                if ( b[ j ] == a[ i ] ) break ;
                }
            for ( t = j ; t > i ; t -- )
                {
                swap ( b[ t - 1 ] , b[ t ] ) ;
                v.push_back ( make_pair ( t - 1 , t ) ) ;
                }
            }
        }
    printf ( "%d\n" , v.size ( ) ) ;
    for ( i = 0 ; i < v.size ( ) ; i ++ )
        {
        printf ( "%d %d\n" , v[ i ].first + 1 , v[ i ].second + 1 ) ;
        }
    }