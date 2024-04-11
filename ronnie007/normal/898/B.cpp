#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 10000007

int n , a , b ;
int dv[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d%d" , &n , &a , &b ) ;
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i <= n ; i += b ) {
        if ( i >= b ) {
            dv[ i ] = dv[ i - b ] + 1 ;
        }
    }
    int tot = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        int lft = ( n - tot ) ;
        if ( lft >= 0 ) {
            if ( lft == 0 ) {
                printf ( "YES\n" ) ;
                printf ( "%d 0\n" , i ) ;
                return ;
            }
            if ( dv[ lft ] != 0 ) {
                printf ( "YES\n" ) ;
                printf ( "%d %d\n" , i , dv[ lft ] ) ;
                return ;
            }
        }
        else { break ; }
        tot += a ;
    }
    printf ( "NO\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}