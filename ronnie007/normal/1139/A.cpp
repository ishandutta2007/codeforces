#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int i ;
    long long ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        int val = ( a[ i ] - '0' ) ;
        if ( ( val % 2 ) == 0 ) {
            ans += ( i + 1 ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}