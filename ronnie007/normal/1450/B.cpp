#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , k ;
pair < int , int > a[ MAXN ] ;

int calc ( int x , int y ) {
    return abs ( a[ x ].first - a[ y ].first ) + abs ( a[ x ].second - a[ y ].second ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        int mx = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            mx = max ( mx , calc ( i , j ) ) ;
        }
        if ( mx <= k ) { printf ( "1\n" ) ; return ; }
    }
    printf ( "-1\n" ) ;
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