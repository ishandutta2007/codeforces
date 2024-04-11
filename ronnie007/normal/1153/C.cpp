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

#define MAXN 300007

int n ;
string a ;


void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    if ( ( n % 2 ) == 1 ) { cout << ":(\n" ; return ; }
    int lft = ( n / 2 ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '(' ) { lft -- ; }
    }
    if ( lft < 0 ) { cout << ":(\n" ; return ; }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( lft <= 0 ) { break ; }
        if ( a[ i ] == '?' ) {
            a[ i ] = '(' ;
            lft -- ;
        }
    }
    int f = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '?' ) { a[ i ] = ')' ; }
        if ( a[ i ] == '(' ) { f ++ ; }
        else { f -- ; }
        if ( i != ( n - 1 ) && f <= 0 ) { cout << ":(\n" ; return ; }
    }
    if ( f != 0 ) { cout << ":(\n" ; return ; }
    cout << a << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}