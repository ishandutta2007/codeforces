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
using namespace std ;

#define MAXN 1000007
#define MAXVAL 10001

int n ;
int a[ MAXN ] ;

int br[ MAXVAL + 7 ] ;

double curans ;
int rem1 , rem2 ;

void clean ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        br[ a[ i ] ] -- ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    curans = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i ;
    int lst = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( br[ a[ i ] ] >= 4 ) {
            printf ( "%d %d %d %d\n" , a[ i ] , a[ i ] , a[ i ] , a[ i ] ) ;
            return ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == a[ i - 1 ] ) { continue ; }
        if ( br[ a[ i ] ] >= 2 ) {
            if ( lst != -1 ) {
                double p = ( 2 * a[ i ] + 2 * lst ) ;
                long long s = 1LL * a[ i ] * lst ;
                double val = ( ( p * p ) / s ) ;
                if ( curans < 0 ) {
                    curans = val ;
                    rem1 = lst ;
                    rem2 = a[ i ] ;
                }
                if ( curans > val ) {
                    curans = val ;
                    rem1 = lst ;
                    rem2 = a[ i ] ;
                }
            }
            lst = a[ i ] ;
        }
    }
    printf ( "%d %d %d %d\n" , rem1 , rem1 , rem2 , rem2 ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t != 0 ) {
        t -- ;
        input ( ) ;
        solve ( ) ;
        clean ( ) ;
    }
    return 0 ;
}