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
#include<random>
using namespace std ;

#define MAXN 100007
#define MOD 1000000007


int n ;
pair < int , int > col[ MAXN ] ;
vector < int > v[ MAXN ] ;
vector < pair < int , int > > srt[ MAXN ] ;

int prv[ MAXN ] ;
int lvl[ MAXN ] ;
int heavy[ MAXN ] ;
int subtree[ MAXN ] ;

long long inv[ MAXN ] ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    int mx = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv[ vertex ] ) { continue ; }
        prv[ v[ vertex ][ i ] ] = vertex ;
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ; 
        dfs ( v[ vertex ][ i ] ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
        if ( mx < subtree[ v[ vertex ][ i ] ] ) {
            heavy[ vertex ] = v[ vertex ][ i ] ;
            mx = subtree[ v[ vertex ][ i ] ] ;
        }
    }
}

class hld {
public :
    int pos_in_tree[ MAXN ] ;
    int root[ MAXN ] ;
    long long tr[ 5 * MAXN ] ;
    long long lazy[ 5 * MAXN ] ;

    void push_lazy ( int where , int IL , int IR ) {
        while ( lazy[ where ] < 0 ) { lazy[ where ] += MOD ; }
        long long aux = ( 1LL * ( IR - IL + 1 ) * lazy[ where ] ) % MOD ;
        tr[ where ] = ( tr[ where ] + aux ) ;
        if ( tr[ where ] >= MOD ) { tr[ where ] -= MOD ; }
        if ( IL != IR ) {
            lazy[ 2 * where ] = ( lazy[ 2 * where ] + lazy[ where ] ) ;
            if ( lazy[ 2 * where ] >= MOD ) { lazy[ 2 * where ] -= MOD ; }
            lazy[ 2 * where + 1 ] = ( lazy[ 2 * where + 1 ] + lazy[ where ] ) ;
            if ( lazy[ 2 * where + 1 ] >= MOD ) { lazy[ 2 * where + 1 ] -= MOD ; }
        }
        lazy[ where ] = 0 ;
    }
    
    void reset ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        reset ( 2 * where , IL , mid ) ;
        reset ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , long long val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = ( lazy[ where ] + val ) ;
            if ( lazy[ where ] >= MOD ) { lazy[ where ] -= MOD ; }
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        while ( tr[ where ] >= MOD ) { tr[ where ] -= MOD ; }
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL == 1 ) { CURL = 2 ; }
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        long long ret = ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
        while ( ret >= MOD ) { ret -= MOD ; }
        return ret ;
    }
    
    void init ( ) {
        int id = 1 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( heavy[ prv[ i ] ] != i ) {
                int x = i ;
                while ( x > 0 ) {
                    pos_in_tree[ x ] = id ++ ;
                    root[ x ] = i ;
                    x = heavy[ x ] ;
                }
            }
        }
        reset ( 1 , 1 , n ) ;
    }
    void update_path ( int vertex , long long val ) {
        while ( vertex > 0 ) {
            update ( 1 , 1 , n , pos_in_tree[ root[ vertex ] ] , pos_in_tree[ vertex ] , val ) ;
            vertex = prv[ root[ vertex ] ] ;
        }
    }
    long long query_path ( int vertex ) {
        long long ret = 0 ;
        while ( vertex > 0 ) {
            ret += query ( 1 , 1 , n , pos_in_tree[ root[ vertex ] ] , pos_in_tree[ vertex ] ) ;
            vertex = prv[ root[ vertex ] ] ;
        }
        return ret ;
    }
};

hld w ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &col[ i ].first , &col[ i ].second ) ;
        srt[ col[ i ].first ].push_back ( { i , 1 } ) ;
        srt[ col[ i ].second + 1 ].push_back ( { i , -1 } ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        inv[ i ] = fastpow ( i , MOD - 2 ) ;
    }
    dfs ( 1 ) ;
    long long prod = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prod = ( prod * ( col[ i ].second - col[ i ].first + 1 ) ) % MOD ;
    }
    long long invsm = 0 ;
    long long comp1 = 0 ;
    long long comp2 = 0 ;
    long long aux_add = 0 ;
    long long ans = 0 ;
    w.init ( ) ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        int sz = srt[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int h = srt[ i ][ j ].first ;
            int len = ( col[ h ].second - col[ h ].first + 1 ) ;
            long long aux = ( lvl[ h ] * inv[ len ] ) % MOD ;
            if ( srt[ i ][ j ].second == 1 ) {
                invsm = ( invsm + inv[ len ] ) % MOD ;
                comp1 = ( comp1 + aux ) % MOD ;
                aux = ( aux * inv[ len ] ) % MOD ;
                comp2 = ( comp2 + aux ) % MOD ;

                aux = w.query_path ( h ) ;
                w.update_path ( h , ( 2 * inv[ len ] ) % MOD ) ;
                aux = ( aux * inv[ len ] ) % MOD ;
                aux_add = ( aux_add + aux ) % MOD ;
            }
            else {
                invsm = ( invsm - inv[ len ] + MOD ) % MOD ;                
                comp1 = ( comp1 - aux + MOD ) % MOD ;
                aux = ( aux * inv[ len ] ) % MOD ;
                comp2 = ( comp2 - aux + MOD ) % MOD ;

                w.update_path ( h , ( 2 *  ( MOD - inv[ len ] ) ) % MOD ) ;
                aux = w.query_path ( h ) ;
                aux = ( aux * inv[ len ] ) % MOD ;                
                aux_add = ( aux_add - aux + MOD ) % MOD ;
            }
        }
        ans = ( ans + ( comp1 * invsm ) % MOD - comp2 + MOD - aux_add + MOD ) % MOD ;
    }
    printf ( "%I64d\n" , ( ans * prod ) % MOD ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}