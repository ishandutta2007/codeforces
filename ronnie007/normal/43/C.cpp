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
int br[ 7 ] ;


void input ( ) ;
void solve ( ) ;



int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , x ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &x ) ;
        br[ x % 3 ] ++ ;
    }
}

void solve ( ) {
    printf ( "%d\n" , min ( br[ 1 ] , br[ 2 ] ) + br[ 0 ] / 2 ) ;
}