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

int n , m , k ;
int mxx , mxy ; 

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 , x , y ; i <= 2 * k ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        if ( i <= k ) {
            mxx = max ( mxx , x ) ;
            mxy = max ( mxy , y ) ;
        }
    }
}

void solve ( ) {
    string a ;
    while ( mxx > 1 ) {
        a += 'U' ;
        -- mxx ;
    }
    while ( mxy > 1 ) {
        a += 'L' ;
        -- mxy ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int st = 1 ;
        if ( ( i % 2 ) == 1 ) {
            for ( int j = 1 ; j < m ; ++ j ) {
                a += 'R' ;
            }
        }
        else {
            for ( int j = 1 ; j < m ; ++ j ) {
                a += 'L' ;
            }
        }
        if ( i < n ) { a += 'D' ; }
    }
    cout << a.size ( ) << "\n" << a << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}