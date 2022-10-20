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

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int mn = 27 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int val = ( a[ i ] - 'a' ) ;
        if ( mn >= val ) { cout << "Mike\n" ; }
        else { cout << "Ann\n" ; }
        if ( mn > val ) { mn = val ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}