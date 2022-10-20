#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n ;
int a[ 107 ] ;

void input ( ) ;
void solve ( ) ;

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0;
}


void input ( ) {
    scanf  ("%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}
void solve ( ) {
    sort ( a , a + n ) ;
    int i ;
    int j ;
    int t ;
    int mn = a[ 0 ]  ;
    for( t = 0 ; t < 150 ; t ++ ) {
        for ( i = 0 ; i < n ; i ++ ) if ( mn > a[ i ] ) mn = a[ i ] ; 
        
        for ( i = 0 ; i < n ; i ++ ) {
            while ( a[ i ] > mn ) a[ i ] -= mn ;
            mn = a[ i ] ;
        }
    }
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        ans += a[ i ] ;
    }   
    printf ( "%d\n" , ans ) ;
}