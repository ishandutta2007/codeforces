#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 127

int n , m ;
string a[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i , j ;
    int mxx = -1 ;
    int mnx = n + 5 ;
    int mxy = -1 ;
    int mny = m + 5 ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            if ( a[ i ][ j ] == 'B' ) {
                mxx = max ( mxx , i ) ;
                mnx = min ( mnx , i ) ;
                mxy = max ( mxy , j ) ;
                mny = min ( mny , j ) ;
            }
        }
    }
    int add = ( mxx - mnx ) / 2 ;
    mnx += add ;
    mny += add ;
    cout << mnx + 1 << " " << mny + 1 << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}