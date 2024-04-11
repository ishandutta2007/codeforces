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


int n , k ;
int a[ 100007 ] ;

void input();
void solve();



int main()
    {
    input();
    solve();
    return 0;
    }




void input()
    {
    scanf ( "%d%d" , &n , &k ) ;
    }


void solve()
    {
    int i ;
    if ( k == n  )
        {
        printf ( "-1\n" ) ;
        return  ;
        }
    for ( i = n ;  i > n - k  ; i -- )
        {
        a[ i ] = i  ;
        }
    int x = 1 ;
    for ( i = 2 ; i <= n - k ; i += 2 )
        {
        a[ i - 1 ] = i  ;
        a[ i ] = i - 1 ;
        }
    if ( ( n - k ) % 2 == 1 )
        {
        a[ n - k  ] =  a[ 1 ] ;
        a[ 1 ] = n - k  ;

        }
    for ( i = 1 ; i <= n ; i ++ )
        {
        printf ( "%d " , a[ i ] ) ;
        }
    printf ( "\n" ) ;
    }