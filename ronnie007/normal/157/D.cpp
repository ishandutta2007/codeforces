#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n , m ;
int a[ 100007 ] ;
int pos[ 100007 ] ;
int neg[ 100007 ] ;
int used[ 100007 ] ;
int cnt ;
int p ;


void input();
void solve();



int main()
    {
    input();
    solve() ;
    return 0;
    }


void input()
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    }



void solve ( )
    {
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] < 0 )
            {
            neg[ -a[ i ] ] ++ ;
            cnt ++ ;
            }
        else pos[ a[ i ] ] ++ ;
        }
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( pos[ i ] + cnt - neg[ i ] == m )
            {
            used[ i ] = 1 ;
            p ++ ;
            }
        }

    for ( i = 0 ; i < n ; i ++ )
        {
        if( a[ i ] > 0)
            {
            if (!used[ a[ i ] ]  ) printf ( "Lie\n" ) ;
            else if ( p == 1 ) printf ( "Truth\n" ) ;
            else printf ( "Not defined\n" ) ;
            }
        else
            {
            a[ i ] = -a[ i ];
            if ( !used[ a[ i ] ]  ) printf ( "Truth\n" ) ;
            else if ( p == 1 ) printf ( "Lie\n" ) ;
            else printf ( "Not defined\n" ) ;
            }
        }
    }