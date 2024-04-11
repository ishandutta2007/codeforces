#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

long long n , k ;

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    long long ans = ( k / n ) ;
    if ( ( ans * n ) < k ) { ans ++ ; }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}