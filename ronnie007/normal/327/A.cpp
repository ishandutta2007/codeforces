#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n;
int a[ 107 ];


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
    scanf ( "%d", &n );
    int i;
    for ( i = 0 ; i < n ;  i ++ )
        {
        scanf( " %d", &a[ i ] );
        }
    }

void solve()
    {
    int br = 0;
    int mx = 0;
    int i , j, t;
    for ( i = 0 ; i < n ; i ++ )
        {
        br = 0 ;
        for ( j = i ; j < n ; j ++ )
            {
            br = 0 ;
            for ( t = 0 ; t < i ; t ++ ) if ( a[ t ] == 1 ) br ++ ;
            for ( t = j + 1 ; t < n ; t ++ ) if ( a[ t ] == 1 ) br ++ ;
            for ( t = i ; t <= j ; t ++ ) if ( a[ t ] == 0 ) br ++ ;
            if ( br > mx ) mx = br ;
            }
        }
    printf("%d\n",mx  );
    }