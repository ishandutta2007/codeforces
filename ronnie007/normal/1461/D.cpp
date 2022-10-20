#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , q ;
int a[ MAXN ] ;

int lst[ MAXN ] ;
long long pref[ MAXN ] ;

set < long long > s ;

void f ( int l , int r ) {
    if ( l > r ) { return ; }
    s.insert ( pref[ r ] - pref[ l - 1 ] ) ;
    if ( a[ l ] == a[ r ] ) { return ; }
    int sr = ( a[ l ] + a[ r ] ) / 2 ;
    int mid = lst[ sr ] ;
    f ( l , mid ) ;
    f ( mid + 1 , r ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
    }
}

void solve ( ) {
    int pos = 0 ;
    for ( int i = 1 ; i <= 1000000 ; ++ i ) {
        while ( pos < n && a[ pos + 1 ] <= i ) { ++ pos ; }
        lst[ i ] = pos ;
    }
    s.clear ( ) ;
    f ( 1 , n ) ;
    while ( q -- ) {
        long long x ;
        scanf ( "%I64d" , &x ) ;
        if ( s.find ( x ) != s.end ( ) ) { printf ( "Yes\n" ) ; }
        else { printf ( "No\n" ) ; }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}