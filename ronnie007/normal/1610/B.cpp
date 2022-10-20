#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int l , r ;

bool f ( int sr ) {
    int tp = 0 ;
    for ( int i = l ; i <= r ; ++ i ) {
        if ( a[ i ] == sr ) { continue ; }
        b[ ++ tp ] = a[ i ] ;
    }
    for ( int i = 1 ; i <= tp ; ++ i ) {
        if ( b[ i ] != b[ tp - i + 1 ] ) {
            return false ;
        }
    }
    return true ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {

    l = 1 , r = n ;
    while ( l < r && a[ l ] == a[ r ] ) {
        ++ l , -- r ;
    }
    if ( l >= r ) {
        cout << "YES\n" ;
        return ;
    }
    if ( f ( a[ l ] ) == true || f ( a[ r ] ) == true ) {
        cout << "YES\n" ;
        return ;
    }
    cout << "NO\n" ;
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