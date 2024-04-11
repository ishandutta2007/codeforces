#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int t ;
string a[ 16 ] ;
int used[ 16 ][ 16 ] ;
int used1[ 16 ][ 16 ] ;

int dx[ 8 ] = { 2 , 2 , -2 , -2 } ;
int dy[ 8 ] = {2 , -2 , 2 , -2 } ;

void dfs ( int x , int y , int pos )
	{
	int i ;
	int newx ;
	int newy ;
	for ( i = 0 ; i < 4 ; i ++ )
		{
		newx = x + dx[ i ] ;
		newy = y + dy[ i ] ;
		if ( newx < 0 || newx >= 8 ) continue ;
		if ( newy < 0 || newy >= 8 ) continue ;
		if ( pos == 0 && used[ newx ][ newy ] != 0 ) continue ;
		if ( pos == 1 && used1[ newx ][ newy ] != 0 ) continue ;

		if ( pos == 0 )
			{
			used[ newx ][ newy ] = used[ x ][ y ] + 1 ;
			}
		else
			{
			used1[ newx ][ newy ] = used1[ x ][ y ] + 1 ;
			}
		dfs ( newx , newy , pos ) ;
		}
	}
void input();
void solve();


int main()
    {
    input();
    return 0;
    }


void input()
    {
	cin >> t ;
	int i ;
	while ( t > 0 )
		{
		for ( i = 0 ; i < 8 ; i ++ ) cin >> a[ i ] ;
		solve ( ) ;
		t -- ;
		}
    }

void solve()
	{
	int i , j ;
	int fl = 0 ;
	for ( i = 0 ; i < 8 ; i ++ )
		{
		for ( j = 0 ; j < 8 ; j ++ )
			{
			used[ i ][ j ] = 0 ;
			used1[ i ][ j ] = 0 ;
			}
		}
	///cout << "here\n" ;
	for ( i = 0 ; i < 8 ; i ++ )
		{
		for ( j = 0 ; j < 8 ; j ++ )
			{
			if ( a[ i ][ j ] == 'K' )
				{
				if ( fl == 0 ) used[ i ][ j ] = 1 ;
				else used1[ i ][ j ] = 1 ;
				dfs ( i , j , fl ) ;
				fl ++ ;
				}
			}
		}
	for ( i = 0 ; i < 8 ; i ++ )
		{
		for ( j = 0 ; j < 8 ; j ++ )
			{
			if ( used[ i ][ j ] != 0 && used1[ i ][ j ] != 0 && a[ i ][ j ] != '#' )
				{
				if ( used[ i ][ j ] % 2 == used1[ i ][ j ] % 2 )
					{
					printf ( "YES\n" ) ;
					return ;
					}
				}
			}
		}
	printf ( "NO\n" ) ;
	}