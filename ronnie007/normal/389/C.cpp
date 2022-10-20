#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n ;
int a[ 107 ] ;
int used[ 107 ] ; 
int ans = 0 ; 

void input ( ) ;
void solve ( ) ;

int main ( ) {
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
void solve ( ) {
    int i ; 
    int j ;
    int lst ;
    int br = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            used[ i ] = 1 ; 
            br = 1 ;
            ans ++ ;
            for ( j = i + 1 ; j < n ; j ++ ) {
                if ( a[ j ] >= br && used[ j ] == 0 ) {
                    used[ j ] = 1 ;
                    br ++ ;
                }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}