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

int n , m ;
int a[ 1500007 ] ;
int lft[ 300007 ] ;
int rght[ 300007 ] ;
int x[ 300007 ] ;
int lt = 1 ;

void input ( ) ;
void solve ( ) ;

void f ( int where  , int l , int r , int L , int R , int t )
    {
    ///printf ( "%d %d %d %d %d %d\n" , where , l , r , L , R , t ) ;
    if ( a[ where ] != 0 )
        {
        return ;
        }

    if ( l == L && r == R && a[ where ] == 0 )
        {
        a[ where ] = t ;
        return  ;
        }

    if ( 2 * where + 1  >= 2 * lt ) return ;
    ///cout << "here\n" ;
    int mid ;
    mid = ( L + R ) / 2 ;
    if ( l <= mid )
        {
        if ( r <= mid ) f( where * 2 , l , r , L , mid , t ) ;
        else f( where * 2 , l , mid , L , mid , t ) ;
        }
    if ( r > mid )
        {
        if ( l > mid  ) f( where * 2 + 1 , l , r , mid + 1  , R , t ) ;
        else f( where * 2 + 1 , mid + 1  , r , mid + 1  , R , t ) ;
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
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    lt = 1 ;
    int p ;
    while ( lt < n ) lt = lt * 2 ;

    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d%d" , &lft[ i ] , &rght[ i ] , &x[ i ] ) ;
        if ( x[ i ] != lft[ i ] ) f ( 1 , lft[ i ] , x[ i ] - 1  , 1 , lt , x[ i ] ) ;
        if ( x[ i ] != rght[ i ] ) f ( 1 , x[ i ] + 1  , rght[ i ]  , 1 , lt , x[ i ] ) ;
        }
    }

void solve ( )
    {
    int i ;
    int p ;
    for ( i = lt ; i < lt + n ; i ++ )
        {
        p = i ;
        while ( a[ p ] == 0 )
            {
            if ( p == 0 ) break ;
            p = p / 2 ;
            }
        if ( p == 0 ) printf ( "0 " ) ;
        else printf ( "%d " , a[ p ] ) ;
        }
    printf ( "\n" ) ;
    }