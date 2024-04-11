#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        b[ i ] = { a[ i ] , i } ;
    }
    sort ( b + 1 , b + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ b[ i ].second ] = i ;
    }
}

void solve ( ) {
    int lft = n ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i + 1 ] == a[ i ] + 1 ) { -- lft ; }
    }
    if ( lft <= k ) {
        cout << "Yes\n" ;
        return ;
    }
    cout << "No\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}