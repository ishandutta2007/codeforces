#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
struct tuhla {
    char type ;
    string s ;
};

tuhla a[ MAXN ] ;

int f[ 37 ] ;
int p[ 37 ] ;
int aux[ 37 ] ;

int check ( ) {
    int br = 0 ;
    int i ;
    int lst = -1 ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        br += f[ i ] ;
        if ( f[ i ] == 1 ) { lst = i ; }
    }
    if ( br == 1 ) { return lst ; }
    return -1 ;
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ].type >> a[ i ].s ;
    }
}

void solve ( ) {
    int i , j ;
    int sz ;
    int ans = 0 ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        f[ i ] = 1 ;
        p[ i ] = 0 ;
    }
    int fl = -1 ;
    for ( i = 1 ; i < n ; i ++ ) {
        fl = check ( ) ;
        sz = a[ i ].s.size ( ) ;
        if ( a[ i ].type == '.' ) {
            for ( j = 0 ; j < sz ; j ++ ) {
                f[ ( a[ i ].s[ j ] - 'a' ) ] = 0 ;
            }
        }
        else if ( a[ i ].type == '!' ) {
            if ( fl >= 0 ) { ans ++ ; }
            for ( j = 0 ; j < 26 ; j ++ ) {
                aux[ j ] = 0 ;
            }
            for ( j = 0 ; j < sz ; j ++ ) {
                aux[ ( a[ i ].s[ j ] - 'a' ) ] = 1 ;
            }
            for ( j = 0 ; j < 26 ; j ++ ) {
                if ( f[ j ] == 1 && aux[ j ] == 0 ) { f[ j ] = 0 ; }
            }
        }
        else {
            if ( fl >= 0 ) {
                ans ++ ;
            }
            f[ ( a[ i ].s[ 0 ] - 'a' ) ] = 0 ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}