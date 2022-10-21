#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MAXN 10007

int n ;

int tot0 , tot1 ;

string a ;

bool f[ MAXN ] ;
int br0[ MAXN ] ;
int br1[ MAXN ] ;

void calc ( int where , int l , int r ) {
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        a[ i ] = '0' ;
    }
    for ( i = l - 1 ; i <= r - 1 ; i ++ ) {
        a[ i ] = '1' ;
    }
    cout << "? " << a << "\n" ;
    fflush ( stdout ) ;
    int cur0 , cur1 ;
    cin >> cur0 ;
    int diff = cur0 - tot1 ;
    int sm = r - l + 1 ;
    br0[ where ] = ( sm + diff ) / 2 ;
    br1[ where ] = sm - br0[ where ] ;
}

int get0 ( int where , int l , int r ) {
    if ( br1[ where ] == 0 ) { return l ; }
    if ( l == r ) { return l ; }
    int mid = ( l + r ) / 2 ;
    if ( f[ 2 * where ] == false ) {
        f[ 2 * where ] = true ;
        calc ( 2 * where , l , mid ) ;
        br0[ 2 * where + 1 ] = br0[ where ] - br0[ 2 * where ] ;
        br1[ 2 * where + 1 ] = br1[ where ] - br1[ 2 * where ] ;
        f[ 2 * where + 1 ] = true ;
    }
    if ( br0[ 2 * where ] != 0 && br1[ 2 * where ] != 0 ) {
        return get0 ( 2 * where , l , mid ) ;
    }
    else if ( br0[ 2 * where + 1 ] == 0 ) {
        return get0 ( 2 * where , l , mid ) ;
    }
    else {
        return get0 ( 2 * where + 1 , mid + 1 , r ) ;
    }
}

int get1 ( int where , int l , int r ) {
    if ( br0[ where ] == 0 ) { return l ; }
    if ( l == r ) { return l ; }
    int mid = ( l + r ) / 2 ;
    if ( f[ 2 * where ] == false ) {
        f[ 2 * where ] = true ;
        calc ( 2 * where , l , mid ) ;
        br0[ 2 * where + 1 ] = br0[ where ] - br0[ 2 * where ] ;
        br1[ 2 * where + 1 ] = br1[ where ] - br1[ 2 * where ] ;
        f[ 2 * where + 1 ] = true ;
    }
    if ( br1[ 2 * where ] != 0 ) {
        return get1 ( 2 * where , l , mid ) ;
    }
    else {
        return get1 ( 2 * where + 1 , mid + 1 , r ) ;
    }
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        a += '0' ;
    }
    cout << "? " << a << "\n" ;
    fflush ( stdout ) ;
    cin >> tot1 ;
    tot0 = n - tot1 ;
    br0[ 1 ] = tot0 ;
    br1[ 1 ] = tot1 ;
}

void solve ( ) {
    int pos0 = get0 ( 1 , 1 , n ) ;
    int pos1 = get1 ( 1 , 1 , n ) ;
    cout << "! " << pos0 << " " << pos1 << "\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}