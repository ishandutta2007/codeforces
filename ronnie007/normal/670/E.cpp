#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 500007

int n , m , p ;
string a ;
string s ;

int nxt[ MAXN ] ;
int prv[ MAXN ] ;

int w[ MAXN ] ;

void input ( ) {
    cin >> n >> m >> p ;
    cin >> a ;
    cin >> s ;
}

void solve ( ) {
    stack < int > st ;
    while ( st.empty ( ) == false ) { st.pop ( ) ; }
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '(' ) { st.push ( i ) ; }
        else {
            int h = st.top ( ) ;
            st.pop ( ) ;
            w[ h + 1 ] = i + 1 ;
            w[ i + 1 ] = h + 1 ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        nxt[ i ] = i + 1 ;
        prv[ i ] = i - 1 ;
    }
    nxt[ n ] = 0 ;
    for ( i = 0 ; i < m ; i ++ ) {
        if ( s[ i ] == 'R' ) {
            if ( nxt[ p ] != 0 ) { p = nxt[ p ] ; }
        }
        else if ( s[ i ] == 'L' ) {
            if ( prv[ p ] != 0 ) { p = prv[ p ] ; }
        }
        else {
            int l , r ;
            l = p ;
            r = w[ p ] ;
            if ( r < l ) { swap ( l , r ) ; }
            nxt[ prv[ l ] ] = nxt[ r ] ;
            prv[ nxt[ r ] ] = prv[ l ] ;
            if ( nxt[ r ] != 0 ) { p = nxt[ r ] ; }
            else { p = prv[ l ] ; }
        }
    }
    int aux1 = p ;
    int aux2 = nxt[ p ] ;
    vector < int > v ;
    while ( aux1 != 0 ) {
        v.push_back ( aux1 ) ;
        aux1 = prv[ aux1 ] ;
    }
    while ( aux2 != 0 ) {
        v.push_back ( aux2 ) ;
        aux2 = nxt[ aux2 ] ;
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    int sz = v.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        cout << a[ v[ i ] - 1 ] ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}