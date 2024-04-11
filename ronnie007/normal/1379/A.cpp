#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

string sr = "abacaba" ;
int len = 7 ;

int f ( string b ) {
    int cnt = 0 ;
    for ( int i = 0 ; i + len <= n ; ++ i ) {
        int j ;
        for ( j = 0 ; j < len ; ++ j ) {
            if ( b[ i + j ] != sr[ j ] ) { break ; }
        }
        cnt += ( j >= len ) ;
    }
    return cnt ;
}

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    string b ;
    for ( int i = 0 ; i + len <= n ; ++ i ) {
        b = a ;
        int j ;
        for ( j = 0 ; j < len ; ++ j ) {
            if ( b[ i + j ] == '?' ) {
                b[ i + j ] = sr[ j ] ;
            }
            if ( b[ i + j ] != sr[ j ] ) { break ; }
        }
        if ( j < len ) { continue ; }
        for ( j = 0 ; j < n ; ++ j ) {
            if ( b[ j ] == '?' ) { b[ j ] = 'z' ; }
        }
        if ( f ( b ) == 1 ) {
            cout << "Yes\n" ;
            cout << b << "\n" ;
            return ;
        }
    }
    cout << "No\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}