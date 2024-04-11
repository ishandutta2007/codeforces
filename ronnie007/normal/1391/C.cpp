#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007

int n ;
long long ans ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    ans = 1 ;
    long long sub = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = ( ans * i ) % MOD ;
        if ( i < n ) { sub = ( sub * 2 ) % MOD ; }
    }
    ans = ( ans - sub + MOD ) % MOD ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}