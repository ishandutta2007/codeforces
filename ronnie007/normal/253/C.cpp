#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
using namespace std;

#define inf 1000000007

int n ;
int m ;
int a[ 107 ] ;
int dist[ 107 ][ 100007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    m = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( m  < a[ i ] ) m = a[ i ] ;
    }
    m ++ ;
}

void solve ( ) {
    int sx , sy , ex , ey ;
    scanf ( "%d%d" , &sx , &sy ) ;
    scanf ( "%d%d" , &ex , &ey ) ;
    sx -- ;
    sy -- ;
    ex -- ;
    ey -- ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            dist[ i ][ j ] = inf ;
        }
    }
    dist[ sx ][ sy ] = 0 ;
    queue < pair < int , int > > q ;
    pair < int , int > p ;
    q.push ( make_pair ( sx , sy ) ) ;
    int x , y ;
    int x1 , y1 ;
    while ( q.empty ( ) == false ) {
        p = q.front ( ) ;
        q.pop ( ) ;
        x = p.first ;
        y = p.second ;

        x1 = x - 1 ;
        y1 = y ;
        if ( x1 >= 0 ) {
            if ( y1 > a[ x1 ] ) y1 = a[ x1 ] ;
            if ( dist[ x1 ][ y1 ] == inf ) {
                dist[ x1 ][ y1 ] = dist[ x ][ y ] + 1 ;
                q.push ( make_pair ( x1 , y1 ) ) ;
            }
        }


        x1 = x + 1 ;
        y1 = y ;
        if ( x1 < n ) {
            if ( y1 > a[ x1 ] ) y1 = a[ x1 ] ;
            if ( dist[ x1 ][ y1 ] == inf ) {
                dist[ x1 ][ y1 ] = dist[ x ][ y ] + 1 ;
                q.push ( make_pair ( x1 , y1 ) ) ;
            }
        }


        x1 = x ;
        y1 = y - 1 ;
        if ( y1 >= 0 ) {
            if ( dist[ x1 ][ y1 ] == inf ) {
                dist[ x1 ][ y1 ] = dist[ x ][ y ] + 1 ;
                q.push ( make_pair ( x1 , y1 ) ) ;
            }
        }


        x1 = x ;
        y1 = y + 1 ;
        if ( y1 < a[ x ] + 1 ) {
            if ( dist[ x1 ][ y1 ] == inf ) {
                dist[ x1 ][ y1 ] = dist[ x ][ y ] + 1 ;
                q.push ( make_pair ( x1 , y1 ) ) ;
            }
        }
    }
    /*
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            if ( dist[ i ][ j ] == inf ) printf ( "-1 " ) ;
            else printf ( "%d " , dist[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
    */
    printf ( "%d\n" , dist[ ex ][ ey ] ) ;
}