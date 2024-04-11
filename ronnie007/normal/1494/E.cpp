#include<bits/stdc++.h>
using namespace std ;

int n , q ;

map < pair < int , int > , int > w ;
int sym , cnt ;

void input ( ) {
    cin >> n >> q ;
}

void solve ( ) {
    while ( q -- ) {
        char type , c ;
        int x , y ;
        cin >> type ;
        if ( type == '+' ) {
            cin >> x >> y >> c ;
            int val = ( c - 'a' + 1 ) ;
            if ( w[ { y , x } ] != 0 ) {
                ++ cnt ;
                sym += ( w[ { y , x } ] == val ) ;
            }
            w[ { x , y } ] = val ;
        }
        else if ( type == '-' ) {
            cin >> x >> y ;
            if ( w[ { y , x } ] != 0 ) {
                -- cnt ;
                sym -= ( w[ { y , x } ] == w[ { x , y } ] ) ;
            }
            w.erase ( { x , y } ) ;
        }
        else {
            cin >> x ;
            if ( ( x % 2 ) == 0 ) {
                if ( sym > 0 ) { cout << "YES\n" ; }
                else { cout << "NO\n" ; }
            }
            else {
                if ( cnt > 0 ) { cout << "YES\n" ; }
                else { cout << "NO\n" ; }
            }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}