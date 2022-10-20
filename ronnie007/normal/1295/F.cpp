#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353
#define MAXN 107

int n ;
pair < int , int > a[ MAXN ] ;

vector < int > v ;
long long dp[ MAXN ][ MAXN ] ;
long long inv[ MAXN ] ;
long long prec[ MAXN ] ;

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
    scanf ( "%d" , &n ) ;
    set < int > s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        s.insert ( a[ i ].first ) ;
        s.insert ( a[ i ].second + 1 ) ;
        inv[ i ] = fastpow ( a[ i ].second - a[ i ].first + 1 , MOD - 2 ) ;
    }
    for ( auto x : s ) { v.push_back ( x ) ; }
    for ( int i = 0 ; i <= n ; ++ i ) {
        prec[ i ] = fastpow ( i , MOD - 2 ) ;
    }
}

long long comb ( int up , int down ) {
    if ( up < down ) { return 0 ; }
    if ( down < up - down ) { down = up - down ; }
    long long ret = 1 ;
    for ( int i = down + 1 ; i <= up ; ++ i ) {
        ret = ( ret * i ) % MOD ;
    }
    for ( int i = 1 ; i <= up - down ; ++ i ) {
        ret = ( ret * prec[ i ] ) % MOD ;
    }
    return ret ;
}

void solve ( ) {
    int sz = v.size ( ) ;
    if ( sz == 1 ) {
        printf ( "1\n" ) ;
        return ;
    }
    dp[ 0 ][ sz - 1 ] = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = sz - 1 ; j >= 0 ; -- j ) {
            if ( dp[ i ][ j ] == 0 ) { continue ; }
            int st , en ;
            for ( int nw = j - 1 ; nw >= 0 ; -- nw ) {
                st = v[ nw ] ;
                en = v[ nw + 1 ] - 1 ;
                long long coef = 1 ;
                for ( int t = i + 1 ; t <= n ; ++ t ) {
                    int cross = min ( en , a[ t ].second ) - max ( st , a[ t ].first ) + 1 ;
                    if ( cross <= 0 ) { break ; }
                    
                    coef = ( coef * inv[ t ] ) % MOD ;
                    long long aux = comb ( en - st + t - i , t - i ) ;
                    aux = ( aux * coef ) % MOD ;
                    dp[ t ][ nw ] += ( dp[ i ][ j ] * aux ) % MOD ;
                    if ( dp[ t ][ nw ] >= MOD ) { dp[ t ][ nw ] -= MOD ; }
                }
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        ans += dp[ n ][ i ] ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}