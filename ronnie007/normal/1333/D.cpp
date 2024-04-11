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
#include<random>
using namespace std ;

#define MAXN 10000007

int n , k ;
string a ;
string s ;
vector < int > v[ MAXN ] ;
int mx ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    int id = 0 ;
    s.resize ( n ) ;
    while ( 1 ) {
        ++ id ;
        for ( int i = 0 ; i < n ; ++ i ) {
            s[ i ] = a[ i ] ;
        }
        for ( int i = 0 ; i < n - 1 ; ++ i ) {
            if ( a[ i ] == 'R'  && a[ i + 1 ] == 'L' ) {
                v[ id ].push_back ( i + 1 ) ;
                s[ i ] = 'L' ; s[ i + 1 ] = 'R' ;
                ++ mx ;
            }
        }
        if ( v[ id ].size ( ) == 0 ) { -- id ; break ; }
        for ( int i = 0 ; i < n ; ++ i ) {
            a[ i ] = s[ i ] ;
        }
    }
    if ( id > k ) { cout << "-1\n" ; return ; }
    if ( mx < k ) { cout << "-1\n" ; return ; }
    int lft = k - id ;
    for ( int i = 1 ; i <= id ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        int st = 0 ;
        for ( int j = 0 ; j < sz - 1 ; ++ j ) {
            if ( lft > 0 ) {
                -- lft ;
                ++ st ;
                cout << "1 " << v[ i ][ j ] << "\n" ;
            }
            else { break ; }
        }
        cout << sz - st << " " ;
        for ( int j = st ; j < sz ; ++ j ) {
            cout << v[ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}