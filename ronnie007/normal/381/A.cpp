#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n ;
int a[ 1107 ] ; 

 

void input ( ) ;
void solve ( ) ;

int main ( ) 
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( ) 
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) 
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    }

void solve ( ) 
    {
    int l , r ;
    int ans1 = 0 ; 
    int ans2 = 0 ; 
    l = 0 ; 
    r = n - 1 ;
    int p = 1 ; 
    while ( l <= r ) 
        {
        if ( a[ l ] > a[ r ] ) 
            {
            if ( p == 1 ) ans1 += a[ l ] ; 
            else ans2 += a[ l ] ; 
            l ++ ;
            p = 3 - p ; 
            }
        else
            {
            if ( p == 1 ) ans1 += a[ r ] ; 
            else ans2 += a[ r ] ; 
            r -- ;
            p = 3 - p ; 
            }
        }
    printf ( "%d %d\n" , ans1 , ans2 ) ;
    }