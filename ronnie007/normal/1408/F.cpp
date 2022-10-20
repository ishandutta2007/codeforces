#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std ;

int n ;
vector < pair < int , int > > v ;

void f ( int l , int r ) {
    if ( l == r ) { return ; }
    int mid = ( l + r ) / 2 ;
    f ( l , mid ) ;
    f ( mid + 1 , r ) ;
    int aux = r ;
    if ( ( r - l + 1 ) % 2 == 1 ) { -- aux ; }
    for ( int i = 0 ; l + i < aux - i ; ++ i ) {
        v.push_back ( { l + i , aux - i } ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int st = 1 ;
    while ( 2 * st <= n ) { st *= 2 ; }
    f ( 1 , st ) ;
    f ( n - st + 1 , n ) ;
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}