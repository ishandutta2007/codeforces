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
int x[ 100007 ] ;


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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        x[ a[ i ] ] = i ;
        }
    }


void solve()
    {
    int i ;
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] == i ) ans ++ ;

        }
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( i != a[ i ] && x[ i ] == a[ i ] )
            {
            ans = ans + 2 ;
            break ;
            }
        }
    if ( i == n )
        {
        if ( ans != n ) ans ++ ;
        }
    printf ( "%d\n" , ans ) ;
    }