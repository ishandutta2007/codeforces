#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;



int n ;
int a[ 100007 ] ;
int b[ 100007 ] ;

void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }




void input()
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%d" , &a[ i ] , &b[ i ] ) ;
        }
    }


void solve()
    {
    int i , j ;
    int l , r ;
    int mid ;
    int p ;
    for ( i = 0 ; i < n ; i ++ )
        {
        l = 0 ;
        r = n - 1 ;
        while ( r - l > 1 )
            {
            mid = ( r + l ) / 2 ;
            if ( b[ mid ] > a[ i ] ) r = mid ;
            else l = mid ;
            }
        while ( b[ l ] < a[ i ] )
            {
            if ( l == n - 1 ) break ;
            l ++ ;
            }
        p = l + i + 1 ;
        if ( b[ l ] < a[ i ] ) p ++ ;
        if ( p <= n ||  i < n / 2 ) cout << "1" ;
        else cout << "0" ;
        }
    cout << "\n" ;


    for ( i = 0 ; i < n ; i ++ )
        {
        l = 0 ;
        r = n - 1 ;
        while ( r - l > 1 )
            {
            mid = ( r + l ) / 2 ;
            if ( a[ mid ] > b[ i ] ) r = mid ;
            else l = mid ;
            }
        while ( a[ l ] < b[ i ] )
            {
            if ( l == n - 1 ) break ;
            l ++ ;
            }
        p =  l + 1  + i ;
        if ( a[ l ] < b[ i ] ) p ++ ;
        ///cout << p << "\n" ;
        if ( p <= n || i < n / 2  ) cout << "1" ;
        else cout << "0" ;
        }
    cout << "\n" ;
    }