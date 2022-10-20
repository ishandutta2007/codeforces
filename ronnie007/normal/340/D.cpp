#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n ;
int a[ 1000007 ];
vector < int > v;


void f ( int x )
    {
    int l = 0 ;
    int r = v.size ( )  - 1 ;
    if ( v.size ( ) == 0  )
        {
        v.push_back ( x ) ;
        return ;
        }
    if ( x > v[ r ] ){ v.push_back ( x ) ; return ; }
    int mid ;
    while( r - l > 1 )
        {
        mid = ( r + l ) / 2 ;
        if ( v[ mid ] < x ) l = mid ;
        else r = mid ;
        }
    if ( v[ l ] < x ) l ++ ;
    ///if ( v[ l ] < x ) l ++ ;
    v[ l ] = x ;
    }


void input();
void solve();





int main()
    {
    input();
    solve() ;
    return 0;
    }


void input()
    {
    v.clear ( ) ;
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d", &a[ i ] ) ;
        f( a[ i ] ) ;
        }
    }


void solve ( )
    {
    printf ( "%d\n" , v.size ( )  ) ;
    }