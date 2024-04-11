#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
using namespace std;

int n , m , p ;
int c ;
int a[ 200007 ] ;
int b[ 200007 ] ;
int used[ 200007 ] ;

map < int , int > t ;
map < int , int > t1 ;
vector < int > v ;

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
    scanf ( "%d%d%d" , &n , &m , &p ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d" , &b[ i ] ) ;
        if ( t1[ b[  i ] ] == 0 ) c ++ ;
        t1[ b[ i ] ] ++ ;
        }
    }

void solve ( )
    {
    int i , j ;
    int l , r ;
    int ans = 0 ;
    int br = 0 ;
    for ( i = 0 ; i < p ; i ++ )
        {
        br = c ;
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( i + p * j >= n ) break ;
            t[ a[ i + p * j ] ] ++ ;
            if ( t[ a[ i + p * j ] ] == t1[ a[ i + p  * j ] ]  ) br -- ;
            if ( t[ a[ i + p * j ] ] == t1[ a[ i + p  * j ] ]  + 1 && t1[ a[ i + p  * j ] ] != 0 ) br ++ ;
            }
        if ( j != m ) break ;
        for ( j = m ; i + j * p < n ; j ++ )
            {
            if ( br == 0 && used[ i + p * ( j - m ) + 1 ] == 0 )
                {
                ans ++ ;
                v.push_back ( i + p * ( j - m ) + 1 ) ;
                used[ i + p * ( j - m ) + 1 ] = 1 ;
                }
            t[ a[ i + p * ( j - m )  ] ] -- ;
            if ( t[ a[ i + p * ( j - m )  ] ] == t1[ a[ i + p * ( j - m )  ] ]  && t1[ a[i + p * ( j - m ) ] ] != 0 ) br -- ;
            if ( t[ a[ i + p * ( j - m )  ] ] == t1[ a[ i + p * ( j - m )  ] ] - 1 ) br ++ ;

            t[ a[ i + p * j  ] ] ++ ;
            if ( t[ a[ i + p * j   ] ] == t1[ a[ i + p * j  ] ] && t1[ a[ i + p  * j ] ] != 0 ) br -- ;
            if ( t[ a[ i + p * j   ] ] == t1[ a[ i + p * j  ] ] + 1  && t1[ a[ i + p  * j ] ] != 0 ) br ++ ;
            }
        if ( br == 0 && used[ i + p * ( j - m ) + 1 ] == 0 )
            {
            ans ++ ;
            v.push_back ( i + p * ( j - m ) + 1 ) ;
            used[ i + p * ( j - m ) + 1 ] = 1 ;
            }
        t.clear ( ) ;
        }
    sort ( v.begin ( ) , v.end ( ) ) ;
    printf ( "%d\n" , ans ) ;
    ///printf ( "%d " , v[ 0 ] ) ;
    for ( i = 0 ; i < ans ; i ++ )
        {
        ///if ( v[ i ] != v[ i - 1 ] )
        printf ( "%d " , v[ i ] ) ;
        }
    printf ( "\n" ) ;
    }