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


int n ;
int a[ 500007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    freopen ( "input.txt" , "r" , stdin ) ;
    freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a , a + n ) ;
}


void solve ( )  {
    int i , l , r , mid ;
    int ans = n + 27 ;
    int cur ;
    int x ;
    for ( i = 0 ; i < n ; i ++ ) {
        x = 2 * a[ i ] ;
        l = 0 ;
        r = n - 1 ;
        while ( r - l > 1 ) {
            mid = ( r + l ) / 2 ;
            if ( a[ mid ] > x ) r = mid ;
            else l = mid ;
        }
        while ( l < n && a[ l ] <= x ) l ++ ;
        cur = i + ( n - l ) ;
        if ( ans > cur ) ans = cur ;
    }
    printf ( "%d\n" , ans ) ;
}