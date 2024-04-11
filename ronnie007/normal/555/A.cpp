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
vector < int > v[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        v[ i ].resize ( sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        ans += ( sz - 1 ) ;
        if ( v[ i ][ 0 ] == 1 ) {
            for ( int j = 1 ; j < sz ; ++ j ) {
                if ( v[ i ][ j ] != ( j + 1 ) ) { break ; }
                ans -= 2 ;
            }
        }
    }
    ans += ( n - 1 ) ;
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}