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

#define MAXN 200007

int n ;
string a ;

int c[ MAXN ] ;
int fst[ 17 ] ;


void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i <= 10 ; ++ i ) {
        fst[ i ] = -1 ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        int dig = ( a[ i ] - '0' ) ;
        if ( fst[ dig ] == -1 ) {
            fst[ dig ] = i ;
        }
    }
    bool fl = false ;
    for ( int j = 0 ; j < 10 ; ++ j ) {
        if ( fst[ j ] == -1 ) { continue ; }
        int x , y ;
        x = 0 ;
        y = j ;
        int i ;
        for ( i = 0 ; i < n ; ++ i ) {
            int cur = ( a[ i ] - '0' ) ;
            if ( i < fst[ j ] ) {
                if ( x > cur ) { break ; }
                if ( cur > j ) { break ; }
                c[ i ] = 1 ;
                x = cur ;
            }
            else if ( i == fst[ j ] ) {
                y = j ;
                c[ i ] = 2 ;
            }
            else {
                if ( cur < j ) {
                    if ( x > cur ) { break ; }
                    c[ i ] = 1 ;
                    x = cur ;
                }
                else if ( cur == j ) {
                    if ( y <= cur ) {
                        c[ i ] = 2 ;
                        y = cur ;
                    }
                    else {
                        c[ i ] = 1 ;
                        x = cur ;
                    }
                }
                else {
                    if ( y > cur ) { break ; }
                    c[ i ] = 2 ;
                    y = cur ;
                }
            }
        }
        if ( i == n ) { fl = true ; break ; }
    }
    if ( fl == false ) { cout << "-\n" ; }
    else {
        for ( int i = 0 ; i < n ; ++ i ) {
            cout << c[ i ] ;
        }
        cout << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}