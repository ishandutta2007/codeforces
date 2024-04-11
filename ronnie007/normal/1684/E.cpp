#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1e5 + 7 ;

int n , k ;
int a[ MAXN ] ;
map < int , int > cnt ;

class Tree {
public :
    ll tr[ 4 * MAXN ] ;
    int hh[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = hh[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int coef ) {
        if ( IL == IR ) {
            tr[ where ] += pos * coef ;
            hh[ where ] += coef ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { update ( 2 * where , IL , mid , pos , coef ) ; }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos , coef ) ; }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        hh[ where ] = hh[ 2 * where ] + hh[ 2 * where + 1 ] ;
    }
    pair < int , int > query ( int where , int IL , int IR , int lft ) {
        if ( tr[ where ] <= lft ) { return { lft - tr[ where ] , hh[ where ] } ; }
        if ( IL == IR ) {
            int ret = lft / IL ;
            return { 0 , ret } ;
        }
        int mid = ( IL + IR ) / 2 ;
        pair < int , int > aux1 = query ( 2 * where , IL , mid , lft ) ;
        pair < int , int > aux2 = query ( 2 * where + 1 , mid + 1 , IR , aux1.first ) ;
        return { aux2.first , aux1.second + aux2.second } ;
    }
};
Tree w ;

void solve ( ) {
    cin >> n >> k ;
    cnt.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( auto p : cnt ) {
        w.update ( 1 , 1 , n , p.second , 1 ) ;
    }
    int ans = MAXN ;
    int tot = cnt.size ( ) ;
    int gaps = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        if ( gaps > k ) { break ; }
        pair < int , int > aux = w.query ( 1 , 1 , n , k ) ;
        ans = min ( ans , tot - aux.second ) ;
        if ( cnt[ i ] > 0 ) {
            -- tot ;
            w.update ( 1 , 1 , n , cnt[ i ] , -1 ) ;
        }
        else { ++ gaps ; }
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