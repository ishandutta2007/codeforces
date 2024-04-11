#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int a ;
int n ; 
int x , y ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d%d" , &n , &a ) ;

}

void solve ( )  {
    int best = -1 ; 
    int i ;
    int p , q ; 
    int br = 0 ; 
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        if ( x < a ) {
            br = 100 - y ;
            if ( y == 0 ) br = 0 ;
            if ( best < br ) best = br ;
        }
        if ( x == a && y == 0 ) {
            if ( best < 0 ) best = 0 ; 
        }
    }
    printf ( "%d\n" , best ) ;
}