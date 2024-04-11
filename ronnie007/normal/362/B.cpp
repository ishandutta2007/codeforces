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
int a[ 3007 ] ;


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
    sort ( a , a + m ) ;
    int i ;
    for ( i = 2 ; i < m ; i ++ )
        {
        if ( a[ i ] == a[ i - 1 ] + 1 && a[ i - 1 ] == a[ i - 2 ] + 1 )
            {
            printf ( "NO\n" ) ;
            return  ;
            }
        }
    if ( a[ m - 1 ] == n || a[ 0 ] == 1 )
        {
        printf ( "NO\n" ) ;
        return  ;
        }
    printf ( "YES\n" ) ;
    }