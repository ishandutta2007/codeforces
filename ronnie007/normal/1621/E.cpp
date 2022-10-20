#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007

int n , m ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

struct node {
    int sm , mn ;
    node ( ) { sm = mn = 0 ; }
};

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void unite ( int where ) {
        tr[ where ].sm = tr[ 2 * where ].sm + tr[ 2 * where + 1 ].sm ;
        tr[ where ].mn = min ( tr[ 2 * where ].mn , tr[ 2 * where ].sm + tr[ 2 * where + 1 ].mn ) ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ].sm = tr[ where ].mn = 0 ;
        if ( IL == IR ) {
            tr[ where ].sm = 1 ;
            tr[ where ].mn = 0 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].sm += val ;
            tr[ where ].mn = min ( tr[ where ].sm , 0 ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        unite ( where ) ;
    }
    bool query ( ) { return ( tr[ 1 ].mn == 0 ) ; }
};
Tree w ;

int get_pos ( long long sm , long long coef ) {
    int l , r , mid ;
    l = 1 , r = n ;
    if ( coef * a[ 1 ] < sm ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( coef * a[ mid ] >= sm ) { l = mid ; }
        else { r = mid ; }
    }
    while ( coef * a[ r ] < sm ) { -- r ; }
    return r ;
}

int fst[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 , sz ; i <= m ; ++ i ) {
        cin >> sz ;
        v[ i ].resize ( sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            cin >> v[ i ][ j ] ;
        }
    }
    sort ( a + 1 , a + n + 1 , greater < int > ( ) ) ;
    if ( n > m ) { n = m ; }
}

void solve ( ) {
    int cnt = 0 ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long sm = 0 ;
        for ( auto x : v[ i ] ) {
            sm += x ;
        }
        fst[ i ] = get_pos ( sm , v[ i ].size ( ) ) ;
        if ( fst[ i ] == 0 ) { ++ cnt ; }
        else {
            w.update ( 1 , 1 , n , fst[ i ] , -1 ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fst[ i ] == 0 ) { -- cnt ; }
        else {
            w.update ( 1 , 1 , n , fst[ i ] , 1 ) ;
        }

        
        long long sm = 0 , sz = v[ i ].size ( ) ;
        for ( auto x : v[ i ] ) {
            sm += x ;
        }
        for ( auto x : v[ i ] ) {
            int wh = get_pos ( sm - x , sz - 1 ) ;
            if ( wh == 0 ) { cout << "0" ; }
            else {
                if ( cnt > 0 || w.query ( ) == false ) { cout << "0" ; }
                else {
                    w.update ( 1 , 1 , n , wh , -1 ) ;
                    if ( w.query ( ) == false ) { cout << "0" ; }
                    else { cout << "1" ; }
                    w.update ( 1 , 1 , n , wh , 1 ) ;
                }
            }
        }
        if ( fst[ i ] == 0 ) { ++ cnt ; }
        else {
            w.update ( 1 , 1 , n , fst[ i ] , -1 ) ;
        }
    }
    cout << "\n" ;
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