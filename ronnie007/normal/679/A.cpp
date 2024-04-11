#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

vector < int > v ;

void input ( ) {

}

void solve ( ) {
    v.push_back ( 2 ) ;
    v.push_back ( 3 ) ;
    v.push_back ( 5 ) ;
    v.push_back ( 7 ) ;
    v.push_back ( 11 ) ;
    v.push_back ( 13 ) ;
    v.push_back ( 17 ) ;
    v.push_back ( 19 ) ;
    v.push_back ( 23 ) ;
    v.push_back ( 29 ) ;
    v.push_back ( 31 ) ;
    v.push_back ( 37 ) ;
    v.push_back ( 41 ) ;
    v.push_back ( 43 ) ;
    v.push_back ( 47 ) ;
    int sz = v.size ( ) ;
    int i ;
    int br = 0 ;
    int id = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        cout << v[ i ] << "\n" ;
        fflush ( stdout ) ;
        string h ;
        cin >> h ;
        if ( h == "yes" ) {
            br ++ ;
            id = v[ i ] ;
        }
    }
    if ( br > 1 ) { cout << "composite\n" ; fflush ( stdout ) ; return ; }
    if ( id != 0 && id * id <= 100 ) {
        cout << id * id << "\n" ;
        fflush ( stdout ) ;
        string h ;
        cin >> h ;
        if ( h == "yes" ) {
            cout << "composite\n" ;
            fflush ( stdout ) ;
            return ;
        }
    }
    cout << "prime\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    //ios_base::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}