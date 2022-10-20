#include<iostream>
#include<stdio.h>
#include<string>

#define MOD 1000000007

std::string a , b ; 

int n , m ; 

long long dp[ 5007 ][ 5007 ] ; 

void input ( ) {
    std::cin >> a >> b ; 
    n = a.size ( ) ;
    m = b.size ( ) ;
}

void solve ( ) {
    int i , j ;
    a = " " + a ;
    b = " " + b ;
    long long res = 0;
    for ( i = 1; i <= n ; i ++) { 
        for ( j = 1; j <= m ; j ++ ) {
            if ( a[ i ] == b[ j ] ){
                dp[ i ][ j ] =  ( dp[ i - 1 ][ j - 1 ] + 1 ) % MOD ;
                res += dp[ i ][ j ] ;
                res %= MOD ;
            }
            dp[ i ][ j ] = ( dp[ i ][ j ] +  dp[ i ][ j - 1 ] ) % MOD ;
        }
    }
    
    std::cout << res << "\n" ;
}

int main ( ) {
    std::ios::sync_with_stdio( false ) ;
    std::cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ; 
}