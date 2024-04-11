#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , m , d ;
int a[ 107 ] ;
int ans = 0 ;

void input();
void solve();


int main()
    {
    input();
    solve ( ) ;
    return 0;
    }


void input()
    {
    scanf ( "%d%d" , &n , &d ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    scanf ( "%d" , &m ) ;
    sort ( a , a + n ) ;
    }

void solve()
    {
    int i ;
    if ( m <= n )
        {
        for ( i = 0 ; i < m ; i ++ )
            {
            ans += a[ i ] ;
            }
        }
    else
        {
        for ( i = 0 ; i < n ; i ++ )
            {
            ans += a[ i ] ;
            }
        ans -= ( m - n ) * d ;
        }
    printf ( "%d\n" , ans ) ;
    }