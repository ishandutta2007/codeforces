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

#define MOD 1000000007

int lim ;
int n ;
string a ;

void input ( ) {
    cin >> lim ;
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    long long ans = n ;
    for ( int i = 0 ; i < lim ; ++ i ) {
        if ( n < lim && a[ i ] != '1' ) {
            string aux = "" ;
            for ( int j = i + 1 ; j < n ; ++ j ) {
                aux += a[ j ] ;
            }
            for ( int j = 1 ; j < ( a[ i ] - '0' ) ; ++ j ) {
                a += aux ;
                n += aux.size ( ) ;
                if ( n > lim ) { break ; }
            }
        }
        long long diff = ( ans - i - 1 + MOD ) % MOD ;
        ans = ( ans + diff * ( a[ i ] - '1' ) ) % MOD ;
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}