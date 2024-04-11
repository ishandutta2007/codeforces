#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define n 9

int v ;
int dp[ 1000007 ] ;
    int ans[ 1000007 ] ;
int a[ 17 ] ;

void input ( ) ;
void solve ( ) ;

bool f ( string a , string b )
    {
    if ( a.size ( ) > b.size ( ) ) return true ;
    if ( b.size ( ) > a.size ( ) ) return false ;
    int i ;
    for ( i = 0 ; i < a.size ( ) ; i ++ )
        {
        if ( a[ i ] < b[ i ] ) return false ;
        if ( a[ i ] > b[ i ] ) return true ;
        }
    return true ;
    }

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d" , &v ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    }

void solve ( )
    {

    int i , j ;
    int mn = 10000000 ;
    int p ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( mn >= a[ i ] )
            {
            p = i ;
            mn = a[ i ] ;
            }
        }
    int s = v / mn ;
    if ( s == 0 )
        {
        printf ( "-1\n" ) ;
        return  ;
        }
    for ( i = 0 ; i < s ; i ++ )
        {
        ans[ i ] = p ;
        }
    v = v % mn ;
    ///cout << v ;
    for ( i = 9 ; i > p ; i -- )
        {
        for ( j = 0 ; j < s ; j ++ )
            {
            if ( ans[ j ] != p ) continue ;
            if ( v  >= ( a[ i ] - a[ p ] )  )
                {
                ans[ j ] = i ;
                v = v - a[ i ] + a[ p ]   ;
                }
            else break ;
            }
        }
    for ( i = 0 ; i < s ; i ++ )
        {
        printf ( "%d" , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    }