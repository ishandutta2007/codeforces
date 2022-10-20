#include<iostream>
#include<stdio.h>
#include<map>
using namespace std ;


int n , k ;
int a[ 400007 ] ;
map < int , int > m ;

int main ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    int l , r ;
    l = 0 , r = 0 ;
    //m[ a[ 0 ] ] = 1 ;
    long long ans = 0 ;
    while ( l != n ) {
        while ( r != n && m[ a[ r ] ] < k - 1 ) {
            m[ a[ r ] ] ++ ;
            r ++ ;
        }
        ///printf ( "for l = %d , r = %d\n" , l , r ) ;
        ans += ( n - r ) ;
        m[ a[ l ] ] -- ;
        l ++ ;
    }
    printf ( "%I64d\n" , ans ) ;
    return 0 ;
}