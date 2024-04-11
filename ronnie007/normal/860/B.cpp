#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 70007

int n ;
string a[ MAXN ] ;
int sz ;

struct tuhla {
    int val ;
    int to[ 17 ] ;
    tuhla ( ) {
        val = 0 ;
        int i ;
        for ( i = 0 ; i < 17 ; i ++ ) {
            to[ i ] = 0 ;
        }
    }
};
vector < tuhla > v ;
tuhla emp ;

void add ( int i , int coef ) {
    int j , t ;
    int pos = 1 ;
    for ( j = 0 ; j < 9 ; j ++ ) {
        int pos = 1 ;
        for ( t = j ; t < 9 ; t ++ ) {
            int id = ( a[ i ][ t ] - '0' ) ;
            v[ pos ].val += coef * ( 9 - t ) ;
            if ( v[ pos ].to[ id ] == 0 ) {
                v.push_back ( emp ) ;
                sz ++ ;
                v[ pos ].to[ id ] = ( sz - 1 ) ;
            }
            pos = v[ pos ].to[ id ] ;
        }
        v[ pos ].val += coef ;
    }
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    emp = tuhla ( ) ;
    v.resize ( 2 ) ;
    sz = 2 ;
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
        add ( i , 1 ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        add ( i , -1 ) ;
        int len = 17 ;
        int st = 17 ;
        for ( j = 0 ; j < 9 ; j ++ ) {
            int pos = 1 ;
            for ( t = j ; t < 9 ; t ++ ) {
                int id = ( a[ i ][ t ] - '0' ) ;
                pos = v[ pos ].to[ id ] ;
                if ( v[ pos ].val == 0 ) {
                    int cur = ( t - j + 1 ) ;
                    if ( len > cur ) {
                        len = cur ;
                        st = j ;
                    }
                }
            }
        }
        for ( j = 0 ; j < len ; j ++ ) {
            cout << a[ i ][ st + j ] ;
        }
        cout << "\n" ;
        add ( i , 1 ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}