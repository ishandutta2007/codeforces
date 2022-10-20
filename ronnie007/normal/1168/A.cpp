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

#define MAXN 300007

int n , m ;
int a[ MAXN ] ;

bool f ( int sr ) {
    int lst = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] + sr < lst ) { return false ; }
        if ( a[ i ] > lst ) {
            int aux = ( a[ i ] + sr ) % m ;
            if ( a[ i ] + sr < m || aux < lst ) { lst = a[ i ] ; }
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 0 ;
    r = m ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid + 1 ; }
    }
    while ( r > 0 && f ( r - 1 ) == true ) { -- r ; }
    printf ( "%d\n" , r ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}