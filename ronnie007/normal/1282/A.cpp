#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

int st , en , x , r ;

void input ( ) {
    scanf ( "%d%d%d%d" , &st , &en , &x , &r ) ;
    if ( en < st ) { swap ( st , en ) ; }
}

void solve ( ) {
    if ( x - r > en || x + r < st ) { printf ( "%d\n" , ( en - st ) ) ; return ; }
    int a = max ( x - r , st ) ;
    int b = min ( x + r , en ) ;
    printf ( "%d\n" , ( en - st ) - ( b - a ) ) ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}