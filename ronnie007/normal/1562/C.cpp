#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n >> a ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i - 1 ] == '0' ) {
            if ( i - 1 >= ( n / 2 ) ) {
                cout << "1 " << i << " " ;
                cout << "1 " << i - 1 << "\n" ;
            }
            else {
                cout << i << " " << n << " " ;
                cout << i + 1 << " " << n << "\n" ;
            }
            return ;
        }
    }
    if ( n == 2 ) {
        cout << "1 1 2 2\n" ;
        return ;
    }
    cout << "2 " << n << " 1 " << n - 1 << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}