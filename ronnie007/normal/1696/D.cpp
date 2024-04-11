#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 3e5 + 7 ;

int n ;
int a[ MAXN ] ;
int ans = 0 ;

pair < int , int > unite ( pair < int , int > p1 , pair < int , int > p2 ) {
    pair < int , int > ret ;
    if ( a[ p1.first ] < a[ p2.first ] ) { ret.first = p1.first ; }
    else { ret.first = p2.first ; } 

    if ( a[ p1.second ] > a[ p2.second ] ) { ret.second = p1.second ; }
    else { ret.second = p2.second ; }
    
    return ret ;
}

class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = { IL , IL } ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    pair < int , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return { 0 , n + 1 } ; }
        if ( IR < CURL || CURR < IL ) { return { 0 , n + 1 } ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void decomp ( int l , int r ) {
    pair < int , int > ret = w.query ( 1 , 1 , n , l , r ) ;
    if ( ret.first == l && ret.second == r ) { ++ ans ; return ; }
    if ( ret.first == r && ret.second == l ) { ++ ans ; return ; }
    if ( ret.first != l && ret.first != r ) {
        decomp ( l , ret.first ) ;
        decomp ( ret.first , r ) ;
    }
    else {
        decomp ( l , ret.second ) ;
        decomp ( ret.second , r ) ;
    }
}

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    if ( n == 1 ) {
        cout << "0\n" ;
        return ;
    }
    a[ 0 ] = MAXN , a[ n + 1 ] = 0 ; 
    w.init ( 1 , 1 , n ) ;
    ans = 0 ;
    decomp ( 1 , n ) ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}