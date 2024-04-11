#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
int n ;
vector < int > v[ MAXN ] ;
long long a[ MAXN ] ;
long long sm = 0 ;

long long lft[ MAXN ] ;

bool dfs ( int vertex , long long sr ) {
    int sz = v[ vertex ].size ( ) ;
    lft[ vertex ] = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( dfs ( v[ vertex ][ i ] , sr ) == false ) { return false ; }
        lft[ vertex ] += lft[ v[ vertex ][ i ] ] ;
        if ( lft[ vertex ] > sm ) { lft[ vertex ] = sm ; }
    }
    if ( sz == 0 ) {
        lft[ vertex ] = sr - a[ vertex ] ;
    }
    else {
        lft[ vertex ] -= a[ vertex ] ;
    }
    if ( lft[ vertex ] > sm ) { lft[ vertex ] = sm ; }
    return ( lft[ vertex ] >= 0 ) ;
}


bool f ( long long sr ) {
    return dfs ( 1 , sr ) ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ;
        cin >> x ;
        v[ x ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
}

void solve ( ) {
    long long l , r , mid ;
    l = 0 ;
    r = sm ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( r > 0 && f ( r - 1 ) == true ) { -- r ; }
    cout << r << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}