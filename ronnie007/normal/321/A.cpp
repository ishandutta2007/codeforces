#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;


bool check ( int x , int y , int dx , int dy )
    {
    ///cout << x << " " << y << "\n" ;
    if ( x > 0 && dx < 0 ) return false ;
    if ( x < 0 && dx > 0 ) return false ;
    if ( y > 0 && dy < 0 ) return false ;
    if ( y < 0 && dy > 0 ) return false ;

    if ( x == 0 && y == 0 ) return true ;
    if ( dx == 0 && x != 0 ) return false ;
    if ( dy == 0 && y != 0 ) return false ;
    if ( ( x == 0 && dx == 0 ) && y % dy == 0 ) return true ;
    if ( ( x == 0 && dx == 0 ) && y % dy != 0 ) return false ;
    if ( ( y == 0 && dy == 0 ) && x % dx == 0 ) return true ;
    if ( ( y == 0 && dy == 0 ) && x % dx != 0 ) return false ;
    if ( x % dx != 0 || y %dy != 0 ) return false ;
    if (x / dx != y / dy ) return false ;
    ///cout << x << " " << y << "\n" ;
    return true ;
    }


int main ( )
    {
    int x , y ;
    string a ;
    int dx = 0 ;
    int dy = 0 ;
    cin >> x >> y ;
    cin >> a ;
    int i ;
    int n = a.size ( ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] == 'U' ) dy ++ ;
        if ( a[ i ] == 'D' ) dy -- ;
        if ( a[ i ] == 'R' ) dx ++ ;
        if ( a[ i ] == 'L' ) dx -- ;
        }
    ///cout << dx <<" " << dy << "\n" ;
    int dx1 = 0 , dy1 = 0 ;

    for ( i = 0 ; i < n ; i ++ )
        {
        if ( check ( x - dx1 , y - dy1 , dx , dy ) == true )
            {
            printf ( "Yes\n" ) ;
            return 0;
            }
        if ( a[ i ] == 'U' ) dy1 ++ ;
        if ( a[ i ] == 'D' ) dy1 -- ;
        if ( a[ i ] == 'R' ) dx1 ++ ;
        if ( a[ i ] == 'L' ) dx1 -- ;
        if ( check ( x - dx1 , y - dy1 , dx , dy ) == true )
            {
            printf ( "Yes\n" ) ;
            return 0;
            }
        }
    printf ( "No\n" ) ;
    return 0 ;
    }