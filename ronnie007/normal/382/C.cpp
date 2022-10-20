#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n ;
int a[ 100007 ] ; 

vector < int > v ;
vector < int > ans ;

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
    sort ( a , a + n ) ;
    }

void solve ( ) 
    {
    int i ;
    if ( n == 1 ) 
        {
        printf ( "-1\n" ) ;
        return  ;
        }
    if ( n == 2 )
        {
        if ( ( a[ 1 ] - a[ 0 ] ) % 2 == 1 ) 
            {
            v.push_back ( a[ 0 ] - ( a[ 1 ] - a[ 0 ] ) ) ;
            v.push_back ( a[ 1 ] + ( a[ 1 ] - a[ 0 ] ) ) ;
            
            }
        else
            {
            v.push_back ( a[ 0 ] - ( a[ 1 ] - a[ 0 ] ) ) ;
            v.push_back ( a[ 1 ] + ( a[ 1 ] - a[ 0 ] ) ) ;
            v.push_back ( a[ 0 ] + ( a[ 1 ] - a[ 0 ] ) / 2 ) ;
            }
            if ( v.size ( ) == 0 )
                {
                printf ( "0\n" ) ;
                return  ; 
                }
            sort ( v.begin ( ) , v.end ( ) ) ;
            ans.push_back ( v[ 0 ] ) ;
            for ( i = 1 ; i < v.size ( ) ; i ++ ) 
                {
                if ( v[ i ] != v[ i - 1 ] ) ans.push_back ( v[ i ] ) ;
                }
            printf ( "%d\n" , ans.size ( ) ) ;

            for ( i = 0 ; i < ans.size ( ) ; i ++ ) 
                {
                printf ( "%d " , ans[ i ] ) ;
                }
            printf ( "\n" ) ;       
        return ;
        }
    int ch = a[ 1 ] - a[ 0 ] ;
    int br = 0 ;
    for ( i = 0 ; i < n - 1 ; i ++ ) 
        {
        if ( a[ i + 1 ] - a[ i ] != ch ) br ++ ;
        }
    int br1 = 0 ; 
    for ( i = 0 ; i < n - 1 ; i ++ ) 
        {
        if ( a[ 2 ] - a[ 1 ] != a[ i + 1 ] - a[ i ]  ) br1 ++ ;
        }

    if ( br == n - 2 )
        {

        if ( br1 != 1 ) 
            {
            printf ( "0\n" ) ;
            return  ;
            }
        if ( br == 1 ) 
            {
            if ( ch > ( a[ 2 ] - a[ 1 ] ) ) ch = a[ 2 ] - a[ 1 ] ;
            }
        else
            {
            ch = a[ 2 ] - a[ 1 ] ;
            br = 1 ; 
            }
        }
    if ( br > 1 ) 
        {
        printf ( "0\n" ) ;
        return ;
        }
    v.clear ( ) ;
    if ( br == 0 )
        {
        v.push_back ( a[ 0 ] - ch ) ;
        v.push_back ( a[ n - 1 ] + ch ) ;
        }
    else
        {
        for ( i = 0 ; i < n - 1 ; i ++ ) 
            {
            if ( a[ i + 1 ] - a[ i ] != ch ) break ;
            }       
        if ( a[ i + 1 ] - a[ i ] == ch * 2 )
            {
            v.push_back ( a[ i ] + ch ) ;
            }
        }
    if ( v.size ( ) == 0 )
        {
        printf ( "0\n" ) ;
        return  ; 
        }
    sort ( v.begin ( ) , v.end ( ) ) ;
    ans.push_back ( v[ 0 ] ) ;
    for ( i = 1 ; i < v.size ( ) ; i ++ ) 
        {
        if ( v[ i ] != v[ i - 1 ] ) ans.push_back ( v[ i ] ) ;
        }
    printf ( "%d\n" , ans.size ( ) ) ;

    for ( i = 0 ; i < ans.size ( ) ; i ++ ) 
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    }