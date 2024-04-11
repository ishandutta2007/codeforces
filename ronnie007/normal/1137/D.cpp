#include<bits/stdc++.h>
using namespace std ;




void input ( ) {

}

void solve ( ) {
    while ( 1 ) {
        int sz ;        
        cout << "next 1\n" ;
        fflush ( stdout ) ;

        cin >> sz ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            string foo ;
            cin >> foo ;
        }


        cout << "next 0 1\n" ;
        fflush ( stdout ) ;

        cin >> sz ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            string foo ;
            cin >> foo ;
        }
        if ( sz == 2 ) {
            break ;
        }
    }
    while ( 1 ) {
        cout << "next 0 1 2 3 4 5 6 7 8 9\n" ;
        fflush ( stdout ) ;
        int sz ;
        cin >> sz ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            string foo ;
            cin >> foo ;
        }
        if ( sz == 1 ) {
            cout << "done\n" ;
            fflush ( stdout ) ;
            return ;
        }
    }
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}