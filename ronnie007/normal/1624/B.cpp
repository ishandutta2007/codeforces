#include<bits/stdc++.h>
using namespace std ;

long long a[ 3 ] ;

void input ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    long long diff1 = a[ 2 ] - a[ 1 ] ;
    long long targ = a[ 1 ] - diff1 ;
    if ( targ % a[ 0 ] == 0 && targ / a[ 0 ] > 0 ) {
        cout << "YES\n" ;
        return ;
    }

    long long diff2 = a[ 1 ] - a[ 0 ] ;
    targ = a[ 1 ] + diff2 ;
    if ( targ % a[ 2 ] == 0 && targ / a[ 2 ] > 0 ) {
        cout << "YES\n" ;
        return ;
    }
    
    targ = ( a[ 0 ] + a[ 2 ] ) ;
    if ( targ % 2 == 0 ) {
        targ /= 2 ;
        if ( targ % a[ 1 ] == 0 && targ / a[ 1 ] > 0 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
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