#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , k ;


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
    int i , j ;
    int x = k - ( n - 1 ) ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        for ( j = 1 ; j <= n ; j ++ )
            {
            if ( i != j ) printf ( "1 " ) ;
            else printf ( "%d " , x ) ;
            }
        printf ( "\n" ) ;
        }
    }