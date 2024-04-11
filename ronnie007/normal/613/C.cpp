#include<bits/stdc++.h>
using namespace std ;

int n ;
int cnt[ 37 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> cnt[ i ] ;
    }
}

void solve ( ) {
    int odd = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        odd += ( cnt[ i ] & 1 ) ;
    }
    if ( odd > 1 ) {
        cout << "0\n" ;
        for ( int i = 0 ; i < n ; ++ i ) {
            while ( cnt[ i ] -- ) {
                cout << char ( 'a' + i ) ;
            }
        }
        cout << "\n" ;
    }
    else if ( odd == 1 ) {
        int w = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            w = __gcd ( w , cnt[ i ] ) ;
        }
        cout << w << "\n" ;
        string h = "" ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( cnt[ i ] & 1 ) != 0 ) { continue ; }
            for ( int j = 0 ; j < ( cnt[ i ] / w ) / 2 ; ++ j ) {
                h += char ( 'a' + i ) ;
            }
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( cnt[ i ] & 1 ) == 0 ) { continue ; }
            for ( int j = 0 ; j < ( cnt[ i ] / w ) ; ++ j ) {
                h += char ( 'a' + i ) ;
            }
        }
        for ( int i = n - 1 ; i >= 0 ; -- i ) {
            if ( ( cnt[ i ] & 1 ) != 0 ) { continue ; }
            for ( int j = 0 ; j < ( cnt[ i ] / w ) / 2 ; ++ j ) {
                h += char ( 'a' + i ) ;
            }
        }
        for ( int i = 0 ; i < w ; ++ i ) {
            cout << h ;
        }
        cout << "\n" ;
    }
    else {
        int w = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            w = __gcd ( w , cnt[ i ] ) ;
        }
        cout << w << "\n" ;
        string h = "" ;
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j < ( cnt[ i ] / w ) ; ++ j ) {
                h += char ( 'a' + i ) ;
            }
        }
        string rv = "" ;
        int sz = h.size ( ) ;
        for ( int i = sz - 1 ; i >= 0 ; -- i ) {
            rv += h[ i ] ;
        }
        for ( int i = 0 ; i < w ; ++ i ) {
            if ( ( i & 1 ) == 0 ) { cout << h ; }
            else { cout << rv ; }
        }
        cout << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}