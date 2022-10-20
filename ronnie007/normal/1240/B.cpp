#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 600007

int n ;
int a[ MAXN ] ;
int br[ MAXN ] ;

int fst[ MAXN ] ;
int lst[ MAXN ] ;

int val_map[ MAXN ] ;
int mx_val ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        br[ i ] = 0 ;
        fst[ i ] = lst[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ br[ a[ i ] ] ;
    }
    int id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( br[ i ] > 0 ) {
            val_map[ i ] = ++ id ;
        }
    }
    mx_val = id ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = val_map[ a[ i ] ] ;
        lst[ a[ i ] ] = i ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        fst[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int l , r ;
    l = r = 1 ;
    int ans = mx_val ;
    while ( l <= mx_val ) {
        if ( r < l ) { r = l ; }
        while ( r + 1 <= mx_val && lst[ r ] <= fst[ r + 1 ] ) { ++ r ; }
        if ( ans > mx_val - ( r - l + 1 ) ) {
            ans = mx_val - ( r - l + 1 ) ;
        }
        ++ l ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}