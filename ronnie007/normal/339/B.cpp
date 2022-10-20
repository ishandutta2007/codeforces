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


int n , m ;
int a[ 100007 ] ;
long long ans = 0;


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
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    }


void solve()
    {
    int i ;
    ans = a[ 0 ] - 1 ;
    for ( i = 1 ; i < m ; i ++ )
        {
        if ( a[ i ] < a[ i - 1 ] ) a[ i ] += n ;
        ans = ans + a[ i ] - a[ i - 1 ] ;
        if ( a[ i ] > n ) a[ i ] -= n ;
        }
    printf ( "%I64d\n" , ans ) ;
    }