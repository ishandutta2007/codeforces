#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAXK 12
#define MOD 1000000007

int n ;
long long m ;
vector < int > v[ MAXN ] ;
int tot , k ;

long long dp[ MAXN ][ MAXK ][ 3 ] ;
bool vis[ MAXN ][ MAXK ] ;


void dfs ( int vertex , int br , int prv ) {
    if ( vis[ vertex ][ br ] == true ) { return ; }
    vis[ vertex ][ br ] = true ;
    int i , j , t ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        for ( j = 0 ; j <= br ; j ++ ) {
            dfs ( v[ vertex ][ i ] , j , vertex ) ;
        }
    }
    if ( sz == 1 && prv != -1 ) {
        if ( br == 0 ) {
            dp[ vertex ][ br ][ 0 ] = ( m - 1 ) ;
            dp[ vertex ][ br ][ 1 ] = ( k - 1 ) ;
            dp[ vertex ][ br ][ 2 ] = ( m - 1 ) ;
        }
        else if ( br == 1 ) {
            dp[ vertex ][ br ][ 0 ] = 1 ;
            dp[ vertex ][ br ][ 1 ] = 0 ;
            dp[ vertex ][ br ][ 2 ] = 0 ;
            ///return ;
        }
        else {
            dp[ vertex ][ br ][ 0 ] = dp[ vertex ][ br ][ 1 ] = 0 ;
        }
        return ;
    }
    long long val[ 17 ] ;
    long long g[ 17 ] ;
    long long u , w , p ;
    u = w = p = 0 ;
    for ( i = 0 ; i <= br ; i ++ ) {
        val[ i ] = 0 ;
    }
    val[ 0 ] = 1 ;
    /// vertex --> small
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        for ( j = 0 ; j <= br ; j ++ ) {
            g[ j ] = 0 ;
        }
        for ( j = 0 ; j <= br ; j ++ ) {
            for ( t = 0 ; t + j <= br ; t ++ ) {
                long long cur = ( val[ t ] * dp[ v[ vertex ][ i ] ][ j ][ 0 ] ) % MOD ;
                g[ t + j ] = ( g[ t + j ] + cur ) % MOD ;
            }
        }
        for ( j = 0 ; j <= br ; j ++ ) {
            val[ j ] = g[ j ] ;
        }
    }
    u = val[ br ] ;
    ///printf ( "---- %I64d\n" , u ) ;
    u = ( u * ( k - 1 ) ) % MOD ;
    /// vertex --> >= k
    for ( i = 0 ; i <= br ; i ++ ) {
        val[ i ] = 0 ;
    }
    val[ 0 ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        for ( j = 0 ; j <= br ; j ++ ) {
            g[ j ] = 0 ;
        }
        for ( j = 0 ; j <= br ; j ++ ) {
            for ( t = 0 ; t + j <= br ; t ++ ) {
                long long cur = ( val[ t ] * dp[ v[ vertex ][ i ] ][ j ][ 1 ] ) % MOD ;
                g[ t + j ] = ( g[ t + j ] + cur ) % MOD ;
            }
        }
        for ( j = 0 ; j <= br ; j ++ ) {
            val[ j ] = g[ j ] ;
        }
    }
    if ( br != 0 ) { p = val[ br - 1 ] ; }

    for ( i = 0 ; i <= br ; i ++ ) {
        val[ i ] = 0 ;
    }
    val[ 0 ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        for ( j = 0 ; j <= br ; j ++ ) {
            g[ j ] = 0 ;
        }
        for ( j = 0 ; j <= br ; j ++ ) {
            for ( t = 0 ; t + j <= br ; t ++ ) {
                long long cur = ( val[ t ] * dp[ v[ vertex ][ i ] ][ j ][ 2 ] ) % MOD ;
                g[ t + j ] = ( g[ t + j ] + cur ) % MOD ;
            }
        }
        for ( j = 0 ; j <= br ; j ++ ) {
            val[ j ] = g[ j ] ;
        }
    }
    w = val[ br ] ;
    w = ( w * ( m - k ) ) % MOD ;

    dp[ vertex ][ br ][ 0 ] = ( u + p + w ) % MOD ;
    dp[ vertex ][ br ][ 1 ] = u ;
    dp[ vertex ][ br ][ 2 ] = ( u + w ) % MOD ;
}

void input ( ) {
    scanf ( "%d%I64d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    scanf ( "%d%d" , &k , &tot ) ;
}

void solve ( ) {
    int i ;
    for ( i = tot ; i >= 0 ; i -- ) {
        dfs ( 1 , i , -1 ) ;
    }
    long long ans = 0 ;
    for ( i = 0 ; i <= tot ; i ++ ) {
        ans += dp[ 1 ][ i ][ 0 ] ;
        ans %= MOD ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}