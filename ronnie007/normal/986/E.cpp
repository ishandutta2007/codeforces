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

#define MAXN 100007
#define LOG 18
#define MAXVAL 10000007
#define MOD 1000000007

int n ;
int q ;
vector < int > v[ MAXN ] ;
long long ans[ MAXN ] ;

int LCA[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;
int a[ MAXN ] ;
int vec_sz[ MAXVAL ] ;

struct query {
    int x , y , z ;
    int lca_val ;
};
query p[ MAXN ] ;

bool pr[ MAXN ] ;
vector < pair < int , int > > srt[ MAXVAL ] ;

void init ( ) {
    for ( int i = 2 ; i <= 3400 ; ++ i ) {
        if ( pr[ i ] == true ) { continue ; }
        for ( int j = 2 * i ; j <= n ; j += i ) {
            pr[ j ] = false ;
        }
        for ( int j = 1 ; j <= n ; ++ j ) {
            int cnt = 0 ;
            while ( ( a[ j ] % i ) == 0 ) {
                ++ cnt ;
                a[ j ] /= i ;
            }
            if ( cnt > 0 ) {
                srt[ i ].push_back ( { cnt , j } ) ;
            }
        }
        for ( int j = 1 ; j <= q ; ++ j ) {
            int cnt = 0 ;
            while ( ( p[ j ].z % i ) == 0 ) {
                ++ cnt ;
                p[ j ].z /= i ;
            }
            if ( cnt > 0 ) {
                srt[ i ].push_back ( { cnt , n + j } ) ;
            }
        }
        vec_sz[ i ] = srt[ i ].size ( ) ;
        sort ( srt[ i ].begin ( ) , srt[ i ].end ( ) ) ;
    }
    for ( int j = 1 ; j <= n ; ++ j ) {
        if ( a[ j ] > 1 ) {
            srt[ a[ j ] ].push_back ( { 1 , j } ) ;
            ++ vec_sz[ a[ j ] ] ;
        }
    }
    for ( int j = 1 ; j <= q ; ++ j ) {
        if ( p[ j ].z > 1 ) {
            srt[ p[ j ].z ].push_back ( { 1 , n + j } ) ;
            ++ vec_sz[ p[ j ].z ] ;
        }
    }
}
int time_var ;
void dfs ( int vertex , int prv ) {
    st[ vertex ] = ++ time_var ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    en[ vertex ] = time_var ;
}
int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if (  lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ;
}

class Tree {
public :
    int tr[ 5 * MAXN ] ;
    int cnt[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ] = ( tr[ where ] + val ) ;
            while ( tr[ where ] >= MOD ) { tr[ where ] -= MOD ; }
            while ( tr[ where ] < 0 ) { tr[ where ] += MOD ; }
            if ( val > 0 ) { ++ cnt[ where ] ; }
            else { -- cnt[ where ] ; }
                
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( CURL <= mid ) {
            update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        }
        if ( mid + 1 <= CURR ) {
            update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        }
    }
    int query ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return 0 ; }
        if ( IL == IR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = 0 ;
        if ( pos <= mid ) {
            ret = query ( 2 * where , IL , mid , pos ) ;
        }
        else {
            ret = query ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        ret += tr[ where ] ;
        while ( ret >= MOD ) { ret -= MOD ; }
        return ret ;
    }
    int get_cnt ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return 0 ; }
        if ( IL == IR ) { return cnt[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = 0 ;
        if ( pos <= mid ) {
            ret = get_cnt ( 2 * where , IL , mid , pos ) ;
        }
        else {
            ret = get_cnt ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        ret += cnt[ where ] ;
        return ret ;
    }
};
Tree w ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw & 1 ) == 0 ) {
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

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d%d%d" , &p[ i ].x , &p[ i ].y , &p[ i ].z ) ;
    }
}

void solve ( ) {
    init ( ) ;
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        ans[ i ] = 1 ;
        p[ i ].lca_val = get_LCA ( p[ i ].x , p[ i ].y ) ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 2 ; i < MAXVAL ; ++ i ) {
        if ( vec_sz[ i ] == 0 ) { continue ; }
        int sz = vec_sz[ i ] ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int ver = srt[ i ][ j ].second ;
            if ( ver <= n ) {
                int add = srt[ i ][ j ].first ;
                w.update ( 1 , 1 , n , st[ ver ] , en[ ver ] , add ) ;
            }
            else {
                ver -= n ; 
                long long ret1 = w.query ( 1 , 1 , n , st[ p[ ver ].x ] ) ;
                long long ret2 = w.query ( 1 , 1 , n , st[ p[ ver ].y ] ) ;
                long long ret3 = w.query ( 1 , 1 , n , st[ p[ ver ].lca_val ] ) ;
                long long ret4 = w.query ( 1 , 1 , n , st[ LCA[ p[ ver ].lca_val ][ 0 ] ] ) ;
                ret1 = ( ret1 + ret2 - ret3 - ret4 + MOD + MOD ) % MOD ;
                long long aux = fastpow ( i , ret1 ) ;
                ans[ ver ] = ( ans[ ver ] * aux ) % MOD ;
            }
        }
        for ( int j = 0 ; j < sz ; ++ j ) {
            int ver = srt[ i ][ j ].second ;
            if ( ver <= n ) {
                int add = srt[ i ][ j ].first ;                
                w.update ( 1 , 1 , n , st[ ver ] , en[ ver ] , -add ) ;
            }
            else {
                ver -= n ; 
                long long ret1 = w.get_cnt ( 1 , 1 , n , st[ p[ ver ].x ] ) ;
                long long ret2 = w.get_cnt ( 1 , 1 , n , st[ p[ ver ].y ] ) ;
                long long ret3 = w.get_cnt ( 1 , 1 , n , st[ p[ ver ].lca_val ] ) ;
                long long ret4 = w.get_cnt ( 1 , 1 , n , st[ LCA[ p[ ver ].lca_val ][ 0 ] ] ) ;
                ret1 = ( ret1 + ret2 - ret3 - ret4 + MOD + MOD ) % MOD ;
                ret1 = ( ret1 * srt[ i ][ j ].first ) % MOD ;
                long long aux = fastpow ( i , ret1 ) ;
                ans[ ver ] = ( ans[ ver ] * aux ) % MOD ;
            }            
        }        
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%I64d\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}