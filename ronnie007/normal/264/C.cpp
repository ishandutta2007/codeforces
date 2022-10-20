#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 300007
long long inf ;

int n , q ;
long long v[ MAXN ] ;
long long c[ MAXN ] ;
long long a , b ;

long long dp[ MAXN ] ;

void calc ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        dp[ i ] = -inf ;
    }
    long long mx1 , mx2 ;
    int id1 , id2 ;
    mx1 = mx2 = 0 ;
    id1 = 1 ;
    id2 = 2 ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        long long cur1 = dp[ c[ i ] ] + a * v[ i ] ;
        long long cur2 ;
        if ( c[ i ] == id1 ) {
            cur2 = mx2 + b * v[ i ] ;
        }
        else {
            cur2 = mx1 + b * v[ i ] ;
        }
        if ( cur2 < b * v[ i ] ) { cur2 = b * v[ i ] ; }
        if ( cur1 < cur2 ) { swap ( cur1 , cur2 ) ; }

        if ( ans < cur1 ) { ans = cur1 ; }

        dp[ c[ i ] ] = max ( dp[ c[ i ] ] , cur1 ) ;
        if ( dp[ c[ i ] ] != cur1 ) { continue ; }

        if ( c[ i ] == id1 ) {
            mx1 = cur1 ;
        }
        else if ( c[ i ] == id2 ) {
            mx2 = cur1 ;
            if ( mx2 > mx1 ) {
                swap ( mx1 , mx2 ) ;
                swap ( id1 , id2 ) ;
            }
        }
        else {
            if ( mx1 <= cur1 ) {
                mx2 = mx1 ;
                id2 = id1 ;
                mx1 = cur1 ;
                id1 = c[ i ] ;
            }
            else if ( mx2 <= cur1 ) {
                mx2 = cur1 ;
                id2 = c[ i ] ;
            }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &v[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &c[ i ] ) ;
    }
    inf = 1 ;
    for ( i = 1 ; i <= 16 ; i ++ ) { inf *= 10 ; }
}

void solve ( ) {
    while ( q != 0 ) {
        q -- ;
        scanf ( "%I64d%I64d" , &a , &b ) ;
        calc ( ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}