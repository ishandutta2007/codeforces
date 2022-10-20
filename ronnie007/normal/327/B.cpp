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

int n;
int used[ 1300000 ];

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
    scanf ( "%d",&n);
    }


void solve()
    {
    int i;
    int j;
    for ( i = 2 ; i <= 1299709; i ++ )
        {
        if ( used[ i ] == 1 ) continue;
        for ( j = i + i; j <= 1299709; j += i )
            {
            used[ j ] = 1 ;
            }
        }
    int br = 0 ;
    for ( i = 2 ; i <= 1299709 ; i ++ )
        {
        if ( used[ i ] == 0 )
            {
            printf ( "%d ", i );
            br ++ ;
            if ( br == n ) break ;
            }
        }
    }