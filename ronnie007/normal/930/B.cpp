#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;


int n ;
string a ;
vector < int > v[ 37 ] ;

int used[ 37 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j , t ;
    for ( i = 0 ; i < n ; i ++ ) {
        v[ ( a[ i ] - 'a' ) ].push_back ( i ) ;
    }
    double ret = 0.0000 ;
    for ( t = 0 ; t < 26 ; t ++ ) {
        int sz = v[ t ].size ( ) ;
        if ( sz == 0 ) { continue ; }
        int mx = 0 ;
        for ( i = 1 ; i < n ; i ++ ) {
            for ( j = 0 ; j <= 26 ; j ++ ) {
                used[ j ] = 0 ;
            }
            for ( j = 0 ; j < sz ; j ++ ) {
                int id = ( v[ t ][ j ] + i ) ;
                if ( id >= n ) { id -= n ; }
                int ch = ( a[ id ] - 'a' ) ;
                used[ ch ] ++ ;
            }
            int cur = 0 ;
            for ( j = 0 ; j <= 26 ; j ++ ) {
                if ( used[ j ] == 1 ) { cur ++ ; }
            }
            if ( mx < cur ) { mx = cur ; }
        }
        ret += mx ;
    }
    ret /= n ;
    printf ( "%.12lf\n" , ret ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}