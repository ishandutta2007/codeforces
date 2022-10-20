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

#define MAXN 1007

int n ;
int mask[ MAXN ] ;
long long bit[ 13 ] ;
vector < int > v[ 13 ] ;

long long ans[ MAXN ] ;

void input ( ) {
    cin >> n ;
    int id = 0 ;
    for ( int i = 0 ; i < (1<<13) ; ++ i ) {
        if ( id >= n ) { break ; }
        int cnt = 0 ;
        int x = i ;
        while ( x > 0 ) {
            ++ cnt , x &= ( x - 1 ) ;
        }
        if ( cnt == 6 ) { mask[ ++ id ] = i ; }
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 13 ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( mask[ j ] & (1<<i) ) > 0 ) {
                v[ i ].push_back ( j ) ;
            }
        }
    }
    for ( int i = 0 ; i < 13 ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        if ( sz == 0 ) { continue ; }
        cout << "? " << sz ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            cout << " " << v[ i ][ j ] ;
        }
        cout << "\n" ;
        fflush ( stdout ) ;
        cin >> bit[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 13 ; ++ j ) {
            int bit1 = ( mask[ i ] & (1<<j) ) ;
            if ( bit1 > 0 ) { bit1 = 1 ; }
            if ( bit1 != 1 ) {
                ans[ i ] |= bit[ j ] ;
            }            
        }
    }
    cout << "!" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << " " << ans[ i ] ;
    }
    cout << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}