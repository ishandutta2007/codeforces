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
#define MOD 1000000007

int n ;
int a[ MAXN ] ;
long long pw[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) % MOD ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = ( ans + pw[ i - 1 ] * a[ i ] ) % MOD ;
        ans = ( ans - ( ( pw[ n - i ] * a[ i ] ) % MOD ) + MOD ) % MOD ;
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