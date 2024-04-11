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


#define eps 0.000000001

int n ;


struct point
    {
    int x , y ;
    };

struct point a[ 307 ] ;

void input();
void solve();

int det( struct point p1 , struct point p2 , struct point p3 ) ;


int main()
    {
    input();
    solve();
    return 0;
    }



int det( struct point p1 , struct point p2 , struct point p3 )
    {
    int k = p1.x * p2.y * 1 + p1.y * 1 * p3.x + 1 * p2.x * p3.y ;
    k-= p3.x * p2.y * 1 + p3.y * 1 * p1.x + 1 * p2.x * p1.y ;
    return k ;
    }


void input()
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
        }
    }


void solve()
    {
    int i , j , t ;
    int u ;
    int mx = 0 ;
    int mn = 0 ;
    double ans = 0 ;
    double k ;
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = i + 1 ; j < n ; j ++ )
            {
            mx = 0 ;
            mn = 0 ;
            for ( t = 0 ; t < n ; t ++ )
                {
                u = det( a[ i ] , a[ j ]  , a[ t ] ) ;
                if ( mx < u ) mx = u ;
                if ( mn > u ) mn = u ;
                }
            if ( mn == 0 || mx == 0 ) continue ;
            mn = 0 - mn ;
            k = double ( mx ) / 2 ;
            k += double ( mn ) / 2 ;
            if ( k - ans > eps ) ans = k ;
            }
        }
    printf ( "%lf\n" , ans ) ;
    }