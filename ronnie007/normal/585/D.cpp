#include<bits/stdc++.h>
using namespace std ;

#define MAXN 26

int n ;
int a[ MAXN ][ 3 ] ;

map < pair < int , int > , pair < int , string > > w ;

int mxval = -1e9 ;
string ans = "" ;

void init ( int pos , int x , int y , int z , string path ) {
    if ( pos == n + 1 ) {
        int diff1 = y - x ;
        int diff2 = z - x ;
        pair < int , int > aux = { diff1 , diff2 } ;
        if ( w.find ( aux ) == w.end ( ) ) {
            w[ aux ] = { x , path } ;
        }
        else {
            if ( w[ aux ].first < x ) { w[ aux ] = { x , path } ; }
        }
        return ;
    }
    init ( pos + 1 , x + a[ pos ][ 0 ] , y + a[ pos ][ 1 ] , z , path + '2' ) ;
    init ( pos + 1 , x + a[ pos ][ 0 ] , y , z + a[ pos ][ 2 ] , path + '1' ) ;
    init ( pos + 1 , x , y + a[ pos ][ 1 ] , z + a[ pos ][ 2 ] , path + '0' ) ;
}

void get ( int pos , int sr , int x , int y , int z , string path ) {
    if ( pos == sr ) {
        int diff1 = x - y ;
        int diff2 = x - z ;
        pair < int , int > aux = { diff1 , diff2 } ;
        if ( w.find ( aux ) != w.end ( ) ) {
            if ( mxval < x + w[ aux ].first ) {
                mxval = x + w[ aux ].first ;
                ans = path + w[ aux ].second ;
            }
        }
        return ;
    }
    get ( pos + 1 , sr , x + a[ pos ][ 0 ] , y + a[ pos ][ 1 ] , z , path + '2' ) ;
    get ( pos + 1 , sr , x + a[ pos ][ 0 ] , y , z + a[ pos ][ 2 ] , path + '1' ) ;
    get ( pos + 1 , sr , x , y + a[ pos ][ 1 ] , z + a[ pos ][ 2 ] , path + '0' ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 3 ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int mid = ( n + 1 ) / 2 ;
    init ( mid + 1 , 0 , 0 , 0 , "" ) ;
    get ( 1 , mid + 1 , 0 , 0 , 0 , "" ) ;
    if ( ans == "" ) { printf ( "Impossible\n" ) ; }
    else {
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ans[ i ] == '0' ) { printf ( "MW\n" ) ; }
            else if ( ans[ i ] == '1' ) { printf ( "LW\n" ) ; }
            else { printf ( "LM\n" ) ; }
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