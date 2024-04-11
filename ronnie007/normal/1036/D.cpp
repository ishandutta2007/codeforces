#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 300007

int n , m ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &m ) ;
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%I64d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    int st1 , st2 ;
    st1 = st2 = 0 ;
    int ans = 0 ;
    long long sm1 , sm2 ;
    sm1 = 0 ;
    sm2 = 0 ;
    while ( st1 < n && st2 < m ) {
        st1 ++ ;
        st2 ++ ;
        sm1 = a[ st1 ] ;
        sm2 = b[ st2 ] ;
        while ( st1 <= n && st2 <= m ) {
            if ( sm1 == sm2 ) { break ; }
            if ( sm1 < sm2 ) {
                st1 ++ ;
                sm1 += a[ st1 ] ;
            }
            else {
                st2 ++ ;
                sm2 += b[ st2 ] ;
            }
        }
        ans ++ ;
        if ( sm1 != sm2 ) { printf ( "-1\n" ) ; return ; }
    }
    if ( st1 != n || st2 != m ) { printf ( "-1\n" ) ; return ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}