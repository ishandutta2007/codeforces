#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

long long inf = 1e15 ;

int n ;
int h[ MAXN ] ;
int a[ MAXN ] ;

long long dp[ MAXN ] ;
long long hval[ MAXN ] ;

multiset < long long > cand ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = -inf ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , long long nw ) {
        if ( IL == IR ) {
            tr[ where ] = nw ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nw ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        }
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return -inf ; }
        if ( IR < CURL || CURR < IL ) { return -inf ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> h[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    h[ 0 ] = -1 ;
    dp[ 0 ] = 0 ;
    w.init ( 1 , 1 , n ) ;
    w.update ( 1 , 1 , n , 1 , 0 ) ;
    stack < int > s ;
    s.push ( 0 ) ;
    hval[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( h[ s.top ( ) ] > h[ i ] ) {
            auto it = cand.find ( hval[ s.top ( ) ] ) ;
            cand.erase ( it ) ;
            s.pop ( ) ;
        }
        hval[ i ] = w.query ( 1 , 1 , n , s.top ( ) + 1 , i ) + a[ i ] ;
        s.push ( i ) ;
        cand.insert ( hval[ i ] ) ;
        dp[ i ] = *(cand.rbegin ( )) ;
        if ( i < n ) {
            w.update ( 1 , 1 , n , i + 1 , dp[ i ] ) ;
        }
    }
    cout << dp[ n ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}