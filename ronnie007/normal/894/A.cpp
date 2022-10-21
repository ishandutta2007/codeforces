#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j , t ;
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = i + 1 ; j < n ; j ++ ) {
            for ( t = j + 1 ; t < n ; t ++ ) {
                if ( a[ i ] == 'Q' && a[ j ] == 'A' && a[ t ] == 'Q' ) { ans ++ ; }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}