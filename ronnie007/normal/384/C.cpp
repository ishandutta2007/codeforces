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
int a[ 200007 ] ;

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
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        }
    }

void solve ( ) 
    {
    long long ans = 0 ;
    int br = 0 ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == 1 ) br ++ ;
        else ans += br ;
        }
    printf ( "%I64d\n" , ans ) ;
    }