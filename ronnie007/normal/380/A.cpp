#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int  n , m ;
int a[ 200107 ] ; 

long long sz = 0 ; 
long long INIT_SZ = 0 ; 

int lst ; 

struct command
    {
    int type ;
    int x , y ; 
    };
 
vector < struct command > v ;
 

void input ( ) ;
void solve ( ) ;

void getans ( long long k ) 
    {
    while( k < sz  ) 
        {
        lst -- ;
        if ( v[ lst ].type == 1 ) sz -- ;
        else sz -= v[ lst ].x * v[ lst ].y ;
        }
    ///printf ( "-----------%d\n", sz ) ;
    while ( 1 ) 
        {
        if ( v[ lst ].type == 1 ) 
            {
            if ( k == sz ) 
                {
                printf ( "%d " , v[ lst ].x ) ;
                sz ++ ;
                lst ++ ;
                return ;
                }
            sz ++ ;
            }
        else
            {
            if ( sz + v[ lst ].x * v[ lst ].y - 1 >= k )
                {
                printf ( "%d " , a[ ( ( k - sz ) % v[ lst ].x ) ] ) ;
                sz = sz + v[ lst ].x * v[ lst ].y ;
                lst ++ ;
                return ;
                } 
            sz = sz + v[ lst ].x * v[ lst ].y ;     
            }
        lst ++ ;
        }
    }

int main ( ) 
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( ) 
    {
    scanf ( "%d" , &n ) ;
    int i , j ;
    v.resize ( n ) ;
    lst = -1 ; 
    for ( i = 0 ; i < n ; i ++ ) 
        {
        scanf ( "%d" , &v[ i ].type ) ; 
        if ( v[ i ].type == 1 ) 
            {
            scanf ( "%d" , &v[ i ].x ) ;
            if ( sz < 100007  && lst == i - 1 ) 
                {
                a[ sz ] = v[ i ].x ; 
                sz ++ ;
                lst = i ; 
                }
            }
        else
            {
            scanf ( "%d%d" , &v[ i ].x , &v[ i ].y ) ;
            while( v[ i ].y  > 0 )
                {
                if( sz > 100007 ) 
                    { 
                    break ;
                    }
                else
                    {
                    for ( j = 0 ; j < v[ i ].x ; j++ ) 
                        {
                        a[ sz + j ] = a[ j ] ; 
                        }
                    sz += v[ i ].x ;
                    v[ i ].y -- ;
                    ///lst = i ;
                    }
                }
            if ( v[ i ].y == 0 ) lst = i ;
            }
        }
    lst ++ ; 
    }

void solve ( ) 
    {
    int i ;
    long long k ;
    INIT_SZ = sz ;
    ///printf ( "INIT_SZ = %d \n" , sz ) ;
    scanf ( "%d" , &m ) ;
    for ( i = 0 ; i < m ; i ++ ) 
        {
        scanf ( "%I64d" , &k ) ;
        k -- ; 
        if ( k < INIT_SZ ) printf ( "%d " , a[ k ] ) ;
        else getans ( k ) ;
        }
    printf ( "\n" ) ;
    }