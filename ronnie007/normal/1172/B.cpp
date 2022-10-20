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

#define MOD 998244353
#define MAXN 200007

int n ;
int deg[ MAXN ] ;

long long fac[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        ++ deg[ x ] ; ++ deg[ y ] ;
    }
}

void solve ( ) {
    long long ans = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = ( ans * fac[ deg[ i ] ] ) % MOD ;
    }
    printf ( "%d\n" , (int) ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}