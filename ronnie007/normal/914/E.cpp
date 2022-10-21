#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;

string a ;
int letter[ MAXN ] ;

int mask[ MAXN ] ;
int subtree[ MAXN ] ;

int used[ MAXN ] ;

long long tot ;
long long br[ (1<<21) ] ;
long long add[ MAXN ] ;
long long dumb[ MAXN ] ;

long long ans[ MAXN ] ;

void calc_subtree ( int vertex , int prv ) {
    tot ++ ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] == 1 ) { continue ; }
        calc_subtree ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
    }
}

int get_centroid ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] == 1 ) { continue ; }
        if ( subtree[ v[ vertex ][ i ] ] > ( tot / 2 ) ) {
            return get_centroid ( v[ vertex ][ i ] , vertex ) ;
        }
    }
    return vertex ;
}

void rec_add ( int vertex , int prv , int coef ) {
    mask[ vertex ] ^= ( 1 << letter[ vertex ] ) ;
    br[ mask[ vertex ] ] += coef ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        mask[ v[ vertex ][ i ] ] = mask[ vertex ] ;
        rec_add ( v[ vertex ][ i ] , vertex , coef ) ;
    }
}
void rec_calc ( int vertex , int prv , int init ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    add[ vertex ] = dumb[ vertex ] = 0 ;
    for ( i = 0 ; i < 20 ; i ++ ) {
        int h = ((1<<i)^mask[ vertex ] ) ;
        h = ( h ^ ( 1 << letter[ init ] ) ) ;
        add[ vertex ] += br[ h ] ;
        if ( ( mask[ vertex ] ^ ( 1 << letter[ init ] ) ) == (1<<i) ) { dumb[ vertex ] ++ ; }
    }
    add[ vertex ] += br[ ( mask[ vertex ]^( 1 << letter[ init ] ) ) ] ;
    if ( ( mask[ vertex ] ^ ( 1 << letter[ init ] ) ) == 0 ) { dumb[ vertex ] ++ ; }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        rec_calc ( v[ vertex ][ i ] , vertex , init ) ;
        add[ vertex ] += add[ v[ vertex ][ i ] ] ;
        dumb[ vertex ] += dumb[ v[ vertex][ i ] ] ;
    }
    ans[ vertex ] += add[ vertex ] + dumb[ vertex ] ;
}

void decompose ( int vertex ) {
    tot = 0 ;
    calc_subtree ( vertex , -1 ) ;
    int cen = get_centroid ( vertex , -1 ) ;
    used[ cen ] = 1 ;
    int i ;
    int sz = v[ cen ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ cen ][ i ] ] != 0 ) { continue ; }
        decompose ( v[ cen ][ i ] ) ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ cen ][ i ] ] != 0 ) { continue ; }
        mask[ v[ cen ][ i ] ] = 0 ;
        rec_add ( v[ cen ][ i ] , cen , 1 ) ;
    }
    long long nw = 0 ;
    long long smdumb = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ cen ][ i ] ] != 0 ) { continue ; }
        mask[ v[ cen ][ i ] ] = 0 ;
        rec_add ( v[ cen ][ i ] , cen , -1 ) ;
        rec_calc ( v[ cen ][ i ] , cen , cen ) ;
        mask[ v[ cen ][ i ] ] = 0 ;
        rec_add ( v[ cen ][ i ] , cen , 1 ) ;
        nw += add[ v[ cen ][ i ] ] ;
        smdumb += dumb[ v[ cen ][ i ] ] ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ cen ][ i ] ] != 0 ) { continue ; }
        mask[ v[ cen ][ i ] ] = 0 ;
        rec_add ( v[ cen ][ i ] , cen , -1 ) ;
    }
    used[ cen ] = 0 ;
    ans[ cen ] += ( nw / 2 ) + smdumb ;
}


void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    cin >> a ;
    for ( i = 1 ; i <= n ; i ++ ) {
        letter[ i ] = ( a[ i - 1 ] - 'a' ) ;
        ans[ i ] = 1 ;
    }
}

void solve ( ) {
    decompose ( 1 ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cout << ans[ i ] ;
        if ( i == n ) { cout << "\n" ; }
        else { cout << " " ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}