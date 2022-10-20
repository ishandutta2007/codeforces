#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n , m , a , b ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //  ios::sync_with_stdio ( false ) ;
    //  cin.tie ( NULL ) ; 
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d%d%d%d" ,&n , &m ,  &a , &b ) ;
}

void solve ( )  {
    int i ; 
    int br = 0 ;
    int ret = -1 ;
    int x ; 
    int u ; 
    for ( i = 0 ; i <= n ; i ++ ) {
        u = i * m ; 
        if ( u < n ) br = ( n - u ) * a ; 
        else br = 0 ;
        br += i * b ; 
        if ( ret == -1 || ret > br ) ret = br ; 
    }
    printf ( "%d\n" , ret ) ;
}