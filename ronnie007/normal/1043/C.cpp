#include<iostream>
#include<stdio.h>
#include<set>
using namespace std ;

#define MAXN 1007

int n ;
string a ;

string cur ;

int fl[ MAXN ] ;

string rev ( string s ) {
    string ret ;
    ret.clear ( ) ;
    int sz = s.size ( ) ;
    int i ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        ret += s[ i ] ;
    }
    return ret ;
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j ;
    cur.clear ( ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        string aux1 , aux2 , aux3 , aux4 ;
        aux1 = cur + a[ i ] ;
        aux2 = rev ( cur ) + a[ i ] ;
        aux3 = rev ( aux1 ) ;
        aux4 = rev ( aux2 ) ;
        int id = 1 ;
        string mn = aux1 ;
        if ( mn > aux2 ) { mn = aux2 ; id = 2 ; }
        if ( mn > aux3 ) { mn = aux3 ; id = 3 ; }
        if ( mn > aux4 ) { mn = aux4 ; id = 4 ; }
        cur = mn ;
        if ( id == 2 ) {
            if ( i != 0 ) { fl[ i - 1 ] ^= 1 ; }
        }
        if ( id == 3 ) {
            fl[ i ] ^= 1 ;
        }
        if ( id == 4 ) {
            if ( i != 0 ) { fl[ i - 1 ] ^= 1 ; }
            fl[ i ] ^= 1 ;
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        cout << fl[ i ] << " " ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}