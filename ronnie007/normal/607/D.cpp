#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007

int n , q ;
struct query {
    int type ;
    int x , y ;
};
query qlist[ MAXN ] ;

int val[ MAXN ] ;
vector < int > v[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

int act[ MAXN ] ;
int prv[ MAXN ] ;
int tp ;

class Tree {
public :
    long long coef[ 4 * MAXN ] ;
    long long tr[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        coef[ where ] = lazy[ where ] = 1 ;
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 1 ) { return ; }
        coef[ where ] = ( coef[ where ] * lazy[ where ] ) % MOD ;
        tr[ where ] = ( tr[ where ] * lazy[ where ] ) % MOD ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = ( lazy[ 2 * where ] * lazy[ where ] ) % MOD ;
            lazy[ 2 * where + 1 ] = ( lazy[ 2 * where + 1 ] * lazy[ where ] ) % MOD ;
        }
        lazy[ where ] = 1 ;
    }
    void update_range ( int where , int IL , int IR , int CURL , int CURR , long long mul ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = mul ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_range ( 2 * where , IL , mid , CURL , CURR , mul ) ;
        update_range ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , mul ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        if ( tr[ where ] >= MOD ) { tr[ where ] -= MOD ; }
    }
    void update_pos ( int where , int IL , int IR , int pos , long long val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = ( coef[ where ] * val ) % MOD ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_pos ( 2 * where , IL , mid , pos , val ) ;
        update_pos ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        if ( tr[ where ] >= MOD ) { tr[ where ] -= MOD ; }
    }
    long long obtain_coef ( int where , int IL , int IR , int pos ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL == IR ) { return coef[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            return obtain_coef ( 2 * where , IL , mid , pos ) ;
        }
        else {
            return obtain_coef ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        long long ret = query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        if ( ret >= MOD ) { ret -= MOD ; }
        return ret ;
    }
};

Tree w ;

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
    st[ vertex ] = ++ tp ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        prv[ v[ vertex ][ i ] ] = vertex ;        
        dfs ( v[ vertex ][ i ] ) ;
    }
    en[ vertex ] = tp ;
}

void input ( ) {
    scanf ( "%d%d" , &val[ 1 ] , &q ) ;
    n = 1 ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d" , &qlist[ i ].type ) ;
        if ( qlist[ i ].type == 1 ) {
            scanf ( "%d%d" , &qlist[ i ].x , &val[ ++ n ] ) ;
            qlist[ i ].y = n ;
            prv[ n ] = qlist[ i ].x ;
            v[ qlist[ i ].x ].push_back ( n ) ;
        }
        else {
            scanf ( "%d" , &qlist[ i ].x ) ;
        }
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    w.init ( 1 , 1 , n ) ;
    w.update_pos ( 1 , 1 , n , st[ 1 ] , val[ 1 ] ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        act[ i ] = 1 ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( qlist[ i ].type == 1 ) {
            int par = qlist[ i ].x ;
            int h = qlist[ i ].y ;
            long long aux = ( fastpow ( act[ par ] , MOD - 2 ) * ( act[ par ] + 1 ) ) % MOD ;
            ++ act[ par ] ;
            w.update_range ( 1 , 1 , n , st[ par ] , en[ par ] , aux ) ;
            w.update_pos ( 1 , 1 , n , st[ h ] , val[ h ] ) ;
        }
        else {
            int h = qlist[ i ].x ;
            long long ret = w.query ( 1 , 1 , n , st[ h ] , en[ h ] ) ;
            if ( h == 1 ) { printf ( "%I64d\n" , ret ) ; }
            else {
                long long aux = w.obtain_coef ( 1 , 1 , n , st[ prv[ h ] ] ) ;
                printf ( "%I64d\n" , ( ret * fastpow ( aux , MOD - 2 ) ) % MOD ) ;
            }
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