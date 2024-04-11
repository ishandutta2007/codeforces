#include<bits/stdc++.h>
using namespace std ;

int n ;

vector < pair < int , int > > ans ;
vector < int > v ;

void f ( int en , int coef ) {
    if ( en <= 2 ) {
        while ( en > 0 ) {
            v.push_back ( en * coef ) ;
            -- en ;
        }
        return ;
    }
    if ( ( en & ( en - 1 ) ) == 0 ) {
        v.push_back ( en * coef ) ;
        f ( en - 1 , coef ) ;
        return ;
    }
    int hh = 1 ;
    while ( 2 * hh <= en ) { hh *= 2 ; }
    for ( int i = 1 ; hh + i <= en ; ++ i ) {
        v.push_back ( coef * 2 * hh ) ;
        ans.push_back ( { coef * ( hh - i ) , coef * ( hh + i ) } ) ;
    }
    v.push_back ( coef * hh ) ;
    f ( hh - ( en - hh ) - 1 , coef ) ;
    f ( en - hh , 2 * coef ) ;
}

void input ( ) {
    cin >> n ;
    ans.clear ( ) ;
    v.clear ( ) ;
}

void solve ( ) {
    if ( n == 2 ) {
        cout << "-1\n" ;
        return ;
    }
    f ( n , 1 ) ;
    sort ( v.begin ( ) , v.end ( ) ) ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        if ( v[ i ] == v[ i + 1 ] ) {
            ans.push_back ( { v[ i ] , v[ i ] } ) ;
            v[ i ] = 0 ;
            v[ i + 1 ] *= 2 ;
            break ;
        }
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    for ( int i = 1 ; i < n - 1 ; ++ i ) {
        while ( v[ i ] < v[ n - 1 ] ) {
            ans.push_back ( { 0 , v[ i ] } ) ;
            ans.push_back ( { v[ i ] , v[ i ] } ) ;
            v[ i ] *= 2 ;
        }
    }
    ans.push_back ( { 0 , v[ n - 1 ] } ) ;
    cout << ans.size ( ) << "\n" ;
    for ( auto e : ans ) {
        cout << e.first << " " << e.second << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}