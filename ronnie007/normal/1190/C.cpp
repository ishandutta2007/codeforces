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

#define MAXN 100007

int n , k ;
string a ;
int pref[ MAXN ] ;

int nxt[ MAXN ][ 2 ] ;
int lst[ MAXN ][ 2 ] ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
    lst[ 0 ][ 0 ] = lst[ 0 ][ 1 ] = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + ( a[ i - 1 ] - '0' ) ) ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            lst[ i ][ j ] = lst[ i - 1 ][ j ] ;
            if ( j == ( a[ i - 1 ] - '0' ) ) {
                lst[ i ][ j ] = i ;
            }
        }
    }
    lst[ n + 1 ][ 0 ] = lst[ n ][ 0 ] ;
    lst[ n + 1 ][ 1 ] = lst[ n ][ 1 ] ;
    nxt[ n + 1 ][ 0 ] = -1 ;
    nxt[ n + 1 ][ 1 ] = -1 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            nxt[ i ][ j ] = nxt[ i + 1 ][ j ] ;
            if ( j == ( a[ i - 1 ] - '0' ) ) {
                nxt[ i ][ j ] = i ;
            }
        }
    }
    nxt[ 0 ][ 0 ] = nxt[ 1 ][ 0 ] ;
    nxt[ 0 ][ 1 ] = nxt[ 1 ][ 1 ] ;
}

void solve ( ) {
    for ( int i = 1 ; i + k - 1 <= n ; ++ i ) {
        int lft = pref[ n ] - ( pref[ i + k - 1 ] - pref[ i - 1 ] ) ;
        if ( lft == n - k || lft == 0 ) {
            cout << "tokitsukaze\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i + k - 1 <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            int st = nxt[ 0 ][ j ] ;
            if ( i <= st && st <= i + k - 1 ) { st = nxt[ i + k ][ j ] ; }
            int en = lst[ n ][ j ] ;
            if ( i <= en && en <= i + k - 1 ) { en = lst[ i - 1 ][ j ] ; }
            if ( en - st + 1 > k ) {
                cout << "once again\n" ;
                return ;
            }
        }
    }
    cout << "quailty\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}