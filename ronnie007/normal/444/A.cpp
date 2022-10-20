#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n , m ;

int a[ 507 ] ;

int x[ 250007 ] ;
int y[ 250007 ] ;
int z[ 250007 ] ;
int br[ 507 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) scanf ( "%d" , &a[ i ] ) ;

    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d%d" , &x[ i ] , &y[ i ] , &z[ i ] ) ;
        br[ x[ i ] ] ++ ;
        br[ y[ i ] ] ++ ;
    }

}

void solve ( ) {
    int i ;
    double ans = 0.00 ;
    double u ;
    double p ;
    p = 0.00 ;
/// for ( i = 1 ; i <= n ; i ++ ) if ( br[ i ] == 0 ) p += a[ i ] ;
    for ( i = 0 ; i < m ; i ++ ) {
        u = p + a[ x[ i ] ] + a[ y[ i ] ] ;
        u /= z[ i ] ;
        if ( ans < u ) ans = u ;
    }
    printf ( "%.10lf\n" , ans ) ;

}