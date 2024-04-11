#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 1000007

long long inf ;

int n , m ;
vector < pair < int , int > > gr[ MAXN ] ;
long long dist[ MAXN ] ;

vector < int > ord ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int LEAVES ;

vector < long long > v[ 3 * MAXN ] ;
vector < long long > pref[ 3 * MAXN ] ;

void dfs ( int vertex ) {
    int i ;
    int sz = gr[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        dist[ gr[ vertex ][ i ].first ] = dist[ vertex ] + gr[ vertex ][ i ].second ;
        dfs ( gr[ vertex ][ i ].first ) ;
    }
}

void calc ( int where ) {
    int sz1 = v[ 2 * where ].size ( ) ;
    int sz2 = v[ 2 * where + 1 ].size ( ) ;
    vector < int > aux ;
    aux.push_back ( dist[ where ] ) ;
    int sz3 = 1 ;
    int pos1 , pos2 , pos3 ;
    pos1 = pos2 = pos3 = 0 ;
    while ( pos1 < sz1 || pos2 < sz2 || pos3 < sz3 ) {
        int val1 , val2 , val3 ;
        val1 = val2 = val3 = inf ;
        if ( pos1 < sz1 ) {
            val1 = v[ 2 * where ][ pos1 ] ;
        }
        if ( pos2 < sz2 ) {
            val2 = v[ 2 * where + 1 ][ pos2 ] ;
        }
        if ( pos3 < sz3 ) {
            val3 = aux[ pos3 ] ;
        }
        if ( val1 <= val2 && val1 <= val3 ) {
            v[ where ].push_back ( val1 ) ;
            pos1 ++ ;
        }
        else if ( val2 <= val1 && val2 <= val3 ) {
            v[ where ].push_back ( val2 ) ;
            pos2 ++ ;
        }
        else {
            v[ where ].push_back ( val3 ) ;
            pos3 ++ ;
        }
    }
    int sz = v[ where ].size ( ) ;
    pref[ where ].resize ( sz + 1 ) ;
    pref[ where ][ 0 ] = 0 ;
    int i ;
    for ( i = 1 ; i <= sz ; i ++ ) {
        pref[ where ][ i ] = ( pref[ where ][ i - 1 ] + v[ where ][ i - 1 ] ) ;
    }
}

int find_id ( int where , long long sr ) {
    int l , r , mid ;
    l = 0 ;
    r = v[ where ].size ( ) - 1 ;
    if ( v[ where ][ r ] < sr ) { return r ; }
    if ( v[ where ][ l ] > sr ) { return -1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ where ][ mid ] < sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( v[ where ][ r ] >= sr ) { r -- ; }
    return r ;
}
long long getsm ( int where , int lca , int st , long long maxlen ) {
    if ( v[ where ].size ( ) == 0 ) { return 0 ; }
    long long sr = maxlen - dist[ st ] + 2 * dist[ lca ] ;
    int id = find_id ( where , sr ) ;
    id ++ ;
    return ( id * maxlen - ( pref[ where ][ id ] + id * dist[ st ] - 2 * id * dist[ lca ] ) ) ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        gr[ ( i / 2 ) ].push_back ( make_pair ( i , x ) ) ;
    }
    inf = 1 ;
    for ( i = 1 ; i <= 17 ; i ++ ) { inf *= 10 ; }
}

void solve ( ) {
    dfs ( 1 ) ;
    int i ;
    for ( i = n ; i >= 1 ; i -- ) {
        if ( 2 * i > n ) {
            v[ i ].push_back ( dist[ i ] ) ;
            pref[ i ].resize ( 2 ) ;
            pref[ i ][ 0 ] = 0 ;
            pref[ i ][ 1 ] = v[ i ][ 0 ] ;
        }
        else {
            calc ( i ) ;
        }
    }
    long long x , y ;
    while ( m != 0 ) {
        m -- ;
        scanf ( "%I64d%I64d" , &x , &y ) ;
        long long ans = 0 ;
        int h = x ;
        ans += getsm ( x , x , x , y ) ;
        h /= 2 ;
        int lst = x ;
        while ( h != 0 ) {
            int where = ( 4 * h + 1 - lst ) ;
            ans += getsm ( where , h , x , y ) ;
            if ( dist[ x ] - dist[ h ] <= y ) {
                ans += y - dist[ x ] + dist[ h ] ;
            }
            lst = h ;
            h /= 2 ;
        }
        printf ( "%I64d\n" , ans ) ;
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}