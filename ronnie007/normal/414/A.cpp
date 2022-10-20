#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define inf 1000000000

int n , k ;
int ans = 0 ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( )  {
    int x = n / 2 ;
    if ( n == 1 && k == 0 ) {
        printf ( "1\n" ) ;
        return ;
    }
    if ( n == 1 && k != 0 ) {
        printf ( "-1\n" ) ;
        return ;
    }
    if ( k < x ) {
        printf ( "-1\n" ) ;
        return ;
    }
    int i ;
    x -- ; 
    printf ( "%d %d ", k - x , 2 * ( k - x ) ) ;
    int p , q ;
    p = inf ;
    q = inf - 1 ;
    while ( x > 0 ) {
        printf ( "%d %d " , p , q ) ;
        p -= 2 ;
        q -= 2 ;
        x -- ;
    }
    if ( n % 2 == 1 ) printf ( "%d" , p ) ;
    printf ( "\n" ) ;

}