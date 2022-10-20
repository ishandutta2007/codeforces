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
using namespace std ;

#define MAXN 200007

int n , k ;
string a ;
int st , en ;

bool fl[ MAXN ] ;


void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    int i ;
    int lft = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( 2 * lft >= k ) { break ; }
        if ( a[ i ] == '(' ) { fl[ i ] = true ; lft ++ ; }
    }
    lft = 0 ;
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        if ( 2 * lft >= k ) { break ; }
        if ( a[ i ] == ')' ) { fl[ i ] = true ; lft ++ ; }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( fl[ i ] == true ) { cout << a[ i ] ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}