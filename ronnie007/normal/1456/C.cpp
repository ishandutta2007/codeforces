#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
int n , k ;
int a[ MAXN ] ;

priority_queue < long long > q ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 , greater < int > ( ) ) ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= k + 1 ; ++ i ) {
        q.push ( 0 ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long aux = q.top ( ) ;
        q.pop ( ) ;
        ans += aux ;
        q.push ( aux + a[ i ] ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}