#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;


long long n , p ;

void input ( ) {
    cin >> n >> p ;
}

void solve ( ) {
    for ( int ans = 1 ; ans <= 100 ; ++ ans ) {
        long long aux = n - ans * p ;
        if ( aux < 0 ) { continue ; }
        long long st = 1 ;
        while ( 2 * st <= aux ) { st *= 2 ; }
        int cnt = 0 ;
        while ( st > 0 ) {
            if ( aux >= st ) { aux -= st ; ++ cnt ; }
            st /= 2 ;
        }
        long long init = n - ans * p ;
        if ( cnt <= ans && init >= ans ) { printf ( "%d\n" , ans ) ; return ; }
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}