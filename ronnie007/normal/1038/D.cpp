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

#define MAXN 500007

int n ;
int a[ MAXN ] ;


long long ans ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    if ( n == 1 ) { printf ( "%d\n" , a[ 1 ] ) ; return ; }
    int i ;
    if ( a[ 1 ] < 0 && a[ n ] > 0 ) {
        for ( i = 1 ; i <= n ; i ++ ) {
            ans += max ( a[ i ] , -a[ i ] ) ;
        }
        printf ( "%I64d\n" , ans ) ;
        return ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        a[ i ] = max ( a[ i ] , -a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    ans = -a[ 1 ] ;
    for ( i = 2 ; i <= n ; i ++ ) {
        ans += a[ i ] ;
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