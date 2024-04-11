#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
string st , en ;
pair < int , int > a[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void unite ( int where ) {
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == -1 ) { return ; }
        tr[ where ] = ( IR - IL + 1 ) * lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = lazy[ where ] ;
            lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = -1 ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = -1 ;
        if ( IL == IR ) {
            tr[ where ] = ( en[ IL - 1 ] - '0' ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    cin >> n >> q ;
    cin >> st >> en ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    for ( int i = q ; i >= 1 ; -- i ) {
        int cnt = w.query ( 1 , 1 , n , a[ i ].first , a[ i ].second ) ;
        int len = a[ i ].second - a[ i ].first + 1 ;
        if ( 2 * cnt == len ) {
            cout << "NO\n" ;
            return ;
        }
        if ( 2 * cnt < len ) {
            w.update ( 1 , 1 , n , a[ i ].first , a[ i ].second , 0 ) ;
        }
        else {
            w.update ( 1 , 1 , n , a[ i ].first , a[ i ].second , 1 ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int ch = w.query ( 1 , 1 , n , i , i ) ;
        if ( ( st[ i - 1 ] - '0' ) != ch ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}