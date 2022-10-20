#include<bits/stdc++.h>
using namespace std ;

int x , y , z , t1 , t2 , t3 ;

void input ( ) {
    cin >> x >> y >> z >> t1 >> t2 >> t3 ;
}

void solve ( ) {
    int h1 = abs ( x - y ) * t1 ;
    int h2 = ( abs ( z - x ) + abs ( x - y ) ) * t2 + 3 * t3 ;
    if ( h2 <= h1 ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}