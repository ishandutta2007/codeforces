#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
vector < int > v[ 3 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ; char c ; cin >> x >> c ;
        if ( c == 'G' ) { v[ 0 ].push_back ( x ) ; }
        else if ( c == 'R' ) { v[ 1 ].push_back ( x ) ; }
        else { v[ 2 ].push_back ( x ) ; }
    }
}

void solve ( ) {
    long long ans = 0 ;
    if ( v[ 0 ].empty ( ) == true ) {
        if ( v[ 1 ].empty ( ) == false ) {
            ans += v[ 1 ].back ( ) - v[ 1 ].front ( ) ;
        }
        if ( v[ 2 ].empty ( ) == false ) {
            ans += v[ 2 ].back ( ) - v[ 2 ].front ( ) ;
        }
        cout << ans << "\n" ;
        return ;
    }
    for ( int i = 1 ; i <= 2 ; ++ i ) {
        if ( v[ i ].empty ( ) == false ) {
            if ( v[ i ].front ( ) <= v[ 0 ].front ( ) ) {
                ans += v[ 0 ].front ( ) - v[ i ].front ( ) ;
            }
            if ( v[ 0 ].back ( ) <= v[ i ].back ( ) ) {
                ans += v[ i ].back ( ) - v[ 0 ].back ( ) ;
            }
        }
    }
    int pos1 , pos2 ;
    pos1 = pos2 = 0 ;
    int sz1 = v[ 1 ].size ( ) ;
    int sz2 = v[ 2 ].size ( ) ;
    int k = v[ 0 ].size ( ) ;
    vector < int > aux1 , aux2 ;
    for ( int i = 0 ; i + 1 < k ; ++ i ) {
        while ( pos1 < sz1 && v[ 1 ][ pos1 ] < v[ 0 ][ i ] ) { ++ pos1 ; }
        while ( pos2 < sz2 && v[ 2 ][ pos2 ] < v[ 0 ][ i ] ) { ++ pos2 ; }
        
        aux1.clear ( ) ; aux2.clear ( ) ;
        while ( pos1 < sz1 && v[ 1 ][ pos1 ] < v[ 0 ][ i + 1 ] ) {
            aux1.push_back ( v[ 1 ][ pos1 ++ ] ) ;
        }
        while ( pos2 < sz2 && v[ 2 ][ pos2 ] < v[ 0 ][ i + 1 ] ) {
            aux2.push_back ( v[ 2 ][ pos2 ++ ] ) ;
        }
        long long cand = 2LL * ( v[ 0 ][ i + 1 ] - v[ 0 ][ i ] ) ;

        int mx1 = 0 , mx2 = 0 ;

        int hh1 = aux1.size ( ) , hh2 = aux2.size ( ) ;
        for ( int j = 0 ; j + 1 < hh1 ; ++ j ) {
            mx1 = max ( mx1 , aux1[ j + 1 ] - aux1[ j ] ) ;
        }
        for ( int j = 0 ; j + 1 < hh2 ; ++ j ) {
            mx2 = max ( mx2 , aux2[ j + 1 ] - aux2[ j ] ) ;
        }
        if ( hh1 > 0 ) {
            mx1 = max ( mx1 , aux1.front ( ) - v[ 0 ][ i ] ) ;
            mx1 = max ( mx1 , v[ 0 ][ i + 1 ] - aux1.back ( ) ) ;
        }
        else { mx1 = v[ 0 ][ i + 1 ] - v[ 0 ][ i ] ; }
        
        if ( hh2 > 0 ) {
            mx2 = max ( mx2 , aux2.front ( ) - v[ 0 ][ i ] ) ;
            mx2 = max ( mx2 , v[ 0 ][ i + 1 ] - aux2.back ( ) ) ;
        }
        else { mx2 = v[ 0 ][ i + 1 ] - v[ 0 ][ i ] ; }
        cand = min ( cand , 3LL * ( v[ 0 ][ i + 1 ] - v[ 0 ][ i ] ) - mx1 - mx2 ) ;
        ans += cand ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}