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

int n ;
int a[ 100007 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( )  {
    int i ;
    long long br = 0 ;
    long long ans = 0 ; 
    for ( i = 1 ; i <= n ; i ++ ) {
        br += ( a[ i - 1 ] - a[ i ] ) ;
        if ( br < 0 ) {
            ans += ( -br ) ;
            br = 0 ; 
        }
    }
    cout << ans << "\n" ;
}