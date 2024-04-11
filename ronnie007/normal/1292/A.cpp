#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007

int n , q ;
bool f[ MAXN ][ 3 ] ;
int cnt = 0 ;

bool blocked ( int st ) {
    if ( st == 0 || st == n ) { return false ; }
    if ( f[ st ][ 1 ] == true && f[ st ][ 2 ] == true ) { return true ; }
    if ( f[ st + 1 ][ 1 ] == true && f[ st + 1 ][ 2 ] == true ) { return true ; }
    if ( f[ st ][ 1 ] == true && f[ st + 1 ][ 2 ] == true ) { return true ; }
    if ( f[ st ][ 2 ] == true && f[ st + 1 ][ 1 ] == true ) { return true ; }
    return false ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
}

void solve ( ) {
    while ( q -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( f[ y ][ x ] == false ) {
            bool prv = blocked ( y - 1 ) ;
            f[ y ][ x ] = true ;
            if ( blocked ( y - 1 ) != prv ) { ++ cnt ; }
            f[ y ][ x ] = false ;
            prv = blocked ( y ) ;
            f[ y ][ x ] = true ;
            if ( blocked ( y ) != prv ) { ++ cnt ; }
        }
        else {
            bool prv = blocked ( y - 1 ) ;
            f[ y ][ x ] = false ;
            if ( blocked ( y - 1 ) != prv ) { -- cnt ; }
            f[ y ][ x ] = true ;
            prv = blocked ( y ) ;
            f[ y ][ x ] = false ;
            if ( blocked ( y ) != prv ) { -- cnt ; }
        }
        if ( cnt == 0 ) { printf ( "Yes\n" ) ; }
        else { printf ( "No\n" ) ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}