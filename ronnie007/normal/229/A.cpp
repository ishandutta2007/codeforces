#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std ;

int n , m ;
vector < int > v[ 107 ] ;

void input ( ) ;
void solve ( ) ;

int getdist( int x , int y  )
    {
    ///cout << x << " " << y << "\n" ;
    int mn = 10000000 ;
    if ( mn > abs ( x - y ) ) mn = abs ( x - y ) ;
    if ( mn > y + ( m - x ) ) mn = y + ( m - x ) ;
    if ( mn > ( m - y ) + x ) mn = ( m - y ) + x ;
    return mn ;
    }

int main ( )
    {
    input ( ) ;
    return 0 ;
    }

void input ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    string a ;
    int fl = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a ;
        v[ i ].clear ( ) ;
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ j ] == '1' ) v[ i ].push_back ( j ) ;
            }
        if ( v[ i ].size (  ) == 0 ) fl = 1 ;
        }
    if ( fl == 1 ) { printf ( "-1\n" ) ; return ; }
    solve ( ) ;
    }

void solve ( )
    {
    int ans = 100000000;
    int t ;
    int i , j ;
    int l , r ;
    int mid ;
    int f , s ;
    int mn = 0 ;
    for ( i = 0 ; i < m ; i ++ )
        {
        t = 0 ;
        for ( j = 0 ; j < n ; j ++ )
            {
            l = 0 ;
            r = v[ j ].size ( ) - 1  ;
            while ( r - l > 1 )
                {
                mid = ( r + l ) / 2 ;
                if ( v[ j ][ mid ] > i ) r = mid ;
                else l = mid ;
                }
            if ( v[ j ][ l ] > i ) l = -1 ;
            else if ( v[ j ][ r ] <= i && l == r - 1 ) l ++ ;
            if ( l == -1 ) f = v[ j ].size ( ) - 1 ;
            else f = l ;
            if ( f == v[ j ].size ( ) - 1 ) s = 0 ;
            else s = f + 1 ;
            ///cout << f << " " << s << "\n" ;
            mn = min ( getdist ( i , v[ j ][ f ] ) , getdist ( i , v[ j ][ s ] ) ) ;
            t += mn ;
            }
        if ( ans > t ) ans = t ;
        }
    printf ( "%d\n" , ans ) ;
    }