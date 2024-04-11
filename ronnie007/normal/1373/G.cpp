#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 4e5 + 7 ;

set < pair < int , int > > s ;
map < int , int > hh ;

class Tree {
public :
    int tr[ 4 * MAXN ] , lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = IL - 1 ; 
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = tr[ 2 * where + 1 ] ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int hh ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += hh ;
            push_lazy ( where , IL , IR ) ;
            return ; 
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , hh ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , hh ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void solve ( ) {
    int n , k , q ;
    cin >> n >> k >> q ;
    w.init ( 1 , 1 , 2 * n ) ;
    while ( q -- ) {
        int x , y ; cin >> x >> y ;
        int pos = y + abs ( x - k ) ;
        if ( s.find ( { x , y } ) == s.end ( ) ) {
            ++ hh[ pos ] ;
            w.update ( 1 , 1 , 2 * n , 1 , pos , 1 ) ;
            s.insert ( { x , y } ) ;
        }
        else {
            if ( hh[ pos ] > 1 ) { -- hh[ pos ] ; }
            else { hh.erase ( pos ) ; }
            w.update ( 1 , 1 , 2 * n , 1 , pos , -1 ) ;
            s.erase ( { x , y } ) ;
        }
        if ( hh.empty ( ) == false ) {
            cout << max ( w.query ( 1 , 1 , 2 * n , 1 , (*hh.rbegin ( )).first ) - n , 0 ) << "\n" ;
        }
        else { cout << "0\n" ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}