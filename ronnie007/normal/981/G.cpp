#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

int n , q ;

set < pair < int , int > > s[ MAXN ] ;

class Tree {
public :
    long long coef_lazy[ 5 * MAXN ] ;
    long long add_lazy[ 5 * MAXN ] ;
    long long tr[ 5 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] = ( tr[ where ] * coef_lazy[ where ] + add_lazy[ where ] * ( IR - IL + 1 ) ) % MOD ;
        if ( IL != IR ) {
            add_lazy[ 2 * where ] = ( add_lazy[ 2 * where ] * coef_lazy[ where ] + add_lazy[ where ] ) % MOD ;
            coef_lazy[ 2 * where ] = ( coef_lazy[ 2 * where ] * coef_lazy[ where ] ) % MOD ;

            add_lazy[ 2 * where + 1 ] = ( add_lazy[ 2 * where + 1 ] * coef_lazy[ where ] + add_lazy[ where ] ) % MOD ;
            coef_lazy[ 2 * where + 1 ] = ( coef_lazy[ 2 * where + 1 ] * coef_lazy[ where ] ) % MOD ;
        }
        add_lazy[ where ] = 0 ;
        coef_lazy[ where ] = 1 ;
    }
    void init ( int where , int IL , int IR ) {
        add_lazy[ where ] = tr[ where ] = 0 ;
        coef_lazy[ where ] = 1 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , long long coef_val , long long add_val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            coef_lazy[ where ] = ( coef_lazy[ where ] * coef_val ) % MOD ;
            add_lazy[ where ] = ( add_lazy[ where ] + add_val ) % MOD ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , coef_val , add_val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , coef_val , add_val ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) % MOD ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) % MOD ) ;
    }
};
Tree w ;

void f ( int l , int r , int x ) {
    if ( s[ x ].empty ( ) == true ) {
        s[ x ].insert ( { l , r } ) ;
        w.update ( 1 , 1 , n , l , r , 1 , 1 ) ;
        return ;
    }
    set < pair < int , int > > :: iterator it ;
    it = s[ x ].upper_bound ( { r , MAXN } ) ;
    if ( it != s[ x ].begin ( ) ) {
        -- it ;
        if ( it->second >= r ) {
            pair < int , int > rem ;
            rem = { it->first , it->second } ;
            s[ x ].erase ( it ) ;
            if ( rem.second > r ) {
                s[ x ].insert ( { r + 1 , rem.second } ) ;
            }
            s[ x ].insert ( { rem.first , r } ) ;
        }
    }
    it = s[ x ].lower_bound ( { l , 0 } ) ;
    if ( it != s[ x ].begin ( ) ) {
        -- it ;
        if ( it->second >= l ) {
            pair < int , int > rem ;
            rem = { it->first , it->second } ;
            s[ x ].erase ( it ) ;
            s[ x ].insert ( { l , rem.second } ) ;
            s[ x ].insert ( { rem.first , l - 1 } ) ;
            it = s[ x ].find ( { rem.first , l - 1 } ) ;
        }
        ++ it ;
    }
    int lst = l ;
    while ( 1 ) {
        if ( it == s[ x ].end ( ) || it->first > r ) {
            s[ x ].insert ( { l , r } ) ;
            w.update ( 1 , 1 , n , lst , r , 1 , 1 ) ;
            return ;
        }
        else {
            w.update ( 1 , 1 , n , lst , it->first - 1 , 1 , 1 ) ;
            w.update ( 1 , 1 , n , it->first , it->second , 2 , 0 ) ;
            lst = it->second + 1 ;
            it = s[ x ].erase ( it ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    while ( q -- ) {
        int type ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            int l , r , x ;
            scanf ( "%d%d%d" , &l , &r , &x ) ;
            f ( l , r , x ) ;
        }
        else {
            int l , r ;
            scanf ( "%d%d" , &l , &r ) ;
            printf ( "%I64d\n" , w.query ( 1 , 1 , n , l , r ) ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}