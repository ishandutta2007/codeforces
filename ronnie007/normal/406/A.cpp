#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
int diag[ 1007 ] ; 
int q ; 


void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    int i , j , x ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            scanf ( "%d" , &x ) ;
            if ( i == j ) diag[ i ] = x ; 
        }
    }
}

void solve ( )  {
    int i ;
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        ans = ans + diag[ i ] ;
    }
    scanf ( "%d" , &q ) ;
    int t , x ;
    while ( q != 0 ) {
        scanf ( "%d" , &t ) ;
        if ( t == 3 ) {
            printf ( "%d" , ans % 2 ) ;
        }
        else {
            scanf ( "%d" , &x ) ;
            if ( diag[ x ] == 0 ) ans ++ ;
            else ans -- ;
            diag[ x ] = 1 - diag[ x ] ; 
        }
        q -- ; 
    }
    printf ( "\n" ) ;
}