#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MXVAL 62

int n , q ;
string a ;

set < int > s[ MXVAL ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = ( IR - IL + 1 ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        -- tr[ where ] ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
    }
    int getl ( int where , int IL , int IR , int lft ) {
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where ] >= lft ) { return getl ( 2 * where , IL , mid , lft ) ; }
        return getl ( 2 * where + 1 , mid + 1 , IR , lft - tr[ 2 * where ] ) ;
    }
    void output ( int where , int IL , int IR ) {
        if ( tr[ where ] == 0 ) { return ; }
        if ( IL == IR ) {
            cout << a[ IL - 1 ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        output ( 2 * where , IL , mid ) ;
        output ( 2 * where + 1 , mid + 1 , IR ) ;
    }
};
Tree w ;

int f ( char c ) {
    if ( c >= 'a' && c <= 'z' ) {
        return ( c - 'a' ) ;
    }
    if ( c >= 'A' && c <= 'Z' ) {
        return 26 + ( c - 'A' ) ;
    }
    return 52 + ( c - '0' ) ;
}

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        s[ f ( a[ i ] ) ].insert ( i + 1 ) ;
    }

}

void solve ( ) {
    int l , r ;
    char c ;
    while ( q -- ) {
        cin >> l >> r >> c ;
        l = w.getl ( 1 , 1 , n , l ) ;
        r = w.getl ( 1 , 1 , n , r ) ;
        int id = f ( c ) ;
        set < int > :: iterator it = s[ id ].lower_bound ( l ) ;
        while ( it != s[ id ].end ( ) ) {
            if ( (*it) > r ) { break ; }
            w.update ( 1 , 1 , n , (*it) ) ;
            it = s[ id ].erase ( it ) ;
        }
    }
    w.output ( 1 , 1 , n ) ;
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}