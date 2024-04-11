#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;

long long odd ;
long long even ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ n + i ] = a[ i ] ;
        if ( ( i % 2 ) == 1 ) {
            odd += a[ i ] ;
        }
        else {
            even += a[ i ] ;
        }
    }
}

void solve ( ) {
    long long ans = max ( odd , even ) ;
    for ( int i = n + 1 ; i <= 2 * n ; ++ i ) {
        int id = ( i - n ) ;
        if ( ( id % 2 ) == 1 ) {
            odd -= a[ id ] ;
        }
        else {
            even -= a[ id ] ;
        }

        if ( ( i % 2 ) == 1 ) {
            odd += a[ i ] ;
        }
        else {
            even += a[ i ] ;
        }
        ans = max ( ans , odd ) ;
        ans = max ( ans , even ) ;
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