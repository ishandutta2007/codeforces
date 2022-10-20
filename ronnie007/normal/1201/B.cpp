#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; ++ i ) { scanf ( "%d" , &a[ i ] ) ; }
}

void solve ( ) {
    int ans = 0 ;
    long long sm = 0 ;
    long long mx = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ans += (a[ i ] & 1) ;
        sm += a[ i ] ;
        mx = ( mx < a[ i ] ) ? a[ i ] : mx ;
    }
    if ( 2 * mx > sm ) { cout << "NO\n" ; return ; }
    string ret = ( ( ans & 1 ) == 0 ) ? "YES" : "NO" ;
    cout << ret << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}