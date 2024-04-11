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
using namespace std ;

int n ;
string a , b ;

void input ( ) {
    cin >> n ;
    cin >> a >> b ;
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 0 ; i + 1 < n ; i ++ ) {
        if ( a[ i ] != b[ i ] && a[ i + 1 ] != b[ i + 1 ] ) {
            if ( a[ i ] == b[ i + 1 ] && b[ i ] == a[ i + 1 ] ) {
                swap ( a[ i ] , a[ i + 1 ] ) ;
                ans ++ ;
            }
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] != b[ i ] ) { ans ++ ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}