#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
pair < int , int > a[ MAXN ] ;
vector < pair < int , int > > v[ 2 * MAXN ] ;

int mxval ;

map < int , int > w ;
int rv[ 2 * MAXN ] ;

bool used[ 2 * MAXN ] ;
bool h[ 2 * MAXN ] ;

int cnt_v , cnt_e ;

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    ++ cnt_v ;
    used[ vertex ] = true ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( h[ v[ vertex ][ i ].second ] == false ) { ++ cnt_e ; }
        if ( used[ v[ vertex ][ i ].first ] == true ) { continue ; }
        dfs ( v[ vertex ][ i ].first ) ;
    }
}

bool block ( int vertex ) {
    if ( used[ vertex ] == true ) { return false ; }
    int sz = v[ vertex ].size ( ) ;
    used[ vertex ] = true ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( h[ v[ vertex ][ i ].second ] == true ) { continue ; }
        if ( used[ v[ vertex ][ i ].first ] == true ) { return false ; }
        h[ v[ vertex ][ i ].second ] = true ;
        if ( block ( v[ vertex ][ i ].first ) == false ) { return false ; }
    }
    return true ;
}

bool f ( int sr ) {
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        used[ i ] = h[ i ] = false ;
    }
    for ( int i = sr + 1 ; i <= mxval ; ++ i ) {
        if ( block ( i ) == false ) { return false ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            cnt_v = cnt_e = 0 ;
            dfs ( i ) ;
            cnt_e /= 2 ;
            if ( cnt_v < cnt_e ) { return false ; }
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    vector < int > srt ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        srt.push_back ( a[ i ].first ) ;
        srt.push_back ( a[ i ].second ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    mxval = 1 ;
    w[ srt[ 0 ] ] = 1 ;
    rv[ 1 ] = srt[ 0 ] ;
    for ( int i = 1 ; i < 2 * n ; ++ i ) {
        if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        w[ srt[ i ] ] = ++ mxval ;
        rv[ mxval ] = srt[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].first = w[ a[ i ].first ] ;
        a[ i ].second = w[ a[ i ].second ] ;
        v[ a[ i ].first ].push_back ( { a[ i ].second , i } ) ;
        v[ a[ i ].second ].push_back ( { a[ i ].first , i } ) ;
    }
}

void solve ( ) {
    int l , r , mid ;
    r = mxval ;
    l = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        l = max ( l , a[ i ].first ) ;
    }
    if ( f ( r ) == false ) {
        printf ( "-1\n" ) ;
        return ;
    }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    printf ( "%d\n" , rv[ l ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}