#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 107
#define MOD 1000000007
int n , q ;

string a ;

long long f[ MAXN ][ 26 * MAXN ] ;


void calc ( ) {
    int i , j , t ;
    f[ 0 ][ 0 ] = 1 ;
    for ( i = 0 ; i < 100 ; i ++ ) {
        for ( j = 0 ; j <= i * 25 ; j ++ ) {
            for ( t = 0 ; t < 26 ; t ++ ) {
                f[ i + 1 ][ j + t ] += f[ i ][ j ] ;
                if ( f[ i + 1 ][ j + t ] >= MOD ) {
                    f[ i + 1 ][ j + t ] -= MOD ;
                }
            }
        }
    }
}

void input ( ) {
    cin >> q ;
}

void solve ( ) {
    calc ( ) ;
    while ( q != 0 ) {
        q -- ;
        cin >> a ;
        n = a.size ( ) ;
        int sm = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) { sm += ( a[ i ] - 'a' ) ; }
        printf ( "%I64d\n" , ( f[ n ][ sm ] + MOD - 1 ) % MOD ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}