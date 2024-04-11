#include<bits/stdc++.h>
using namespace std ;

int h , n ;

void input ( ) {
    scanf ( "%d%d" , &n , &h ) ;
}

void solve ( ) {
    double area = h / 2.0 ;
    area /= n ;
    for ( int coef = 1 ; coef < n ; ++ coef ) {
        double aux = area * coef ;
        aux = aux * 2 * h ;
        printf ( "%.12lf\n" , sqrt ( aux ) ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}