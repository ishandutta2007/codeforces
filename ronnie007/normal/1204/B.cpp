#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

int n , l , r ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &l , &r ) ;
}

void solve ( ) {
    long long mn = 0 ;
    long long mx = 0 ;
    for ( int i = 0 ; i < l ; ++ i ) {
        mn += (1<<i) ;
    }
    mn += 1LL * ( n - l ) ;
    for ( int i = 0 ; i < r ; ++ i ) {
        mx += (1<<i) ;
    }
    mx += 1LL * ( n - r ) * (1<<(r-1)) ;
    printf ( "%I64d %I64d\n" , mn , mx ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}