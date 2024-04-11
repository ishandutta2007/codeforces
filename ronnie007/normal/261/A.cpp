#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


int n ;
int m ;
int a[ 100007 ] ;
int mn = 100007 ;


void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }


void input ( )
    {
    scanf ( "%d" , &m ) ;
    int i ;
    int x ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        if ( mn > x ) mn = x ;
        }
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    }

void solve ( )
    {
    int i = n - 1 ;
    int ans = 0 ;
    int j ;
    while ( i >= 0 )
        {
        for ( j = 0 ; j < mn && i - j >= 0 ; j ++ )
            {
            ans += a[ i -  j ] ;
            }
        i -= j ;
        if ( i >= 0 ) i -- ;
        if ( i >= 0 ) i -- ;
        }
    printf ( "%d\n" , ans ) ;
    }