#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n ;
string a[ MAXN ] ;
string b[ MAXN ] ;

int tot ;
char aux[ 3 ] ;

int f ( char c1 , char c2 , char c3 ) {
    aux[ 0 ] = c1 ; aux[ 1 ] = c2 ; aux[ 2 ] = c3 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        b[ i ] = a[ i ] ;
    }
    int ret = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( a[ i ][ j ] != '.' ) {
                if ( aux[ ( i + j ) % 3 ] != '+' && a[ i ][ j ] != aux[ ( i + j ) % 3 ] ) {
                    ++ ret ;
                    if ( b[ i ][ j ] == 'X' ) { b[ i ][ j ] = 'O' ; }
                    else { b[ i ][ j ] = 'X' ; }
                }
            }
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    tot = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            tot += ( a[ i ][ j ] != '.' ) ;
        }
    }
}

void solve ( ) {
    for ( char c1 : { 'O' , 'X' , '+' } ) {
        for ( char c2 : { 'O' , 'X' , '+' } ) {
            if ( c1 == '+' && c2 == '+' ) { continue ; }
            for ( char c3 : { 'O' , 'X' , '+' } ) {
                int cnt1 = 0 ;
                int cnt2 = 0 ;
                int cnt3 = 0 ;
                cnt1 = ( c1 == 'O' ) + ( c2 == 'O' ) + ( c3 == 'O' ) ;
                cnt2 = ( c1 == 'X' ) + ( c2 == 'X' ) + ( c3 == 'X' ) ;
                cnt3 = ( c1 == '+' ) + ( c2 == '+' ) + ( c3 == '+' ) ;
                if ( cnt1 == 0 || cnt2 == 0 || cnt3 == 0 ) { continue ; }
                int ret = f ( c1 , c2 , c3 ) ;
                if ( ret <= tot / 3 ) {
                    for ( int i = 0 ; i < n ; ++ i ) {
                        cout << b[ i ] << "\n" ;
                    }
                    return ;
                }
            }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}