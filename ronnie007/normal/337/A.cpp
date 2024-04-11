#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , m ;
int a[ 57 ];


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
    scanf ( "%d%d", &m , &n ) ;
    int i ;
    for (i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d", &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    }

void solve()
    {
    int mn = 1000000 ;
    int i ;
    for ( i = 0 ; i + m - 1 < n ; i ++ )
        {
        if ( a[ i + m - 1 ] - a[ i ] < mn ) mn = a[ i + m - 1 ] - a[ i ] ;
        }
    printf ( "%d\n" , mn ) ;
    }