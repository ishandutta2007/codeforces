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

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int pos[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        if ( b[ i ] > 0 ) { pos[ b[ i ] ] = i ; }
    }
}

void solve ( ) {
    int mx = 0 ;
    int cnt = 0 ;
    int sr = 3 * MAXN ;
    if ( pos[ 1 ] > 0 ) {
        int j ;
        for ( j = pos[ 1 ] + 1 ; j <= n ; ++ j ) {
            if ( b[ j ] != b[ j - 1 ] + 1 ) { break ; }
        }
        if ( j > n ) {
            int st = b[ n ] + 1 ;
            int en = 0 ;
            for ( int i = st ; i <= n ; ++ i ) {
                if ( pos[ i ] > en ) { break ; }
                ++ en ;
                if ( i == n ) { sr = n - st + 1 ; }
            }
            if ( st > n ) { sr = 0 ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < pos[ i ] - cnt ) {
            mx = pos[ i ] - cnt ;
        }
        ++ cnt ;
    }
    printf ( "%d\n" , min ( mx + n , sr ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}