#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007

int n ;
string a ;

int f ( char c ) {
    if ( c >= '0' && c <= '9' ) { return ( c - '0' ) ; }
    if ( c >= 'A' && c <= 'Z' ) { return 10 + ( c - 'A' ) ; }
    if ( c >= 'a' && c <= 'z' ) { return 36 + ( c - 'a' ) ; }
    if ( c == '-' ) { return 62 ; }
    return 63 ;
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j ;
    long long ans = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int val = f ( a[ i - 1 ] ) ;
        for ( j = 0 ; j < 6 ; j ++ ) {
            if ( (val&(1<<j)) == 0 ) {
                ans *= 3 ;
                if ( ans >= MOD ) { ans -= MOD ; }
                if ( ans >= MOD ) { ans -= MOD ; }
                if ( ans >= MOD ) { ans -= MOD ; }
            }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}