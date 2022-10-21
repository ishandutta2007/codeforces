#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

string a , b ;

vector < string > v ;

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    string s ;
    int i , j , t ;
    for ( i = 0 ; i < a.size ( ) ; i ++ ) {
        for ( j = 0 ; j < b.size ( ) ; j ++ ) {
            s.clear ( ) ;
            for ( t = 0 ; t <= i ; t ++ ) {
                s += a[ t ] ;
            }
            for ( t = 0 ; t <= j ; t ++ ) {
                s += b[ t ] ;
            }
            v.push_back ( s ) ;
        }
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    cout << v[ 0 ] << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}