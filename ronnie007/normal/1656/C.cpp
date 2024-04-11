#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int cnt0 , cnt1 ;
    cnt0 = cnt1 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == 0 ) { ++ cnt0 ; }
        if ( a[ i ] == 1 ) { ++ cnt1 ; }
    }
    if ( cnt0 > 0 && cnt1 > 0 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( cnt0 == 0 && cnt1 == 0 ) {
        cout << "YES\n" ;
        return ;
    }
    if ( cnt0 > 0 ) {
        cout << "YES\n" ;
        return ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] + 1 ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}