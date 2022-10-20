#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n ;
struct tuhla
    {
    int x , y , z , t ;
    };

struct tuhla a[ 7 ] ;

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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        scanf ( "%d%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].z , &a[ i ].t ) ;
        }
    }

void solve()
    {
    int i ;
    int cost = 0 ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        cost = 0 ;
        if ( a[ i ].x < a[ i ].y ) cost = a[ i ].x ;
        else cost = a[ i ].y ;
        if ( a[ i ].z < a[ i ].t ) cost += a[ i ].z ;
        else cost += a[ i ].t ;
        if ( cost <= n )
            {
            if ( a[ i ].x < a[ i ].y ) printf ( "%d %d %d\n" , i + 1 , a[ i ].x , n - a[ i ].x ) ;
            else printf ( "%d %d %d\n" , i + 1 , a[ i ].y , n - a[ i ].y ) ;
            return ;
            }
        }
    printf ( "-1\n" ) ;
    }