#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;

int n , d ;
int a[ MAXN ] ;
bool act[ MAXN ] ;

ll sum_up_to ( ll x ) {
    return x * ( x + 1 ) / 2 ;
}

class Tree {
public :
    ll cnt[ 4 * MAXN ] ;
    ll sm[ 4 * MAXN ] ;
    ll tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        cnt[ where ] = sm[ where ] = tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        int hh = lazy[ where ] ;
        if ( lazy[ where ] > 0 ) {
            ll coef = 2 * sum_up_to ( lazy[ where ] - 1 ) * cnt[ where ] ;
            tr[ where ] += coef ;
            tr[ where ] += 2 * lazy[ where ] * sm[ where ] ;
            sm[ where ] += lazy[ where ] * cnt[ where ] ;
            lazy[ where ] = 0 ;
        }
        else {
            lazy[ where ] *= -1 ;
            tr[ where ] += 2 * lazy[ where ] * cnt[ where ] ;
            
            ll coef = 2 * sum_up_to ( lazy[ where ] - 1 ) * cnt[ where ] ;
            tr[ where ] += coef ;
            tr[ where ] -= 2 * lazy[ where ] * sm[ where ] ;
            sm[ where ] -= lazy[ where ] * cnt[ where ] ;
            lazy[ where ] = 0 ;
        }
        if ( IL != IR ) {
            lazy[ 2 * where ] += hh ;
            lazy[ 2 * where + 1 ] += hh ;
        }
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , bool fl ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) { 
            if ( fl == true ) { ++ lazy[ where ] ; }
            else { -- lazy[ where ] ; }
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , fl ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , fl ) ;
        cnt[ where ] = cnt[ 2 * where ] + cnt[ 2 * where + 1 ] ;
        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    void set_pos ( int where , int IL , int IR , int pos , ll nw_sm , ll nw_cnt ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = nw_sm * ( nw_sm - 1 ) ;
            sm[ where ] = nw_sm ;
            cnt[ where ] = nw_cnt ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        set_pos ( 2 * where , IL , mid , pos , nw_sm , nw_cnt ) ;
        set_pos ( 2 * where + 1 , mid + 1 , IR , pos , nw_sm , nw_cnt ) ;
        cnt[ where ] = cnt[ 2 * where ] + cnt[ 2 * where + 1 ] ;
        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;        
    }
    int get_cnt ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return cnt[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return get_cnt ( 2 * where , IL , mid , CURL , CURR ) + get_cnt ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

void solve ( ) {
    cin >> n >> d ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    w.init ( 1 , 1 , MAXN ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int st = a[ i ] - d ;
        if ( st < 1 ) { st = 1 ; }
        if ( act[ a[ i ] ] == false ) {
            w.update ( 1 , 1 , MAXN , st , a[ i ] - 1 , true ) ;
            int en = a[ i ] + d ;
            if ( en > MAXN ) { en = MAXN ; }
            ll hh = w.get_cnt ( 1 , 1 , MAXN , a[ i ] + 1 , en ) ;
            w.set_pos ( 1 , 1 , MAXN , a[ i ] , hh , 1 ) ;
            act[ a[ i ] ] = true ;
        }
        else {
            w.update ( 1 , 1 , MAXN , st , a[ i ] - 1 , false ) ;
            w.set_pos ( 1 , 1 , MAXN , a[ i ] , 0 , 0 ) ;
            act[ a[ i ] ] = false ;
        }
        cout << w.tr[ 1 ] / 2 << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}