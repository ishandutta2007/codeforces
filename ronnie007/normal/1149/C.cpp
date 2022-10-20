#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
int n , q ;
string a ;

int coef[ 3 ] = { 1 , -2 , 1 } ;
int prec[ 3 ][ 3 ] ;

struct node {
    int tot ;
    int f[ 3 ][ 3 ] ;
    node ( ) {
        for ( int i = 0 ; i < 3 ; ++ i ) {
            for ( int j = 0 ; j < 3 ; ++ j ) {
                f[ i ][ j ] = 0 ;
            }
        }
    }
    node ( int val ) {
        tot = val ;
        for ( int i = 0 ; i < 3 ; ++ i ) {
            for ( int j = 0 ; j < 3 ; ++ j ) {
                f[ i ][ j ] = 0 ;
            }
            for ( int j = i ; j < 3 ; ++ j ) {
                f[ i ][ j ] = val * prec[ i ][ j ] ;
            }
        }
    }
};

node merge ( node p1 , node p2 ) {
    node ret ;
    ret.tot = p1.tot + p2.tot ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = 0 ; j < 3 ; ++ j ) {
            ret.f[ i ][ j ] = p1.f[ i ][ j ] ;
        }
    }
    for ( int l = 0 ; l < 3 ; ++ l ) {
        for ( int r = l ; r < 3 ; ++ r ) {
            for ( int mid = l - 1 ; mid <= r ; ++ mid ) {
                int cand = 0 ;
                if ( l <= mid ) { cand += p1.f[ l ][ mid ] ; }
                if ( mid < r ) { cand += prec[ mid + 1 ][ r ] * p1.tot + p2.f[ mid + 1 ][ r ] ; }
                ret.f[ l ][ r ] = max ( ret.f[ l ][ r ] , cand ) ;
            }
        }
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            if ( a[ IL - 1 ] == '(' ) {
                tr[ where ] = node ( 1 ) ;
            }
            else {
                tr[ where ] = node ( -1 ) ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            if ( a[ IL - 1 ] == '(' ) {
                tr[ where ] = node ( 1 ) ;
            }
            else {
                tr[ where ] = node ( -1 ) ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { update ( 2 * where , IL , mid , pos ) ; }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( ) {
        return tr[ 1 ].f[ 0 ][ 2 ] ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        int aux = 0 ;
        for ( int j = i ; j < 3 ; ++ j ) {
            aux += coef[ j ] ;
            prec[ i ][ j ] = aux ;
        }
    }
    int len = 2 * ( n - 1 ) ;
    w.init ( 1 , 1 , len ) ;
    cout << w.query ( ) << "\n" ;
    while ( q -- ) {
        int x , y ;
        cin >> x >> y ;
        swap ( a[ x - 1 ] , a[ y - 1 ] ) ;
        w.update ( 1 , 1 , len , x ) ;
        w.update ( 1 , 1 , len , y ) ;
        cout << w.query ( ) << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}