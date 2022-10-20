#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
string a ;

int p[ MAXN ] , c[ MAXN ] ;
int aux_p[ MAXN ] , aux_c[ MAXN ] ;
int cnt[ MAXN ] ;

void input ( ) {
    cin >> n >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        ++ cnt[ ( a[ i ] - 'a' ) ] ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        cnt[ i ] += cnt[ i - 1 ] ;
    }
    for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        int pos = ( a[ i ] - 'a' ) ;
        p[ -- cnt[ pos ] ] = i ;
    }
    c[ p[ 0 ] ] = 0 ;
    for ( int i = 1 ; i < ( 1 << n ) ; ++ i ) {
        if ( a[ p[ i ] ] != a[ p[ i - 1 ] ] ) {
            c[ p[ i ] ] = c[ p[ i - 1 ] ] + 1 ;
        }
        else {
            c[ p[ i ] ] = c[ p[ i - 1 ] ] ;
        }
    }

    for ( int wh = 1 ; wh <= n ; ++ wh ) {
        for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
            cnt[ i ] = 0 ; 
        }
        for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
            int hh = p[ i ] ^ ( 1 << ( wh - 1 ) ) ;
            ++ cnt[ c[ hh ] ] ;
        }
        for ( int i = 1 ; i < ( 1 << n ) ; ++ i ) {
            cnt[ i ] += cnt[ i - 1 ] ;
        }
        for ( int i = ( 1 << n ) - 1 ; i >= 0 ; -- i ) {
            int hh = p[ i ] ^ ( 1 << ( wh - 1 ) ) ;
            aux_p[ -- cnt[ c[ hh ] ] ] = hh ;
        }
        aux_c[ aux_p[ 0 ] ] = 0 ;
        for ( int i = 1 ; i < ( 1 << n ) ; ++ i ) {
            pair < int , int > sr1 = { c[ aux_p[ i - 1 ] ] , c[ aux_p[ i - 1 ] ^ ( 1 << ( wh - 1 ) ) ] } ;
            pair < int , int > sr2 = { c[ aux_p[ i ] ] , c[ aux_p[ i ] ^ ( 1 << ( wh - 1 ) ) ] } ;
            if ( sr1 == sr2 ) {
                aux_c[ aux_p[ i ] ] = aux_c[ aux_p[ i - 1 ] ] ;
            }
            else {
                aux_c[ aux_p[ i ] ] = aux_c[ aux_p[ i - 1 ] ] + 1 ;
            }
        }
        for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
            p[ i ] = aux_p[ i ] ;
            c[ i ] = aux_c[ i ] ; 
        }
    }
    int opt = p[ 0 ] ;
    for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        cout << a[ i ^ opt ] ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}