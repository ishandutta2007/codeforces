#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007
long long inf = ( 1LL << 50 ) ;

int n , m ;
int a[ MAXN ] ;

pair < int , int > b[ MAXN ] ;
int lst[ MAXN ] ;
int nxt[ MAXN ] ;

vector < int > v[ MAXN ] ;


int getl ( int sr ) {
    int l , r , mid ;
    l = 1 , r = n ;
    if ( sr <= a[ l ] ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ] >= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( a[ r ] >= sr ) { -- r ; }
    return r ;
}

vector < pair < int , int > > act ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    auto cmp = [ & ] ( pair < int , int > p1 , pair < int , int > p2 ) {
        if ( p1.first != p2.first ) {
            return ( p1.first < p2.first ) ;
        }
        else {
            return ( p1.second > p2.second ) ;
        }
    };
    
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ].first >> b[ i ].second ;
    }
    sort ( b + 1 , b + m + 1 , cmp ) ;
    int mn_r = 1000000007 ;
    act.clear ( ) ;
    for ( int i = m ; i >= 1 ; -- i ) {
        if ( b[ i ].second >= mn_r ) { continue ; }
        int hh = getl ( b[ i ].first ) ;
        if ( hh + 1 <= n ) {
            if ( a[ hh + 1 ] < b[ i ].first || b[ i ].second < a[ hh + 1 ] ) {
                act.push_back ( b[ i ] ) ;
            }
        }
        else {
            act.push_back ( b[ i ] ) ;
        }
        mn_r = b[ i ].second ;
    }
    m = act.size ( ) ;
    sort ( act.begin ( ) , act.end ( ) ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        b[ i ] = act[ i - 1 ] ;
    }
}

long long dp[ 2 ][ MAXN ] ;
long long sm[ MAXN ] ;
long long lg[ MAXN ] ;

long long pref_sm[ MAXN ] ;
long long suff_lg[ MAXN ] ;


void solve ( ) {
    a[ 0 ] = -1000000007 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        lst[ i ] = getl ( b[ i ].first ) ;
        v[ lst[ i ] ].push_back ( i ) ;
    }
    int prv = 0 ;
    int nxt = 1 ;
    for ( int id = 0 ; id < 2 ; ++ id ) {
        for ( int i = 0 ; i < MAXN ; ++ i ) {
            dp[ id ][ i ] = inf ;
        }
    }
    dp[ prv ][ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = v[ i - 1 ].size ( ) ;
        for ( int j = 0 ; j <= sz ; ++ j ) {
            long long aux = dp[ prv ][ sz - j ] ;
            if ( j > 0 ) {
                aux += a[ i ] - b[ v[ i - 1 ][ sz - j ] ].second ;
            }
            lg[ j ] = aux ;
            if ( j > 0 ) {
                aux += a[ i ] - b[ v[ i - 1 ][ sz - j ] ].second ;
            }
            sm[ j ] = aux ;
        }
        pref_sm[ 0 ] = sm[ 0 ] ;
        suff_lg[ sz ] = lg[ sz ] ;
        for ( int j = 1 ; j <= sz ; ++ j ) {
            pref_sm[ j ] = min ( pref_sm[ j - 1 ] , sm[ j ] ) ;
        }
        for ( int j = sz - 1 ; j >= 0 ; -- j ) {
            suff_lg[ j ] = min ( suff_lg[ j + 1 ] , lg[ j ] ) ;
        }

        int nwsz = v[ i ].size ( ) ;
        int id = sz ;
        for ( int j = 0 ; j <= nwsz ; ++ j ) {
            int add = 0 ;
            if ( j > 0 ) {
                add = b[ v[ i ][ j - 1 ] ].first - a[ i ] ;
                while ( id > 0 && a[ i ] - b[ v[ i - 1 ][ id - 1 ] ].second <= add ) {
                    -- id ;
                }
            }
            dp[ nxt ][ j ] = add + pref_sm[ sz - id ] ;
            if ( id > 0 ) {
                dp[ nxt ][ j ] = min ( dp[ nxt ][ j ] , 2 * add + suff_lg[ sz - id + 1 ] ) ;
            }
        }
        for ( int j = 0 ; j <= sz ; ++ j ) {
            dp[ prv ][ j ] = inf ;
        }
        prv ^= 1 , nxt ^= 1 ;
    }
    cout << dp[ prv ][ (int)v[ n ].size ( ) ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}