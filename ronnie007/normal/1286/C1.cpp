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

#define MAXN 107
#define lim 26

int n ;

string a ;

int v[ MAXN ][ 32 ] ;
int aux[ MAXN ][ 32 ] ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "? 1 1\n" ;
        fflush ( stdout ) ;
        cin >> a ;
        cout << "! " << a << "\n" ;
        fflush ( stdout ) ;
        return ;
    }
    a.resize ( n ) ;
    string ret ;

    
    cout << "? 1 " << n << "\n" ;
    fflush ( stdout ) ;
    for ( int i = 1 ; i <= n * ( n + 1 ) / 2 ; ++ i ) {
        cin >> ret ;
        int sz = ret.size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int val = ( ret[ j ] - 'a' ) ;
            ++ v[ sz ][ val ] ;
        }
    }
    cout << "? 2 " << n << "\n" ;
    fflush ( stdout ) ;
    for ( int i = 1 ; i <= ( n - 1 ) * n / 2 ; ++ i ) {
        cin >> ret ;
        int sz = ret.size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int val = ( ret[ j ] - 'a' ) ;
            ++ aux[ sz ][ val ] ;
        }
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < lim ; ++ j ) {
            if ( v[ i ][ j ] != aux[ i ][ j ] ) {
                a[ i - 1 ] = char( 'a' + j ) ;
                -- v[ i ][ j ] ;
                break ;
            }
        }
        for ( int j = 0 ; j < i ; ++ j ) {
            -- v[ i + 1 ][ ( a[ j ] - 'a' ) ] ;
        }
    }
    cout << "! " << a << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}