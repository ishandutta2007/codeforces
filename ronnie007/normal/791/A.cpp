#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

long long x , y ;


void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    int ans = 0 ;
    while ( x <= y ) {
        x *= 3 ;
        y *= 2 ;
        ans ++ ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}