#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

int n ;
int b ;
int a[ 4007 ][ 4007 ] ;
map < int , int > m ;

void input ( ) ;
void solve ( ) ;

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }



void input ( )
    {
    scanf ( "%d" , &n ) ;
    int i , j ;
    int x ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &b ) ;
        if ( m[ b ] == 0 ) m[ b ] = i ;
        b = m[ b ] ;
        a[ b ][ b ] ++ ;
        for( j = 1 ; j <= n ; j ++ )
            {
            if ( a[ b ][ j ] % 2 == 0 && b != j ) a[ b ][ j ] ++ ;
            }
        for ( j = 1 ; j <= n ; j ++ )
            {
            if ( a[ j ][ b ] % 2 == 1 && b != j )a[ j ][ b ] ++ ;
            }
        }
    }

void solve ( )
    {
    int ans = 0 ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        for ( j = 1 ; j <= n ; j ++ )
            {
            if ( ans < a[ i ][ j ] ) ans = a[ i ][ j ] ;
            }
        }
    printf ( "%d\n" , ans ) ;
    }