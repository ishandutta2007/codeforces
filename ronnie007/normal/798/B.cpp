#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAXN 57

int n ;
string a[ MAXN ] ;


string f ( string x ) {
    string ret ;
    ret.clear ( ) ;
    int i ;
    int sz = x.size ( ) ;
    for ( i = 1 ; i < sz ; i ++ ) {
        ret += x[ i ] ;
    }
    ret += x[ 0 ] ;
    return ret ;
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i , j , t ;
    string h = a[ 1 ] ;
    int ans = -1 ;
    int sz = a[ 1 ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        int cur = i ;
        for ( j = 2 ; j <= n ; j ++ ) {
            string u = a[ j ] ;
            int br = 0 ;
            while ( u != h ) {
                if ( br > sz ) { break ; }
                u = f ( u ) ;
                br ++ ;
            }
            if ( u != h ) { cur = -1 ; break ; }
            cur += br ;
        }
        h = f ( h ) ;
        if ( cur != -1 ) {
            if ( ans == -1 || ans > cur ) { ans = cur ; }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}