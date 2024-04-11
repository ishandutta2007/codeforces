#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 300007
#define OFFSET 100000

int n , m ;
pair < int , int > a[ MAXN ] ;

int hr[ MAXN ] ;
int curhr[ MAXN ] ;

int vr[ MAXN ] ;
int curvr[ MAXN ] ;

int diag[ MAXN ] ;
int curdiag[ MAXN ] ;

int antidiag[ MAXN ] ;
int curantidiag[ MAXN ] ;

int ret[ 17 ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        hr[ a[ i ].first ] ++ ;
        vr[ a[ i ].second ] ++ ;
        diag[ a[ i ].first - a[ i ].second + OFFSET ] ++ ;
        antidiag[ a[ i ].first + a[ i ].second ] ++ ;
    }
    sort ( a + 1 , a + m + 1 ) ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int ans = 0 ;
        ans += ( curhr[ a[ i ].first ] != 0 ) ;
        ans += ( curvr[ a[ i ].second ] != 0 ) ;
        ans += ( curdiag[ a[ i ].first - a[ i ].second + OFFSET ] != 0 ) ;
        ans += ( curantidiag[ a[ i ].first + a[ i ].second ] != 0 ) ;

        ans += ( curhr[ a[ i ].first ] != ( hr[ a[ i ].first ] - 1 ) ) ;
        ans += ( curvr[ a[ i ].second ] != ( vr[ a[ i ].second ] - 1 ) ) ;
        ans += ( curdiag[ a[ i ].first - a[ i ].second + OFFSET ] != ( diag[ a[ i ].first - a[ i ].second + OFFSET ] - 1 ) ) ;
        ans += ( curantidiag[ a[ i ].first + a[ i ].second ] != ( antidiag[ a[ i ].first + a[ i ].second ] - 1 ) ) ;

        ret[ ans ] ++ ;

        curhr[ a[ i ].first ] ++ ;
        curvr[ a[ i ].second ] ++ ;
        curdiag[ a[ i ].first - a[ i ].second + OFFSET ] ++ ;
        curantidiag[ a[ i ].first + a[ i ].second ] ++ ;
    }
    for ( i = 0 ; i < 9 ; i ++ ) {
        printf ( "%d " , ret[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}