#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n , MOD ;
vector < pair < int , int > > v[ MAXN ] ;
long long pw[ MAXN ] ;
long long inv[ MAXN ] ;

int subtree[ MAXN ] ;
long long path[ MAXN ] ;
int lvl[ MAXN ] ;
bool used[ MAXN ] ;
long long ans = 0 ;
map < int , int > cnt ;
int comp ;

void calc_subtrees ( int x , int prv ) {
    ++ comp ;
    int sz = v[ x ].size ( ) ;
    subtree[ x ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ x ][ i ].first ;
        int len = v[ x ][ i ].second ;
        if ( used[ to ] == true || to == prv ) { continue ; }
        lvl[ to ] = lvl[ x ] + 1 ;
        path[ to ] = ( path[ x ] + pw[ lvl[ to ] - 1 ] * len ) % MOD ;
        calc_subtrees ( to , x ) ;
        subtree[ x ] += subtree[ to ] ;
    }
}
int get_cen ( int x , int prv ) {
    int sz = v[ x ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ x ][ i ].first ;
        if ( used[ to ] == true || to == prv ) { continue ; }
        if ( subtree[ to ] > comp / 2 ) {
            return get_cen ( to , x ) ;
        }
    }
    return x ;
}

void add_ans ( int x , int prv , long long aux ) {
    int sz = v[ x ].size ( ) ;
    long long id = ( MOD - aux ) % MOD ;
    id = ( id * inv[ lvl[ x ] ] ) % MOD ;
    ans += cnt[ id ] ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ x ][ i ].first ;
        int len = v[ x ][ i ].second ;
        if ( used[ to ] == true || to == prv ) { continue ; }
        add_ans ( to , x , ( aux * 10 + len ) % MOD ) ;
    }
}

void upd_vals ( int x , int prv , int coef ) {
    int sz = v[ x ].size ( ) ;
    cnt[ path[ x ] ] += coef ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ x ][ i ].first ;
        if ( used[ to ] == true || to == prv ) { continue ; }
        upd_vals ( to , x , coef ) ;
    }
}

void decompose ( int x ) {
    path[ x ] = lvl[ x ] = comp = 0 ;
    calc_subtrees ( x , -1 ) ;
    int cen = get_cen ( x , -1 ) ;
    path[ cen ] = lvl[ cen ] = comp = 0 ;
    calc_subtrees ( cen , -1 ) ;
    int sz = v[ cen ].size ( ) ;
    ++ cnt[ 0 ] ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ cen ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        upd_vals ( to , cen , 1 ) ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ cen ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        upd_vals ( to , cen , -1 ) ;
        add_ans ( to , cen , path[ to ] ) ;
        upd_vals ( to , cen , 1 ) ;
    }
    ans = ( ans + cnt[ 0 ] - 1 ) ;
    -- cnt[ 0 ] ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ cen ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        upd_vals ( to , cen , -1 ) ;
    }
    used[ cen ] = true ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ cen ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        decompose ( to ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &MOD ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        ++ x ; ++ y ;
        v[ x ].push_back ( { y , z } ) ;
        v[ y ].push_back ( { x , z } ) ;
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 10 ) % MOD ;
    }
    long long st = MOD ;
    long long dummy = MOD ;
    for ( long long i = 2 ; i * i <= dummy ; ++ i ) {
        if ( dummy % i == 0 ) {
            st /= i ;
            st *= i - 1 ;
            while ( dummy % i == 0 ) { dummy /= i ; }
        }
    }
    if ( dummy > 1 ) {
        st /= dummy ;
        st *= dummy - 1 ;
    }
    auto fastpow = [ & ] ( long long x , long long pw ) {
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
    };
    -- st ;
    inv[ 0 ] = 1 ;
    inv[ 1 ] = fastpow ( 10 , st ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        inv[ i ] = ( inv[ i - 1 ] * inv[ 1 ] ) % MOD ;
    }
}

void solve ( ) {
    decompose ( 1 ) ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}