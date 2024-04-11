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
int used[ 100007 ] ; 

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
    vector < int > ans ;
    ans.clear ( ) ;
    ans.push_back ( a[ 0 ] ) ;
    used[ 0 ] = 1 ;
    for ( i = 1 ; i < n ; i ++ ) 
        {
        if ( a[ i ] != a[ i - 1 ] ) 
            {
            used[ i ] = 1 ; 
            ans.push_back ( a[ i ] ) ;
            }
        }
    for ( i = n - 1 ; i >= 0 ; i -- ) 
        {
        if ( a[ i ] < ans[ ans.size ( ) - 1 ] && used[ i ] == 0 ) 
            {
            used[ i ] = 1 ;
            ans.push_back ( a[ i ] ) ;
            }
        }
    printf ( "%d\n" , ans.size ( ) ) ;
    for ( i = 0 ; i < ans.size ( ) ; i ++ ) 
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    }