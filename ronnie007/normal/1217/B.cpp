#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 107

int n , x ;
pair < int , int > a[ MAXN ] ;

int mx = 0 ;

void input ( ) {
    scanf ( "%d%d" , &n , &x ) ;
    mx = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        mx = ( mx < a[ i ].first ) ? a[ i ].first : mx ;
    }
}

void solve ( ) {
    int ans = 2 * x ;
    if ( x <= mx ) { ans = 1 ; }
    else {
        for ( int i = 1 ; i <= n ; ++ i ) {
            int diff = ( a[ i ].first - a[ i ].second ) ;
            if ( diff <= 0 ) { continue ; }
            int h = ( x - mx ) / diff + 1 ;
            if ( ( x - mx ) % diff != 0 ) { ++ h ; }
            ans = ( ans > h ) ? h : ans ;
        }
    }

    if ( ans == 2 * x ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
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