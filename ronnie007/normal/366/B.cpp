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

int n , k ;
int a[ 100007 ] ;
int mn = 0 ;

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
    int i ;
    int x ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        mn += x ;
        a[ i%k ] += x ;
        }
    mn += 27 ;
    }


void solve()
    {
    int i ;
    for ( i = 0 ; i < k ; i ++ )
        {
        if ( mn > a[ i ] ) mn = a[ i ] ;
        }
    for ( i = 0 ; i < k ; i ++ )
        {
        if ( mn == a[ i ] )
            {
            printf ( "%d\n" , i + 1 ) ;
            return  ;
            }
        }
    }