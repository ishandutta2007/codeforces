#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std ;

#define MAXN 3007
#define LCM 2520


int n ;
int add[ MAXN ] ;
int dp[ MAXN ][ MAXN ] ;
bool vis[ MAXN ][ MAXN ] ;

int sz[ MAXN ] ;
vector < int > v[ MAXN ] ;


void calc ( int st , int val ) {
    if ( vis[ st ][ val ] == true ) { return ; }
    vector < pair < int , int > > log ;
    vector < pair < int , int > > cp ;

    while ( 1 ) {
        log.push_back ( { st , val } ) ;
        cp.push_back ( { st , val } ) ;
        vis[ st ][ val ] = true ;
        int nwst , nwval ;
        nwst = st ;
        nwval = val + add[ st ] ;
        if ( nwval < 0 ) { nwval += LCM ; }
        if ( nwval >= LCM ) { nwval -= LCM ; }
        nwst = v[ st ][ ( nwval % sz[ st ] ) ] ;
        st = nwst , val = nwval ;
        if ( vis[ st ][ val ] == true ) { break ; }
    }
    if ( dp[ st ][ val ] == 0 ) {
        set < int > s ;
        s.clear ( ) ;
        while ( 1 ) {
            pair < int , int > tp = log.back ( ) ;
            log.pop_back ( ) ;
            s.insert ( tp.first ) ;
            if ( tp.first == st && tp.second == val ) { break ; }
        }
        dp[ st ][ val ] = s.size ( ) ;
    }
    int sz = cp.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        dp[ cp[ i ].first ][ cp[ i ].second ] = dp[ st ][ val ] ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &add[ i ] ) ;
        add[ i ] %= LCM ;
        if ( add[ i ] < 0 ) { add[ i ] += LCM ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &sz[ i ] ) ;
        v[ i ].resize ( sz[ i ] ) ;
        for ( int j = 0 ; j < sz[ i ] ; ++ j ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int st , val ;
        scanf ( "%d%d" , &st , &val ) ;
        val %= LCM ;
        if ( val < 0 ) { val += LCM ; }
        calc ( st , val ) ;
        printf ( "%d\n" , dp[ st ][ val ] ) ;
    }
}

int main ( ) {
    ///freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}