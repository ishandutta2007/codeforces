#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int n ;
string a[ 2 ] ;
vector < pair < int , int > > v[ 2 ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        cin >> a[ i ] ;
    }
    if ( a[ 0 ][ 0 ] != a[ 1 ][ 0 ] ) {
        cout << "-1\n" ;
        return ;
    }
    if ( a[ 0 ][ n - 1 ] != a[ 1 ][ n - 1 ] ) {
        cout << "-1\n" ;
        return ;
    }
    v[ 0 ].clear ( ) ; v[ 1 ].clear ( ) ;
    ll ans = 0 ;
    for ( int wh = 0 ; wh < 2 ; ++ wh ) {
        int cons = 0 ;
        a[ wh ] += '0' ;
        for ( int i = 0 ; i <= n ; ++ i ) {
            if ( a[ wh ][ i ] == '1' ) { ++ cons ; }
            else {
                if ( cons > 0 ) {
                    v[ wh ].push_back ( { i - cons , i - 1 } ) ;
                    cons = 0 ;
                }
            }
        }
    }
    if ( (int)v[ 0 ].size ( ) != (int)v[ 1 ].size ( ) ) {
        cout << "-1\n" ;
        return ;
    }
    int sz = v[ 0 ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        ans += abs ( v[ 0 ][ i ].first - v[ 1 ][ i ].first ) ;
        ans += abs ( v[ 0 ][ i ].second - v[ 1 ][ i ].second ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}