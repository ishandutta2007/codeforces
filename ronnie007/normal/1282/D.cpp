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
char fst_char ;

int ask ( string s ) {
    cout << s << "\n" ;
    fflush ( stdout ) ;
    int ans ;
    cin >> ans ;
    if ( ans == 0 || ans == -1 ) { exit ( 0 ) ; }
    return ans ;
}

void input ( ) {
    string a = "a" ;
    int ret1 = ask ( a ) ;
    n = ret1 + 1 ;
}

void solve ( ) {
    string a = "" ;
    for ( int i = 0 ; i < n ; ++ i ) {
        a += "a" ;
    }
    if ( n > 300 ) {
        string b = "" ;
        for ( int i = 0 ; i < n - 1 ; ++ i ) { b += 'b' ; }
        ask ( b ) ;
        return ;        
    }
    int init = ask ( a ) ;
    if ( init == n ) {
        string b = "" ;
        for ( int i = 0 ; i < n - 1 ; ++ i ) { b += 'b' ; }
        ask ( b ) ;
        return ;
    }
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        a[ i ] = 'b' ;
        int ret = ask ( a ) ;
        if ( ret < init ) {
            init = ret ;
        }
        else {
            a[ i ] = 'a' ;
        }
    }
    if ( init == 1 ) { a[ n - 1 ] = 'b' ; }
    ask ( a ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}