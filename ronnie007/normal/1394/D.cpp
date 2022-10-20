#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long cost[ MAXN ] ;
int h[ MAXN ] ;

int in[ MAXN ] ;
int out[ MAXN ] ;

bool used[ MAXN ] ;
vector < int > v[ MAXN ] ;

long long ans = 0 ;

long long dp[ MAXN ][ 2 ] ;
long long root[ MAXN ] ;

bool cmp ( int x , int y ) {
    return ( dp[ x ][ 0 ] - dp[ x ][ 1 ] > dp[ y ][ 0 ] - dp[ y ][ 1 ] ) ;
}

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    vector < int > aux ;
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == true ) { continue ; }
        dfs ( x ) ;
        aux.push_back ( x ) ;
    }
    sort ( aux.begin ( ) , aux.end ( ) , cmp ) ;
    int sz = aux.size ( ) ;
    long long sm = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        sm += dp[ aux[ i ] ][ 1 ] ;
    }
    for ( int i = 0 ; i <= sz ; ++ i ) {
        long long cnt1 = min ( in[ vertex ] + i , out[ vertex ] + sz - i ) ;
        root[ vertex ] = max ( root[ vertex ] , cnt1 * cost[ vertex ] + sm ) ;
        cnt1 = min ( in[ vertex ] + i + 1 , out[ vertex ] + sz - i ) ;
        dp[ vertex ][ 1 ] = max ( dp[ vertex ][ 1 ] , cnt1 * cost[ vertex ] + sm ) ;
        cnt1 = min ( in[ vertex ] + i , out[ vertex ] + sz - i + 1 ) ;
        dp[ vertex ][ 0 ] = max ( dp[ vertex ][ 0 ] , cnt1 * cost[ vertex ] + sm ) ;
        if ( i < sz ) {
            sm -= dp[ aux[ i ] ][ 1 ] ;
            sm += dp[ aux[ i ] ][ 0 ] ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lld" , &cost[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &h[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( h[ x ] == h[ y ] ) {
            v[ x ].push_back ( y ) ;
            v[ y ].push_back ( x ) ;
        }
        else if ( h[ x ] < h[ y ] ) {
            ++ in[ y ] ;
            ++ out[ x ] ;
        }
        else {
            ++ in[ x ] ;
            ++ out[ y ] ;
        }
        ans += cost[ x ] + cost[ y ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs ( i ) ;
            ans -= root[ i ] ;
        }
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}