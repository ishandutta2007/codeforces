#include<bits/stdc++.h>
using namespace std ;

#define MAXN 11
#define digs 53

int n ;
string a[ MAXN ] ;

int conv ( char c ) {
    if ( 'a' <= c && c <= 'z' ) { return ( c - 'a' ) ; }
    return ( c - 'A' ) + 26 ;
}
int tp[ digs ] ;
int wh[ digs ][ MAXN ][ 2 ] ;

int dp[ digs ][ ( 1 << MAXN ) ] ;
pair < int , int > nxt[ digs ][ ( 1 << MAXN ) ] ;
bool vis[ digs ][ ( 1 << MAXN ) ] ;


void f ( int lst , int mask ) {
    dp[ lst ][ mask ] = 0 ;
    vis[ lst ][ mask ] = true ;
    for ( int i = 0 ; i < digs - 1 ; ++ i ) {
        int nxt_mask = 0 ;
        bool fl = false ;
        for ( int j = 0 ; j < n ; ++ j ) {
            int bit = ( ( mask & ( 1 << j ) ) > 0 ) ;
            if ( wh[ lst ][ j ][ bit ] < wh[ i ][ j ][ 0 ] ) { continue ; }
            if ( wh[ lst ][ j ][ bit ] < wh[ i ][ j ][ 1 ] ) {
                nxt_mask += ( 1 << j ) ;
                continue ;
            }
            fl = true ;
            break ;
        }
        if ( fl == true ) { continue ; }
        if ( vis[ i ][ nxt_mask ] == false ) {
            f ( i , nxt_mask ) ;
        }
        if ( dp[ lst ][ mask ] < 1 + dp[ i ][ nxt_mask ] ) {
            dp[ lst ][ mask ] = 1 + dp[ i ][ nxt_mask ] ;
            nxt[ lst ][ mask ] = { i , nxt_mask } ;
        }
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < digs ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            wh[ i ][ j ][ 0 ] = wh[ i ][ j ][ 1 ] = -1 ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < digs ; ++ j ) {
            tp[ j ] = 0 ;
        }
        int sz = a[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            wh[ conv ( a[ i ][ j ] ) ][ i ][ tp[ conv ( a[ i ][ j ] ) ] ++ ] = j ;
        }
    }
    for ( int i = 0 ; i < digs ; ++ i ) {
        for ( int j = 0 ; j < ( 1 << n ) ; ++ j ) {
            vis[ i ][ j ] = false ;
            nxt[ i ][ j ] = { -1 , -1 } ;
        }
    }
    f ( digs - 1 , 0 ) ;
    cout << dp[ digs - 1 ][ 0 ] << "\n" ;
    int lst_dig = digs - 1 , lst_mask = 0 ;
    string ans = "" ;
    while ( lst_dig != -1 ) {
        if ( lst_dig != digs - 1 ) {
            if ( lst_dig < 26 ) { ans += char ( 'a' + lst_dig ) ; }
            else { ans += char ( 'A' + ( lst_dig - 26 ) ) ; }
        }
        auto hh = nxt[ lst_dig ][ lst_mask ] ;
        lst_dig = hh.first , lst_mask = hh.second ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}