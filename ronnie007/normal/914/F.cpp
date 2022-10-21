#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
string a ;

bitset < MAXN > f[ 26 ] , full ;
bitset < MAXN > aux ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        f[ ( a[ i ] - 'a' ) ][ i ] = 1 ;
        full[ i ] = 1 ;
    }
    int q ; cin >> q ;
    while ( q -- ) {
        int type ;
        cin >> type ;
        if ( type == 1 ) {
            int pos ; char c ;
            cin >> pos >> c ; -- pos ; 
            f[ ( a[ pos ] - 'a' ) ][ pos ] = 0 ;
            a[ pos ] = c ;
            f[ ( a[ pos ] - 'a' ) ][ pos ] = 1 ;
        }
        else {
            int l , r ; string s ;
            cin >> l >> r >> s ; -- l ; -- r ;
            int sz = s.size ( ) ;
            if ( sz > r - l + 1 ) {
                cout << "0\n" ;
                continue ; 
            }
            aux = full ;
            for ( int i = 0 ; i < sz ; ++ i ) {
                aux &= ( f[ ( s[ i ] - 'a' ) ] >> i ) ;
            }
            cout << ( aux >> l ).count ( ) - ( aux >> ( r - sz + 2 ) ).count ( ) << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}