#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


string s ;
int m ;
int l ;
int ans[ 1007 ];
int used[ 17 ][ 17 ][ 1007 ];


void dfs ( int i , int j , int k )
    {
    int b;
    used[ i ][ j ][ k ] = 1;

    if( k == m )
        {
        l = 1 ;
        return ;
        }

    for( b = i + 1 ; b < 11 ; b ++ )
        {
        if( b != j && s[ b - 1 ] == '1' && used[ b - i ][ b ][ k + 1 ] == 0 )
            {
            ans[ k ] = b;
            dfs( b - i , b , k + 1 );
            if( l == 1 )return;
            }
        }
    }




int main()
    {
    cin >> s >> m ;
    dfs ( 0 , 0 , 0 );
    if( l == 0 )
        {
        printf ( "NO\n" ) ;
        return 0;
        }
    printf ( "YES\n" ) ;
    int i ;
    for ( i = 0 ; i < m ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" );
    return 0;
    }