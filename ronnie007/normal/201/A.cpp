#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int x ;


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &x ) ;
}

void solve ( ) {
    int i ;
    int n ;
    if ( x == 3 ) { printf ( "5\n" ) ; return ; }
    for ( i = 1 ; i <= 1007 ; i +=2 ) {
        n = ( i * i + 1 ) / 2 ;
        if ( n >= x ) break ;
    }
    printf ( "%d\n" , i ) ;
}