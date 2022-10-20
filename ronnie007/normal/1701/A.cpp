#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int a , b , c , d ;

void solve ( ) {
    cin >> a >> b >> c >> d ;
    if ( a + b + c + d == 4 ) { cout << "2\n" ; }
    else if ( a + b + c + d > 0 ) {
        cout << "1\n" ;
    }
    else { cout << "0\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}