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

vector < char > v ;

bool check ( char c ) {
    if ( c == 'a' ) { return false ; }
    if ( c == 'e' ) { return false ; }
    if ( c == 'i' ) { return false ; }
    if ( c == 'o' ) { return false ; }
    if ( c == 'u' ) { return false ; }
    return true ;
}

bool f ( ) {
    int sz = v.size ( ) ;
    bool p1 , p2 , p3 ;
    p1 = check ( v[ sz - 1 ] ) ;
    p2 = check ( v[ sz - 2 ] ) ;
    p3 = check ( v[ sz - 3 ] ) ;
    if ( p1 == false || p2 == false || p3 == false ) { return false ; }
    if ( v[ sz - 1 ] == v[ sz - 2 ] && v[ sz - 2 ] == v[ sz - 3 ] ) { return false ; }
    return true ;
}


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        v.push_back ( a[ i ] ) ;
        if ( v.size ( ) >= 3 ) {
            if ( f ( ) == true ) {
                v.pop_back ( ) ;
                int sz = v.size ( ) ;
                for ( j = 0 ; j < sz ; j ++ ) {
                    cout << v[ j ] ;
                }
                v.clear ( ) ;
                cout << " " ;
                v.push_back ( a[ i ] ) ;
            }
        }
    }
    int sz = v.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        cout << v[ i ] ;
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