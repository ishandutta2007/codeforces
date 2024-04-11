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

#define MAXN 400007

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int ans = 0 ;
    int init_cnt ;
    for ( int i = 25 ; i >= 0 ; -- i ) {
        int st = 1 ;
        int sr = (1<<i) ;
        long long aux = 1LL * init_cnt * ( n - init_cnt ) ;
        for ( int j = n ; j >= 1 ; -- j ) {
            while ( st < j && a[ j ] + a[ st ] < sr ) { ++ st ; }
            if ( st >= j ) { break ; }
            aux += ( j - st ) ;
        }
        ans += ( aux & 1 ) * (1<<i) ;
        if ( i == 0 ) { break ; }
        init_cnt = 0 ;
        for ( int j = n ; j >= 1 ; -- j ) {
            if ( ( a[ j ] & (1<<(i-1)) ) != 0 ) {
                a[ j ] -= (1<<(i-1)) ;
                ++ init_cnt ;
            }
        }
        sort ( a + 1 , a + n + 1 ) ;
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}