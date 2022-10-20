#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int f[ MAXN ] ;

long long sm = 0 ;
map < pair < int , int > , int > ZX ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        sm += a[ i ] ;
    }
}

void solve ( ) {
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( ZX.find ( { x , y } ) != ZX.end ( ) ) {
            if ( -- f[ ZX[ { x , y } ] ] < a[ ZX[ { x , y } ] ] ) { ++ sm ; }
            ZX.erase ( { x , y } ) ;
        }
        if ( z != 0 ) {
            if ( ++ f[ z ] <= a[ z ] ) { -- sm ; }
            ZX[ { x , y } ] = z ;
        }
        printf ( "%I64d\n" , sm ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}