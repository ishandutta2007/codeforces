#include<iostream>
#include<stdio.h>
using namespace std ;


int n , m ;
char a[ 5007 ][ 5007 ] ;

int t[ 5007 ] ;
int br[ 5007 ] ;

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
    scanf ( "%d%d\n" , &n , &m ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        gets ( a[ i ] ) ;
        }
    }


void solve ( )
    {
    int i , j ;
    int ans = 0 ;
    for ( j = m - 1 ; j >= 0 ; j -- )
        {
        for ( i = 0 ; i <= 5000 ; i ++ )
            {
            br[ i ] = 0 ;
            }
        for ( i = 0 ; i < n ; i ++ )
            {
            if ( a[ i ][ j ] == '0' ) t[ i ] = 0  ;
            else t[ i ] ++ ;
            br[ t[ i ] ] ++ ;
            }

        for ( i = 5000 ; i >= 0 ; i -- )
            {
            br[ i ] += br[ i + 1 ] ;
            }
        for ( i = 0 ; i <= 5000 ; i ++ )
            {
            if ( ans < i * br[ i ] ) ans = i * br[ i ] ;
            }
        }
    printf ( "%d\n" , ans ) ;
    }