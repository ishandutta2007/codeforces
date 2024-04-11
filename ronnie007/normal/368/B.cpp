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
int lst[ 100007 ] ;
int ans[ 100007 ] ;


void input();
void solve();

bool f ( int p1 , int p2 )
    {
    if ( p1 > p2 ) return true ;
    return false ;
    }

int main()
    {
    input();
    solve();
    return 0;
    }




void input()
    {
    int i , x ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        lst[ x ] = i + 1 ;
        }
    sort ( lst , lst + 100004 , f ) ;
    }


void solve()
    {
    int i ;
    int ind = 0 ;
    int br = 0 ;
    for ( i = n ; i >= 0 ; i -- )
        {
        if ( lst[ ind ] >= i )
            {
            ind ++ ;
            br ++ ;
            }
        ans[ i ] = br ;
        }
    int x ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        printf ( "%d\n" , ans[ x ] ) ;
        }
    }