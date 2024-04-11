#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long h ;
pair < int , int > a[ MAXN ] ;

vector < int > ans ;

void input ( ) {
    scanf ( "%d%I64d" , &n , &h ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 ) ;
    ans.clear ( ) ;
    long long sr = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( sr + a[ i ].first <= h ) {
            ans.push_back ( a[ i ].second ) ;
            sr += a[ i ].first ;
        }
    }
    if ( sr * 2 < h ) {
        printf ( "-1\n" ) ;
        return ;
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
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