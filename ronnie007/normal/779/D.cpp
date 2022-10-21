#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , m ;
string a , b ;
int w[ MAXN ] ;
int pos[ MAXN ] ;

bool f ( int x ) {
    int i ;
    int id = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( pos[ i ] <= x ) { continue ; }
        if ( a[ i - 1 ] == b[ id ] ) { id ++ ; }
        if ( id == m ) { return true ; }
    }
    return false ;
}

void input ( ) {
    cin >> a >> b ;
    n = a.size ( ) ;
    m = b.size ( ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> w[ i ] ;
        pos[ w[ i ] ] = i ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 0 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { r -- ; }
    printf ( "%d\n" , r ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}