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

int n , s , e ;
int a[ 100007 ] ;
int p[ 100007 ] ;

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
    scanf ( "%d%d%d" , &n , &s , &e ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        p[ a[ i ] ] = i + 1 ;
        }
    }


void solve()
    {
    int x = e ;
    int ans = 0 ;
    while ( x != s )
        {
        x = p[ x ] ;
        ans ++ ;
        if ( ans > n ) { ans = -1 ; break ; }
        }
    printf ( "%d\n" , ans ) ;
    }