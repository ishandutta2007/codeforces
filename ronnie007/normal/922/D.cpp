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
using namespace std ;

#define MAXN 100007

int n ;
struct tuhla {
    string s ;
    int val ;
};
tuhla a[ MAXN ] ;

long long ans ;

bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( 1LL * p1.val * ( p2.s.size ( ) - p2.val ) < 1LL * p2.val * ( p1.s.size ( ) - p1.val ) ) ;
}

void input ( ) {
    cin >> n ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ].s ;
        int sz = a[ i ].s.size ( ) ;
        int cur = 0 ;
        for ( j = 0 ; j < sz ; j ++ ) {
            a[ i ].val += ( a[ i ].s[ j ] == 'h' ) ;
            cur += ( a[ i ].s[ j ] == 's' ) ;
            if ( a[ i ].s[ j ] == 'h' ) {
                ans += cur ;
            }
        }
    }
    sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
    int i ;
    long long cur = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ans += cur * a[ i ].val ;
        cur += ( a[ i ].s.size ( ) - a[ i ].val ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}