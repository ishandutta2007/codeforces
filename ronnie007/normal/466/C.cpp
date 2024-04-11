#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

int n ;
int a[ 500007 ] ;
long long sm = 0 ;
long long ans = 0 ; 


map < long long , int > ZX ; 

void input ( ) ;
void solve ( ) ;



int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    sm = 0 ; 
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        sm += a[ i ] ; 
    }
}

void solve ( ) {
    if ( sm % 3 != 0 ) {
        printf ( "0\n" ) ;
        return ; 
    }
    sm /= 3 ; 
    long long x = 0 ;
    int i ;
    for ( i = 0 ; i < n - 1  ; i ++ ) {
        x += a[ i ] ; 

        if ( x == 2 * sm ) {
            ans += ZX[ sm ] ; 
        }
        ZX[ x ] ++ ; 
    }
    printf ( "%I64d\n" , ans ) ;
}