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
#define MAXMOD 1007

int n , mod ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;

long long diff[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &mod ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ cnt[ ( a[ i ] % mod ) ] ;
    }
}

void solve ( ) {
    long long ans = 1 ;
    for ( int i = 0 ; i < mod ; ++ i ) {
        if ( cnt[ i ] > 1 ) { printf ( "0\n" ) ; return ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j < i ; ++ j ) {
            ans = ans * ( abs ( a[ i ] - a[ j ] ) ) ;
            ans %= mod ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}