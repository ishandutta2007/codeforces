#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAXVAL 7001


int n , q ;
bitset < 7001 > f[ MAXN ] ;

bitset < 7001 > mask[ MAXVAL ] ;
bitset < 7001 > inc[ MAXVAL ] ;

bool sqfree[ MAXVAL ] ;

bitset < 7001 > aux ;

void init ( ) {
    for ( int i = 0 ; i < MAXVAL ; ++ i ) {
        sqfree[ i ] = true ;
        for ( int j = 2 ; j * j <= i ; ++ j ) {
            if ( ( i % ( j * j ) ) == 0 ) {
                sqfree[ i ] = false ;
                break ;
            }
        }
    }
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        for ( int j = 1 ; j * i < MAXVAL ; ++ j ) {
            mask[ j * i ][ i ] = 1 ;
            if ( sqfree[ j ] == true ) {
                inc[ i ][ j * i ] = 1 ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> q ;
}

void solve ( ) {
    int type , x , y , z ;
    while ( q -- ) {
        cin >> type ;
        if ( type == 1 ) {
            cin >> x >> y ;
            f[ x ] = mask[ y ] ;
        }
        else if ( type == 2 ) {
            cin >> x >> y >> z ;
            f[ x ] = ( f[ y ] ^ f[ z ] ) ;
        }
        else if ( type == 3 ) {
            cin >> x >> y >> z ;
            f[ x ] = ( f[ y ] & f[ z ] ) ;
        }
        else {
            cin >> x >> y ;
            aux = ( f[ x ] & inc[ y ] ) ;
            cout << ( aux.count ( ) % 2 ) ;
        }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}