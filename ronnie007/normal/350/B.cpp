#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

int n ;
int a[ 100007 ] ;
int b[ 100007 ] ;
int r[ 100007 ] ;

vector < int > ans ;

int main ( )
    {
    int i , j ;
    int br = 0 ;
    int mx = 0 ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &b[ i ] ) ;
        b[ i ] -- ;
        r[ b[ i ] ] ++ ;
        }
    int x = 0 ;
    int st = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] == 1 )
            {
            x = b[ i ]  ;
            br = 1 ;
            while ( x != -1 && a[ x ] != 1 && r[ x ] == 1 )
                {
                x = b[ x ] ;
                br ++ ;
                }
            if ( br > mx ) { st = i ; mx = br ; }
            }
        }
    printf ( "%d\n" , mx ) ;
    ans.clear ( ) ;
    ans.push_back ( st ) ;
    x = b[ st ] ;
    while ( x != -1 && a[ x ] != 1 && r[ x ] == 1 )
        {
        ans.push_back ( x ) ;
        x = b[ x ] ;
        }
    for ( i = ans.size ( ) - 1 ; i >= 0 ; i -- )
        {
        printf ( "%d " , ans[ i ] + 1 ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }