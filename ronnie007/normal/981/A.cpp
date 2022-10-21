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

bool f ( int st , int en ) {
    while ( st < en && a[ st - 1 ] == a[ en - 1 ] ) {
        ++ st , -- en ;
    }
    return ( st >= en ) ;
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    for ( int len = n ; len >= 1 ; -- len ) {
        for ( int i = 1 ; i + len - 1 <= n ; ++ i ) {
            if ( f ( i , i + len - 1 ) == false ) {
                printf ( "%d\n" , len ) ;
                return ;
            }
        }
    }
    printf ( "0\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}