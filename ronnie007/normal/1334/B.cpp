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

#define MAXN 100007
int n , x ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &x ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 , greater < int > ( ) ) ;
}

void solve ( ) {
    long long sm = 0 ;
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sm += ( a[ i ] - x ) ;
        if ( sm >= 0 ) {
            ans = i ;
        }
        else { break ; }
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