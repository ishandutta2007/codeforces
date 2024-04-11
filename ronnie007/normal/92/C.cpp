#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

string a , b ;
int dp[ 10007 ][ 37 ] ;
int lst[ 37 ] ;


void precomputeDP ( )
    {
    int i , j ;
    for ( j = 0 ; j < 26 ; j ++ ) lst[ j ] = -1 ;
    for ( i = a.size ( ) - 1 ; i >= 0 ; i -- )
        {
        ///cout << " " << a[ i ] << "\n" ;
        lst[ a[ i ] - 'a' ] = i  ;
        for ( j = 0 ; j < 26 ; j ++ )
            {
            dp[ i ][ j ] = lst[ j ] ;
            }
        }
    }


bool f ( int t )
    {
    int i ;
    int pos = 0 ;
    int br = 1 ;
    ///cout << dp[ 2 ][ 0 ] << "\n" ;
    ///cout << " t = "  << t << "\n" ;
    for ( i = 0 ; i < b.size ( ) ; i ++ )
        {
        ///cout << pos << " " ;
        if ( pos < a.size ( ) ) pos = dp[ pos ][ b[ i ] - 'a' ] + 1 ;
        else {  pos = 0 ; }
        ///cout << pos << " " ;
        if ( pos == 0 ) { br ++ ; pos = dp[ 0 ][ b[ i ] - 'a' ] + 1 ;}
        ///cout << br << "\n" ;
        if ( dp[ 0 ][ b[ i ] - 'a' ] == -1 ) return false ;
        }
    return br <= t ;
    }

int main ( )
    {
    cin >> a >> b ;
    precomputeDP ( ) ;
    int l = 1 ;
    int r = b.size ( ) ;
    int mid = 0 ;
    while ( r - l > 1 )
        {
        mid = ( r + l ) / 2 ;
        if ( f( mid ) == true ) r = mid ;
        else l = mid ;
        }
    if ( f( l ) == false ) l ++ ;
    if ( f( l ) == false ) printf ( "-1\n" ) ;
    else printf ( "%d\n" , l ) ;
    return 0 ;
    }