#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 1e6 + 57 ;

int n ;
string a ;

int PI[ MAXN ] ;
int prec[ MAXN ][ 26 ] ;
int fst[ MAXN ][ 26 ] ;
int path[ MAXN ] ;

void calc_init ( ) {
    PI[ 0 ] = PI[ 1 ] = 0 ;
    int l = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        while ( l > 0 && a[ l ] != a[ i - 1 ] ) {
            l = PI[ l ] ;
        }
        if ( a[ l ] == a[ i - 1 ] ) { ++ l ; }
        PI[ i ] = l ;
    }
    for ( int i = 0 ; i <= 12 ; ++ i ) {
        a += a[ 0 ] ;
    }
    for ( int i = 0 ; i <= n + 11 ; ++ i ) {
        for ( int nw = 0 ; nw < 26 ; ++ nw ) {
            fst[ i ][ nw ] = -1 ;
        }
    }
    for ( int i = 0 ; i <= n + 11 ; ++ i ) {
        for ( int nw = 0 ; nw < 26 ; ++ nw ) {
            int tp = 0 ;
            int l = i ;
            int nwval = -1 , ori = -1 ;
            while ( l > 0 && ( a[ l ] - 'a' ) != nw ) {
                path[ ++ tp ] = l ;
                l = PI[ l ] ;
                if ( fst[ l ][ nw ] != -1 ) {
                    nwval = ori = fst[ l ][ nw ] ;
                    if ( ( a[ nwval ] - 'a' ) == nw ) { ++ nwval ; }
                    break ;
                }
            }
            if ( tp == 0 ) {
                path[ ++ tp ] = i ;
            }
            if ( nwval == -1 ) {
                ori = l ;
                if ( ( a[ l ] - 'a' ) == nw ) { ++ l ; }
                nwval = l ;
            }
            for ( int j = 1 ; j <= tp ; ++ j ) {
                prec[ path[ j ] ][ nw ] = nwval ;
                fst[ path[ j ] ][ nw ] = ori ;
            }
        }
    }
}

void solve ( ) {
    int mxval = 33 ;
    cin >> a ;
    n = a.size ( ) ;
    if ( n >= mxval ) {
        calc_init ( ) ;
    }
    int q ;
    cin >> q ;
    string s ;
    while ( q -- ) {
        cin >> s ;
        if ( n < mxval ) {
            string aux = a + s ;
            int sz = aux.size ( ) ;
            PI[ 0 ] = PI[ 1 ] = 0 ;
            int l = 0 ;
            for ( int i = 2 ; i <= sz ; ++ i ) {
                while ( l > 0 && aux[ l ] != aux[ i - 1 ] ) {
                    l = PI[ l ] ;
                }
                if ( aux[ l ] == aux[ i - 1 ] ) { ++ l ; }
                PI[ i ] = l ;
            }
            for ( int i = n + 1 ; i <= sz ; ++ i ) {
                cout << PI[ i ] << " " ;
            }
            cout << "\n" ;
        }
        else {
            int sz = s.size ( ) ;
            int aux = PI[ n ] ;
            for ( int i = 0 ; i < sz ; ++ i ) {
                aux = prec[ aux ][ ( s[ i ] - 'a' ) ] ;
                cout << aux << " " ;
            }
            cout << "\n" ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}