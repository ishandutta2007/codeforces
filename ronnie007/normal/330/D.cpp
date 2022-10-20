#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std ;

int dx[ 7 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 7 ] = { 0 , 0 , 1 , -1 } ;


int n , m ;
string a[ 1007 ];
int d[ 1007 ][ 1007 ] ;

void bfs ( int x , int y )
    {
    queue < pair < int , int > > q ;
    pair < int , int > p ;
    p.first = x ;
    p.second = y ;
    d[ x ][ y ] = 1 ;
    while ( q.empty ( ) == false ) q.pop ( ) ;
    q.push ( p ) ;
    int i;
    while ( q.empty ( ) == false )
        {
        p = q.front ( ) ;
        q.pop ( ) ;
        for ( i = 0 ; i < 4 ; i ++ )
            {
            x = p.first + dx[ i ] ;
            y = p.second + dy[ i ] ;
            ///printf ( "%d %d\n" , x , y ) ;
            if ( x < 0 || y < 0 || x >= n || y >= m ) continue ;
            if ( a[ x ][ y ] != 'T' )
                {
                if ( d[ x ][ y ] == 0 )
                    {
                    d[ x ][ y ] = d[ p.first ][ p.second ] + 1 ;
                    q.push ( make_pair ( x , y ) ) ;
                    }
                }
            }
        }
    }

int main ( )
    {
    cin >> n >> m ;
    int i , j ;
    int s , t ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a[ i ] ;
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] == 'E' )
                {
                s = i ;
                t = j ;
                }
            }
        }
    bfs ( s , t ) ;

    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            ///printf ( "%d" , d[ i ][ j ] ) ;
            if ( a[ i ][ j ] == 'S' ) { s = i ; t = j ; }
            }
        ///printf ( "\n" ) ;
        }
    long long ans = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( i == s && j == t ) continue ;
            if ( d[ i ][ j ] <= d[ s ][ t ] && a[ i ][ j ] >= '0' && a[ i ][ j ] <='9' && d[ i ][ j ] != 0 ) ans += ( a[ i ][ j ] - '0' ) ;
            }
        }
    printf ( "%I64d\n", ans ) ;
    return 0 ;
    }