#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
using namespace std;


int dx[ 7 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 7 ] = { 0 , 0 , 1 , -1 } ;

int n , m , k ;

string a[ 507 ] ;
int used[ 507 ][ 507 ] ;


void input ( ) ;
void solve ( ) ;

void dfs ( int x , int y )
    {
    if ( k == 0 ) return ;
    int i , j ;
    int p , q ;
    int br = 0 ;
    ///cout << x << " " << y << "\n" ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        p = x + dx[ i ] ;
        q = y + dy[ i ] ;
        if ( p >= 0 && p < n && q >= 0 && q < m )
            {
            if ( a[ p ][ q ] == '.' && used[ p ][ q ] > used[ x ][ y ] + 1  )
                {
                used[ p ][ q ] = used[ x ][ y ] + 1 ;
                dfs ( p , q ) ;
                if ( k == 0 ) return ;
                if ( used[ p ][ q ] != -1 ) br ++ ;
                }
            }
        }
    if ( k == 0 ) return ;
    if ( br == 0 )
        {
        used[ x ][ y ] = -1 ;
        k -- ;
        }
    }

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }



void input ( )
    {
    cin >> n >> m >> k ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) cin >> a[ i ] ;
    }

void solve ( )
    {
    int i , j ;
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            used[ i ][ j ] = n * 1000 ;
            }
        }

    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] == '.' )
                {
                used[ i ][ j ] = 1 ;
                dfs ( i , j ) ;
                break ;
                }
            }
        if ( j != m ) break ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] == '#' ) cout << a[ i ][ j ] ;
            else
                {
                if ( used[ i ][ j ] == -1 ) cout << 'X' ;
                else cout << a[ i ][ j ] ;
                }
            }
        cout << "\n" ;
        }
    }