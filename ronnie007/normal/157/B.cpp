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
int r[ 107 ] ;

#define PI M_PI

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
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &r[ i ] ) ;
        }
    sort ( r , r + n ) ;
    }


void solve()
    {
    int i ;
    int x = 0 ;
    for ( i = n - 1 ; i >= 0 ; i -= 2 )
        {
        if ( i > 0 ) x += ( r[ i ] * r[ i ] - r[ i - 1 ] * r[ i - 1 ] ) ;
        }
    if ( n % 2 == 1 ) x += r[ 0 ] * r[ 0 ] ;
    printf ( "%lf\n" , PI * x ) ;
    }