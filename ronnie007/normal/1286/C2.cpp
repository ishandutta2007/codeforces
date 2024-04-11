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

int n ;
string a ;

int cnt[ 3 ][ MAXN ][ 27 ] ;
int hh[ 27 ] ;

void extr ( ) {
    int mid = ( n + 1 ) >> 1 ;
    for ( int i = 1 ; i <= mid ; ++ i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            if ( cnt[ 0 ][ i ][ j ] != cnt[ 1 ][ i ][ j ] ) {
                a[ i - 1 ] = char ( 'a' + j ) ;
                -- cnt[ 0 ][ i ][ j ] ;
                break ;
            }
        }
        for ( int j = 0 ; j < i ; ++ j ) {
            -- cnt[ 0 ][ i + 1 ][ ( a[ j ] - 'a' ) ] ;
        }
    }
}

void input ( ) {
    cin >> n ;
    a.resize ( n ) ;
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
    if ( n == 2 ) {
        string b ;
        cout << "? 1 1\n" ;
        fflush ( stdout ) ;
        cin >> a ;
        cout << "? 2 2\n" ;
        fflush ( stdout ) ;
        cin >> b ;
        cout << "! " << a << b << "\n" ;
        fflush ( stdout ) ;
        return ;
    }
    int mid = ( n + 1 ) >> 1 ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        int aux = 0 ;
        if ( i == 0 ) {
            cout << "? 1 " << mid << "\n" ;
            aux = ( mid * ( mid + 1 ) ) >> 1 ;
        }
        if ( i == 1 ) {
            cout << "? 2 " << mid << "\n" ;
            aux = ( ( mid - 1 ) * mid ) >> 1 ;
        }
        if ( i == 2 ) {
            cout << "? 1 " << n << "\n" ;
            aux = ( n * ( n + 1 ) ) >> 1 ;
        }
        fflush ( stdout ) ;
        for ( int j = 0 ; j < aux ; ++ j ) {
            int len ;
            string s ;
            cin >> s ;
            len = s.size ( ) ;
            for ( int t = 0 ; t < len ; ++ t ) {
                ++ cnt[ i ][ len ][ ( s[ t ] - 'a' ) ] ;
            }
        }
    }
    extr ( ) ;
    int id = 2 ;
    for ( int i = n - 1 ; i >= mid ; -- i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            hh[ j ] = cnt[ 2 ][ id ][ j ] - cnt[ 2 ][ id - 1 ][ j ] ;
        }
        for ( int j = 0 ; j < n - i ; ++ j ) {
            ++ hh[ ( a[ j ] - 'a' ) ] ;
        }
        for ( int j = i + 1 ; j < n ; ++ j ) {
            ++ hh[ ( a[ j ] - 'a' ) ] ;
        }
        for ( int j = 0 ; j < 26 ; ++ j ) {
            if ( hh[ j ] < cnt[ 2 ][ 1 ][ j ] ) {
                a[ i ] = char ( j + 'a' ) ;
            }
        }
        ++ id ;
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