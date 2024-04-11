#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
long long a[ MAXN ] ;

long long sm ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
}

void solve ( ) {
    long long aux = ( sm - 1LL * n * ( n - 1 ) / 2 ) / n + 1 ;
    long long lft = aux * n + 1LL * n * ( n - 1 ) / 2 - sm ;
    int coef = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == n - lft + 1 ) { -- coef ; }
        cout << aux + i - 1 + coef << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}