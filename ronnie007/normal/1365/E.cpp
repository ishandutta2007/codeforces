#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
long long a[ MAXN ] ;
long long ans = 0 ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            for ( int t = 1 ; t <= n ; ++ t ) {
                long long aux = a[ i ] ;
                aux |= a[ j ] ;
                aux |= a[ t ] ;
                if ( ans < aux ) { ans = aux ; }
            }
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