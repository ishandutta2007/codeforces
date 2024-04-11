#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n ;
string a ;

vector < pair < int , int > > v ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] != 'a' ) {
            v.push_back ( make_pair ( ( a[ i ] - 'a' ) , i ) ) ;
        }
    }
    int sz = v.size ( ) ;
    if ( sz == 0 ) {
        cout << a << "\n" ;
        return ;
    }
    if ( ( sz % 2 ) != 0 ) { cout << ":(\n" ; return ; }
    int half = ( sz / 2 ) ;
    for ( i = 0 ; i < half ; i ++ ) {
        if ( v[ i ].first != v[ i + half ].first ) {
            cout << ":(\n" ;
            return ;
        }
    }
    int st_id = v[ half ].second ;
    for ( i = st_id ; i < n ; i ++ ) {
        if ( a[ i ] == 'a' ) {
            cout << ":(\n" ;
            return ;
        }
    }
    for ( i = 0 ; i < st_id ; i ++ ) {
        cout << a[ i ] ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}