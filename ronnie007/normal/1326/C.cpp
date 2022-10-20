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
#define MOD 998244353
int n , k ;
int a[ MAXN ] ;

long long sm , mul ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    sm = 0 ;
    mul = 1 ;
    int lst = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] >= n - k + 1 ) {
            sm += a[ i ] ;
            if ( lst != -1 ) {
                mul = ( mul * ( i - lst ) ) % MOD ;
            }
            lst = i ;
        }
    }
    cout << sm << " " << mul << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}