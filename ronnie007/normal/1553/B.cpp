#include<bits/stdc++.h>
using namespace std ;

int n , k ;
string a , b ;

bool f ( int sr , int pos ) {
    int x = sr , y = pos ;
    while ( y > 0 ) {
        -- x , -- y ;
        if ( x < 0 ) { return false ; }
        if ( a[ x ] != b[ y ] ) { return false ; }
    }

    x = sr , y = pos ;
    while ( y < k - 1 ) {
        -- x , ++ y ;
        if ( x < 0 ) { return false ; }
        if ( a[ x ] != b[ y ] ) { return false ; }
    }
    return true ;
}

void input ( ) {
    cin >> a >> b ;
    n = a.size ( ) ;
    k = b.size ( ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < k ; ++ j ) {
            if ( a[ i ] != b[ j ] ) { continue ; }
            if ( f ( i , j ) == true ) {
                cout << "YES\n" ;
                return ;
            }
        }
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