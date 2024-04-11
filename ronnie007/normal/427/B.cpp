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

int n , t , c ;
int a[ 200007 ] ;
int br[ 200007 ] ;
int ans = 0 ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d%d" , &n , &t , &c ) ;
    int i ;
    br[ 0 ] = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( a[ i ] > t ) br[ i ] = br[ i - 1 ] + 1 ;
        else br[ i ] = br[ i - 1 ] ;
    }
}


void solve ( )  {
    int i ;
    int x ;
    int cur ;
    for ( i = c ; i <= n ; i ++ ) {
        x = i - c ;
        cur = br[ i ] - br[ x ] ;
        if ( cur == 0 ) ans ++ ;
    }
    printf ( "%d\n" , ans ) ;
}