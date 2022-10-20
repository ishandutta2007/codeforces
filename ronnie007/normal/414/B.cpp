#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

#define MOD 1000000007

int n , k ;

long long dp[ 2007 ][ 2007 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( )  {
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) { dp[ 1 ][ i ] = 1 ; }
    for ( i = 1 ; i < k ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            for ( t = j ; t <= n ; t += j ) {
                dp[ i + 1 ][ t ] += dp[ i ][ j ] ;
                dp[ i + 1 ][ t ] %= MOD ;
            }
        }
    }
    int ans = 0 ; 
    for ( i = 1 ; i <= n ; i ++ ) {
        ans += dp[ k ][ i ] ;
        ans = ans % MOD ;
    }
    printf ( "%d\n" , ans ) ;
}