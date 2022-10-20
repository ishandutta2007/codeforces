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

int n , m ;


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
    if ( n == 1 && m == 1 ) { printf ( "0\n" ) ; return ; }
    if ( n == 1 ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            printf ( "%d " , j + 2 ) ;
        }
        printf ( "\n" ) ;
        return ;
    }
    if ( m == 1 ) {
        for ( int i = 0 ; i < n ; ++ i ) {
            printf ( "%d\n" , i + 2 ) ;
        }
        return ;
    }
    for ( int i = 0 ; i < n ; ++ i , printf ( "\n" ) ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            printf ( "%d " , ( j + 2 ) * ( ( i == 0 ) ? 1 : ( m + i + 1 ) ) ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}