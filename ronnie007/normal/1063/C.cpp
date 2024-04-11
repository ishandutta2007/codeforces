#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
bool fl ;

string ask ( int x , int y ) {
    cout << x << " " << y << "\n" ;
    fflush ( stdout ) ;
    string ret ;
    cin >> ret ;
    return ret ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    string init = ask ( 0 , 0 ) ;
    if ( n == 1 ) {
        cout << "1 0 1 1\n" ;
        fflush ( stdout ) ;
        return ;
    }
    string hh = ask ( 0 , 1000000000 ) ;
    if ( hh != init ) { fl = true ; }
    if ( n == 2 ) {
        if ( fl == true ) {
            cout << "0 1 1 1\n" ;
            fflush ( stdout ) ;
        }
        else {
            cout << "1 0 1 1\n" ;
            fflush ( stdout ) ;
        }
        return ;
    }
    int add = 0 ;
    for ( int i = n - 2 ; i >= 1 ; -- i ) {
        int x = add + (1<<i) ;
        string ret = ask ( x , 0 ) ;
        if ( ret == init ) { add += (1<<i) ; }
    }
    if ( fl == false ) {
        cout << add + 1 << " 1 " << add + 2 << " 1000000000\n" ;
        fflush ( stdout ) ;
    }
    else {
        cout << "0 999999999 " << add + 1 << " 2\n" ;
        fflush ( stdout ) ;
    }
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}