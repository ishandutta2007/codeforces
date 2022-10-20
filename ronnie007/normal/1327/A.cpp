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

int n , k ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    long long aux = 1LL * k * ( k + 1 ) / 2 ;
    aux = 2 * aux - k ;
    if ( aux > n || (n+k)%2 != 0 ) { printf ( "NO\n" ) ; }
    else { printf ( "YES\n" ) ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}