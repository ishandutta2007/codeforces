#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;
long long cnt[ 37 ] ;
long long f[ 37 ][ 37 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        int el = ( a[ i ] - 'a' ) ;
        for ( int j = 0 ; j < 26 ; ++ j ) {
            f[ j ][ el ] += cnt[ j ] ;
        }
        ++ cnt[ el ] ;
    }
    long long mx = 0 ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        mx = max ( mx , cnt[ i ] ) ;
        for ( int j = 0 ; j < 26 ; ++ j ){
            mx = max ( mx , f[ i ][ j ] ) ;
        }
    }
    printf ( "%I64d\n" , mx ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}