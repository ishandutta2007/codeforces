#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007

struct edge {
    int to ;
    int val , col ;
    edge ( int _to , int _val , int _col ) {
        to = _to ; val = _val ; col = _col ;
    }
};

int n ;
vector < edge > v[ MAXN ] ;
int used[ MAXN ] ;

int ans = 1 ;
int subtree[ MAXN ] ;

int fastpow ( int x , long long pw ) {
    int ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( 1LL * x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( 1LL * ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

int prod[ MAXN ] ;
int inv[ MAXN ] ;
int bal[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    subtree[ vertex ] = 1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x.to == prv || used[ x.to ] > 0 ) { continue ; }
        prod[ x.to ] = ( 1LL * prod[ vertex ] * x.val ) % MOD ;
        inv[ x.to ] = ( 1LL * inv[ vertex ] * fastpow ( x.val , MOD - 2 ) ) % MOD ;
        bal[ x.to ] = bal[ vertex ] ;
        if ( x.col == 0 ) { ++ bal[ x.to ] ; }
        else { bal[ x.to ] -= 2 ; }
        dfs ( x.to , vertex ) ;
        subtree[ vertex ] += subtree[ x.to ] ;
    }
}

int get_cen ( int vertex , int prv , int sr ) {
    for ( auto x : v[ vertex ] ) {
        if ( x.to == prv || used[ x.to ] > 0 ) { continue ; }
        if ( 2 * subtree[ x.to ] > sr ) { return get_cen ( x.to , vertex , sr ) ; }
    }
    return vertex ;
}

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int cnt[ 4 * MAXN ] ;
    void unite ( int where ) {
        tr[ where ] = ( 1LL * tr[ 2 * where ] * tr[ 2 * where + 1 ] ) % MOD ;
        cnt[ where ] = cnt[ 2 * where ] + cnt[ 2 * where + 1 ] ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 1 ; cnt[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int coef , int add ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = ( 1LL * tr[ where ] * coef ) % MOD ;
            cnt[ where ] += add ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , coef , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , coef , add ) ;
        }
        unite ( where ) ;
    }
    pair < int , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return { 1 , 0 } ; }
        if ( CURR < IL || IR < CURL ) { return { 1 , 0 } ; }
        if ( CURL <= IL && IR <= CURR ) { return { tr[ where ] , cnt[ where ] } ; }
        int mid = ( IL + IR ) / 2 ;
        pair < int , int > ret1 = query ( 2 * where , IL , mid , CURL , CURR ) ;
        pair < int , int > ret2 = query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        return { ( ( 1LL * ret1.first * ret2.first ) % MOD ) , ret1.second + ret2.second } ;
    }
};
Tree w ;

void upd ( int vertex , int prv , int coef ) {
    if ( coef > 0 ) {
        w.update ( 1 , 1 , 2 * n , bal[ vertex ] , inv[ vertex ] , 1 ) ;
    }
    else {
        w.update ( 1 , 1 , 2 * n , bal[ vertex ] , prod[ vertex ] , -1 ) ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x.to == prv || used[ x.to ] > 0 ) { continue ; }
        upd ( x.to , vertex , coef ) ;
    }
}

void query ( int vertex , int prv ) {
    pair < int , int > ret = w.query ( 1 , 1 , 2 * n , n - ( bal[ vertex ] - n ) + 1 , 2 * n ) ;
    ans = ( 1LL * ans * ret.first ) % MOD ;
    ans = ( 1LL * ans * fastpow ( inv[ vertex ] , ret.second ) ) % MOD ;
    for ( auto x : v[ vertex ] ) {
        if ( x.to == prv || used[ x.to ] > 0 ) { continue ; }
        query ( x.to , vertex ) ;
    }    
}

void decompose ( int vertex ) {
    bal[ vertex ] = n ;
    prod[ vertex ] = inv[ vertex ] = 1 ;
    dfs ( vertex , -1 ) ;
    int cen = get_cen ( vertex , -1 , subtree[ vertex ] ) ;
    used[ cen ] = 1 ;
    prod[ cen ] = inv[ cen ] = 1 ;
    bal[ cen ] = n ;
    dfs ( cen , -1 ) ;
    w.update ( 1 , 1 , 2 * n , bal[ cen ] , 1 , 1 ) ;
    for ( auto x : v[ cen ] ) {
        if ( used[ x.to ] > 0 ) { continue ; }
        query ( x.to , cen ) ;
        upd ( x.to , cen , 1 ) ;
    }
    for ( auto x : v[ cen ] ) {
        if ( used[ x.to ] > 0 ) { continue ; }
        upd ( x.to , cen , -1 ) ;
    }
    w.update ( 1 , 1 , 2 * n , bal[ cen ] , 1 , -1 ) ;
    for ( auto x : v[ cen ] ) {
        if ( used[ x.to ] > 0 ) { continue ; }
        decompose ( x.to ) ;
    }
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        int x , y , val , c ;
        scanf ( "%d%d%d%d" , &x , &y , &val , &c ) ;
        v[ x ].push_back ( edge ( y , val , c ) ) ;
        v[ y ].push_back ( edge ( x , val , c ) ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    w.init ( 1 , 1 , 2 * n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto x : v[ i ] ) {
            if ( subtree[ i ] >= subtree[ x.to ] ) {
                ans = ( 1LL * ans * fastpow ( x.val , ( ( 1LL * subtree[ x.to ] * ( n - subtree[ x.to ] ) ) ) ) ) % MOD ;
            }
        }
    }
    decompose ( 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = 0 ;
        for ( auto &x : v[ i ] ) {
            x.col ^= 1 ;
        }
    }
    decompose ( 1 ) ;
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}