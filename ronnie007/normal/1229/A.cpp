#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 7007

int n ;
pair < long long , long long > a[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ].first ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    vector < long long > v ;
    v.push_back ( 0 ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ].first == a[ i + 1 ].first ) {
            v.push_back ( a[ i ].first ) ;
        }
    }
    int sz = v.size ( ) ;
    int hh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( ( a[ i ].first & v[ j ] ) == a[ i ].first ) {
                ans += a[ i ].second ;
                ++ hh ;
                break ;
            }
        }
    }
    if ( hh < 2 ) { ans = 0 ; }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}