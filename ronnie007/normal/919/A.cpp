#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 5007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

double mn ;

void input ( ) {
    cin >> n >> m ;
    int i ;
    mn = MAXN * MAXN ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] >> b[ i ] ;
        double aux = a[ i ] ;
        aux /= b[ i ] ;
        if ( mn > aux ) { mn = aux ; }
    }
}

void solve ( ) {
    printf ( "%.12lf\n" , mn * m ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}