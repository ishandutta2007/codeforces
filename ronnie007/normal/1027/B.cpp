#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

long long n , q ;

void input ( ) {
    scanf ( "%I64d%I64d" , &n , &q ) ;
}

void solve ( ) {
    long long x , y ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%I64d%I64d" , &x , &y ) ;
        long long st = 0 ;
        if ( ( ( x + y ) % 2 ) == 1 ) { st = ( n * n + 1 ) / 2 ; }
        long long aux = 0 ;
        if ( ( ( x + y ) % 2 ) == 0 ) {
            long long row1 = ( n + 1 ) / 2 ;
            long long row2 = n - row1 ;
            aux = ( x / 2 ) * row1 ;
            aux += ( ( x - 1 ) / 2 ) * row2 ;
            if ( ( x % 2 ) == 0 ) {
                aux += ( y / 2 ) ;
            }
            else {
                aux += ( y - ( y / 2 ) ) ;
            }
        }
        else {
            long long row2 = ( n + 1 ) / 2 ;
            long long row1 = n - row2 ;
            aux = ( x / 2 ) * row1 ;
            aux += ( ( x - 1 ) / 2 ) * row2 ;
            if ( ( x % 2 ) == 1 ) {
                aux += ( y / 2 ) ;
            }
            else {
                aux += ( y - ( y / 2 ) ) ;
            }
        }
        printf ( "%I64d\n" , st + aux ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}