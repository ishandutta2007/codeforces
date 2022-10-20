#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 100007

int n , k ;
int prv[ MAXN ] ;
int ans = 0 ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

int UNITE ( int x , int y ) {
    int k1 = get ( x ) ;
    int k2 = get ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
        ++ ans ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        UNITE ( x , y ) ;
    }
    printf ( "%d\n" , k - ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}