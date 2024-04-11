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

#define MAXN 3507

int n , m , k ;
int a[ MAXN ] ;

int f[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    k = min ( k , m - 1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        f[ i ] = max ( a[ i ] , a[ i + n - m ] ) ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= k + 1 ; ++ i ) {
        int lft = ( k - ( i - 1 ) ) ;
        int aux = -1 ;
        for ( int j = i ; j + n - m <= n - lft ; ++ j ) {
            if ( aux < 0 ) { aux = f[ j ] ; }
            aux = min ( aux , f[ j ] ) ;
        }
        ans = max ( ans , aux ) ;
    }
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