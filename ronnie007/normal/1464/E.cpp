#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MOD 998244353
#define MAGIC 512

int n , m ;
vector < int > v[ MAXN ] ;
int sg[ MAXN ] ;
int used[ MAXN ] ;

int cnt[ MAGIC ] ;

int a[ MAGIC ][ MAGIC ] ;
int b[ MAGIC ] ;

bool ww[ MAGIC ] ;

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    sz = min ( sz , 510 ) ;
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == 0 ) { dfs ( x ) ; }
    }
    for ( int i = 0 ; i <= sz + 1 ; ++ i ) { ww[ i ] = false ; }
    for ( auto x : v[ vertex ] ) {
        ww[ sg[ x ] ] = true ;
    }
    for ( int i = 0 ; i < MAGIC ; ++ i ) {
        if ( ww[ i ] == false ) { sg[ vertex ] = i ; break ; }
    }
}


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

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) { dfs ( i ) ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) { ++ cnt[ sg[ i ] ] ; }

    for ( int i = 0 ; i < MAGIC ; ++ i ) {
        for ( int j = 0 ; j < MAGIC ; ++ j ) {
            int nw = i ^ j ;
            a[ i ][ nw ] = cnt[ j ] ;
        }
        b[ i ] = MOD - ( i != 0 ) ;
    }
    for ( int i = 0 ; i < MAGIC ; ++ i ) {
        a[ i ][ i ] = a[ i ][ i ] - ( n + 1 ) ;
        if ( a[ i ][ i ] < 0 ) { a[ i ][ i ] += MOD ; }
    }
    for ( int i = 0 ; i < MAGIC ; ++ i ) {
        if ( a[ i ][ i ] == 0 ) {
            for ( int j = i + 1 ; j < MAGIC ; ++ j ) {
                if ( a[ j ][ i ] != 0 ) {
                    for ( int t = 0 ; t < MAGIC ; ++ t ) {
                        swap ( a[ i ][ t ] , a[ j ][ t ] ) ;
                    }
                    swap ( b[ i ] , b[ j ] ) ;
                }
            }
        }
        int hh = fastpow ( a[ i ][ i ] , MOD - 2 ) ;
        if ( hh == 0 ) { continue ; }
        for ( int j = 0 ; j < MAGIC ; ++ j ) {
            if ( i == j ) { continue ; }
            if ( a[ j ][ i ] == 0 ) { continue ; }
            int coef = ( 1LL * a[ j ][ i ] * hh ) % MOD ;
            for ( int t = 0 ; t < MAGIC ; ++ t ) {
                if ( a[ i ][ t ] == 0 ) { continue ; }
                int val = ( 1LL * coef * a[ i ][ t ] ) % MOD ;
                a[ j ][ t ] = ( a[ j ][ t ] - val ) ;
                if ( a[ j ][ t ] < 0 ) { a[ j ][ t ] += MOD ; }
            }
            int val = ( 1LL * coef * b[ i ] ) % MOD ;
            b[ j ] = ( b[ j ] - val ) ;
            if ( b[ j ] < 0 ) { b[ j ] += MOD ; }
        }
    }
    b[ 0 ] = ( 1LL * b[ 0 ] * fastpow ( a[ 0 ][ 0 ] , MOD - 2 ) ) % MOD ;
    printf ( "%d\n" , b[ 0 ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}