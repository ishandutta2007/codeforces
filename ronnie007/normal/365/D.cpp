#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
using namespace std;


int n ;
int d ;
int a[ 57 ] ;
int pos[ 500007 ] ;
vector < int > v ;


void input ( ) ;
void solve ( ) ;

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d%d" , &n , &d ) ;
    int i , j ;
    pos[ 0 ] = 1 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        for ( j = 500000 - a[ i ]  ; j >= 0  ; j -- )
            {
            if ( pos[ j ] == 1 ) pos[ j  + a[ i ] ] = 1 ;
            }
        }
    for ( i = 0 ; i <= 500000 ; i ++ )
        {
        if ( pos[ i ] == 1 ) v.push_back ( i ) ;
        }
    }

void solve ( )
    {
    int now = 0 ;
    int cur = 0 ;
    int days = 0 ;
    int i ;
    ///cout << v.size ( ) << "\n" ;
    for ( i = 0 ; i < v.size ( )  ; i ++ )
        {
        ///cout << v[ i ] << "\n" ;
        if ( v[ i ] - now <= d ) cur = v[ i ] ;
        else
            {
            if ( now != cur ) days ++ ;
            now = cur ;
            if ( v[ i ] - now <= d ) cur = v[ i ] ;
            else break ;
            }
        }
    if ( now != cur ) days ++ ;
    now = cur ;

    printf ( "%d %d\n" , now , days ) ;
    }