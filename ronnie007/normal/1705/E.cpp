#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 67 ;
const int lim = 2e5 + 22 ;

int n , q ;
int a[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] , lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        lazy[ where ] = -1 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == -1 ) { return ; }
        tr[ where ] = lazy[ where ] * ( IR - IL + 1 ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = lazy[ where ] ;
            lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = -1 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int nw ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = nw ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , nw ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , nw ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    bool present ( int where , int IL , int IR , int type ) {
        if ( type == 1 ) { return ( tr[ where ] > 0 ) ; }
        return ( tr[ where ] < ( IR - IL + 1 ) ) ;
    }
    int get_lst ( int where , int IL , int IR , int pos , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( pos < IL ) { return -1 ; }
        if ( present ( where , IL , IR , val ) == false ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_lst ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        if ( ret != -1 ) { return ret ; }
        return get_lst ( 2 * where , IL , mid , pos , val ) ;
    }
    int get_fst ( int where , int IL , int IR , int pos , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos ) { return lim + 1 ; }
        if ( present ( where , IL , IR , val ) == false ) { return lim + 1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_fst ( 2 * where , IL , mid , pos , val ) ;
        if ( ret != lim + 1 ) { return ret ; }
        return get_fst ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
    }
};
Tree w ;

void add ( int x ) {
    if ( w.get_fst ( 1 , 1 , lim , x , 1 ) == x ) {
        int en = w.get_fst ( 1 , 1 , lim , x , 0 ) ;
        w.update ( 1 , 1 , lim , x , en - 1 , 0 ) ;
        w.update ( 1 , 1 , lim , en , en , 1 ) ;
    }
    else {
        w.update ( 1 , 1 , lim , x , x , 1 ) ;
    }
}
void sub ( int x ) {
    if ( w.get_fst ( 1 , 1 , lim , x , 0 ) == x ) {
        int en = w.get_fst ( 1 , 1 , lim , x , 1 ) ;
        w.update ( 1 , 1 , lim , x , en - 1 , 1 ) ;
        w.update ( 1 , 1 , lim , en , en , 0 ) ;
    }
    else {
        w.update ( 1 , 1 , lim , x , x , 0 ) ;
    }
}

void solve ( ) {
    cin >> n >> q ;
    w.init ( 1 , 1 , lim ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        add ( a[ i ] ) ;
    }
    while ( q -- ) {
        int pos , x ;
        cin >> pos >> x ;
        sub ( a[ pos ] ) ;
        a[ pos ] = x ;
        add ( x ) ;
        cout << w.get_lst ( 1 , 1 , lim , lim , 1 ) << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}