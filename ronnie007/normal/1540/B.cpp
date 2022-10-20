#include<bits/stdc++.h>
using namespace std ;

#define MAXN 407
#define LOG 11
#define MOD 1000000007

int n ;
vector < int > v[ MAXN ] ;

int st[ MAXN ] , en[ MAXN ] ;
int depth[ MAXN ] ;

int LCA[ MAXN ][ LOG ] ;

long long ans = 0 ;

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

int tp ;

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( depth[ x ] - ( 1 << i ) >= depth[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( depth[ y ] - ( 1 << i ) >= depth[ x ] ) {
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

void dfs ( int vertex , int prv ) {
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    st[ vertex ] = ++ tp ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        depth[ x ] = depth[ vertex ] + 1 ;
        LCA[ x ][ 0 ] = vertex ;
        dfs ( x , vertex ) ;
    }
    en[ vertex ] = tp ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

long long f[ MAXN ][ MAXN ] ;

void solve ( ) {
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ][ 0 ] = 1 ;
    }
    long long inv2 = fastpow ( 2 , MOD - 2 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            f[ i ][ j ] = f[ i - 1 ][ j ] + f[ i ][ j - 1 ] ;
            f[ i ][ j ] = ( f[ i ][ j ] * inv2 ) % MOD ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        depth[ i ] = 0 ;
        for ( int j = 0 ; j < LOG ; ++ j ) {
            LCA[ i ][ j ] = 0 ;
        }
        tp = 0 ;
        dfs ( i , -1 ) ;
        ans += ( i - 1 ) ;
        ans %= MOD ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( j == i ) { continue ; }
            for ( int t = j + 1 ; t <= n ; ++ t ) {
                if ( t == i ) { continue ; }
                if ( st[ j ] <= st[ t ] && en[ t ] <= en[ j ] ) { continue ; }
                if ( st[ t ] <= st[ j ] && en[ j ] <= en[ t ] ) { ++ ans ; ans %= MOD ; continue ; }

                int wtf = get_LCA ( j , t ) ;
                ans = ( ans + f[ depth[ j ] - depth[ wtf ] ][ depth[ t ] - depth[ wtf ] ] ) % MOD ;
            }
        }
    }
    ans = ( ans * fastpow ( n , MOD - 2 ) ) % MOD ;
    cout << ans << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}