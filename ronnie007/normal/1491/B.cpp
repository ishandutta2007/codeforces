#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
long long u , v ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n >> u >> v ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( abs ( a[ i ] - a[ i - 1 ] ) > 1 ) {
            cout << "0\n" ;
            return ;
        }
    }
    long long sr = u + v ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] != a[ i - 1 ] ) { sr = u ; break ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int diff = -2 ; diff <= 2 ; ++ diff ) {
            int aux = a[ i ] + diff ;
            if ( aux < 0 || aux > 1000001 ) { continue ; }
            if ( i == 1 && aux == 0 ) { continue ; }
            if ( i == n && aux == 1000001 ) { continue ; }
            if ( aux == 0 ) {
                bool fl = true ;
                for ( int j = 2 ; j < i - 1 ; ++ j ) {
                    if ( abs ( a[ j ] - a[ j - 1 ] ) > 1 ) { fl = false ; break ; }
                }
                if ( abs ( aux - a[ i - 1 ] ) > 1 ) { fl = false ; }
                if ( fl == true ) { continue ; }
            }
            if ( aux == 1000001 ) {
                bool fl = true ;
                for ( int j = n - 1 ; j > i ; -- j ) {
                    if ( abs ( a[ j ] - a[ j + 1 ] ) > 1 ) { fl = false ; break ; }
                }
                if ( abs ( aux - a[ i + 1 ] ) > 1 ) { fl = false ; }
                if ( fl == true ) { continue ; }
            }
            if ( i > 1 && abs ( aux - a[ i - 1 ] ) > 1 ) {
                sr = min ( sr , 1LL * abs ( diff ) * v ) ;
            }
            else if ( i < n && abs ( aux - a[ i + 1 ] ) > 1 ) {
                sr = min ( sr , 1LL * abs ( diff ) * v ) ;
            }
        }
    }
    cout << sr << "\n" ;
}

int main ( ) {
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