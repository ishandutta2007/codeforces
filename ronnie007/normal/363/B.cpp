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
int mn = 100000000 ;
int a[ 200007 ] ;
int s[ 200007 ] ;

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
    int i ;
    scanf ( "%d%d" , &n , &k ) ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        s[ i ] = s[ i - 1 ] + a[ i ] ;
        }
    }


void solve()
    {
    int i ;
    int ind = -1 ;
    for ( i = 1 ; i + k - 1 <= n ; i ++ )
        {
        if ( s[ i + k - 1 ] - s[ i - 1 ] < mn )
            {
            mn = s[ i + k - 1 ] - s[ i - 1 ] ;
            ind = i ;
            }
        }
    printf ( "%d\n" , ind  ) ;
    }