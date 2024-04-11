#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
char op[ MAXN ] ;
int val[ MAXN ] ;

int a[ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        cin >> op[ i ] ;
        if ( op[ i ] == '-' ) { cin >> val[ i ] ; }
    }
}

void solve ( ) {
    stack < int > s ;
    int id = 0 ;
    while ( s.empty ( ) == false ) { s.pop ( ) ; }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( op[ i ] == '+' ) {
            s.push ( ++ id ) ;
        }
        else {
            if ( s.empty ( ) == true ) { cout << "NO\n" ; return ; }
            int aux = s.top ( ) ;
            s.pop ( ) ;
            a[ aux ] = val[ i ] ;
        }
    }
    if ( s.empty ( ) == false ) { cout << "NO\n" ; return ; }
    set < int > w ;
    id = 0 ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( op[ i ] == '+' ) {
            w.insert ( a[ ++ id ] ) ;
        }
        else {
            auto it = w.begin ( ) ;
            if ( (*it) != val[ i ] ) {
                cout << "NO\n" ;
                return ;
            }
            w.erase ( it ) ;
        }
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}