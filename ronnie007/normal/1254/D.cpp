#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 150007
#define MOD 998244353

int n , q ;
vector < int > v[ MAXN ] ;
int subtree[ MAXN ] ;
int heavy[ MAXN ] ;
int lst[ MAXN ] ;

int root[ MAXN ] ;
int tpsz ;
int ord[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

long long add[ MAXN ] ;



void dfs ( int vertex , int prv ) {
    ord[ ++ tpsz ] = vertex ;
    st[ vertex ] = tpsz ;


    subtree[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lst[ v[ vertex ][ i ] ] = vertex ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
        if ( subtree[ v[ vertex ][ i ] ] > subtree[ heavy[ vertex ] ] ) {
            heavy[ vertex ] = v[ vertex ][ i ] ;
        }
    }

    en[ vertex ] = tpsz ;
}

long long fastpow ( long long x , long long st ) {
    long long ret = 1 ;
    while ( st > 0 ) {
        if ( ( st & 1 ) != 0 ) {
            ret = ( ret * x ) % MOD ;
            -- st ;
        }
        else {
            x = ( x * x ) % MOD ;
            st >>= 1 ;
        }
    }
    return ret ;
}

class Tree {
    public :
    long long tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , long long val ) {
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ] += val ;
            if ( tr[ where ] >= MOD ) { tr[ where ] -= MOD ; }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    }
    long long query ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return 0 ; }
        if ( IL == IR ) { return tr[ where ] ; }
        long long ret = tr[ where ] ;
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { ret += query ( 2 * where , IL , mid , pos ) ; }
        else { ret += query ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
        return ret ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) , v[ y ].push_back ( x ) ;
    }
}



void solve ( ) {
    dfs ( 1 , 0 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( heavy[ lst[ i ] ] != i ) {
            int x = i ;
            while ( x > 0 ) {
                root[ x ] = i ;
                x = heavy[ x ] ;
            }
        }
    }
    long long coef = fastpow ( n , MOD - 2 ) ;
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int type , x , y ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d" , &x , &y ) ;
            add[ x ] += y ;
            if ( add[ x ] >= MOD ) { add[ x ] -= MOD ; }
            long long aux = ( 1LL * subtree[ x ] * y ) % MOD ;
            w.update ( 1 , 1 , n , 1 , st[ x ] - 1 , aux ) ;
            w.update ( 1 , 1 , n , en[ x ] + 1 , n , aux ) ;
            if ( heavy[ x ] > 0 ) {
                aux = ( 1LL * ( n - subtree[ heavy[ x ] ] ) * y ) % MOD ;
                w.update ( 1 , 1 , n , st[ heavy[ x ] ] , en[ heavy[ x ] ] , aux ) ;
            }
        }
        else {
            scanf ( "%d" , &x ) ;
            long long ans = 1LL * n * add[ x ] + w.query ( 1 , 1 , n , st[ x ] ) ;
            ans %= MOD ;
            while ( x > 0 ) {
                x = root[ x ] ;
                ans += ( 1LL * add[ lst[ x ] ] * ( n - subtree[ x ] ) ) % MOD ;
                if ( ans >= MOD ) { ans -= MOD ; }
                x = lst[ x ] ;
            }
            printf ( "%I64d\n" , ( ans * coef ) % MOD ) ;
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