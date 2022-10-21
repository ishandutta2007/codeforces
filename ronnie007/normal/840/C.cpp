#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307
#define MOD 1000000007

int n ;
int a[ MAXN ] ;

bool used[ MAXN ] ;

vector < pair < int , int > > divs[ MAXN ] ;

vector < int > v ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long dp[ 2 ][ MAXN ] ;

long long fastpow ( long long x , long long st ) {
    long long ret = 1 ;
    while ( st > 0 ) {
        if ( ( st % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            st /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- st ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        int j = 2 ;
        while ( j * j <= a[ i ] ) {
            int cnt = 0 ;
            while ( ( a[ i ] % j ) == 0 ) {
                ++ cnt ;
                a[ i ] /= j ;
            }
            if ( cnt > 0 ) {
                divs[ i ].push_back ( { j , cnt } ) ;
            }
            ++ j ;
        }
        if ( a[ i ] > 1 ) {
            divs[ i ].push_back ( { a[ i ] , 1 } ) ;
        }
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n + 2 ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n + 2 ] = fastpow ( fac[ n + 2 ] , MOD - 2 ) ;
    for ( int i = n + 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

bool f ( int x , int y ) {
    int sz1 = divs[ x ].size ( ) ;
    int sz2 = divs[ y ].size ( ) ;
    int pos1 , pos2 ;
    pos1 = pos2 = 0 ;
    while ( pos1 < sz1 || pos2 < sz2 ) {
        if ( pos1 == sz1 ) {
            if ( divs[ y ][ pos2 ++ ].second % 2 == 1 ) { return false ; }
        }
        else if ( pos2 == sz2 ) {
            if ( divs[ x ][ pos1 ++ ].second % 2 == 1 ) { return false ; }
        }
        else {
            if ( divs[ x ][ pos1 ].first < divs[ y ][ pos2 ].first ) {
                if ( divs[ x ][ pos1 ++ ].second % 2 == 1 ) { return false ; }
            }
            else if ( divs[ x ][ pos1 ].first > divs[ y ][ pos2 ].first ) {
                if ( divs[ y ][ pos2 ++ ].second % 2 == 1 ) { return false ; }
            }
            else {
                int aux = divs[ x ][ pos1 ++ ].second ;
                aux += divs[ y ][ pos2 ++ ].second ;
                if ( aux % 2 == 1 ) { return false ; }
            }
        }
    }
    return true ;
}

long long get_comb ( int n , int k ) {
    long long ret = fac[ n ] ;
    ret = ( ret * inv[ k ] ) % MOD ;
    ret = ( ret * inv[ n - k ] ) % MOD ;
    return ret ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        used[ i ] = true ;
        int cnt = 1 ;
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            if ( f ( i , j ) == true ) {
                ++ cnt ;
                used[ j ] = true ;
            }
        }
        v.push_back ( cnt ) ;
    }
    int sz = v.size ( ) ;
    int prv = 0 ;
    int nxt = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        dp[ prv ][ i ] = dp[ nxt ][ i ] = 0 ;
    }
    dp[ prv ][ v[ 0 ] - 1 ] = fac[ v[ 0 ] ] ;
    int sm = v[ 0 ] ;
    for ( int i = 1 ; i < sz ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( dp[ prv ][ j ] == 0 ) { continue ; }
            int sr = min ( sm + 1 , v[ i ] ) ;
            for ( int t = 1 ; t <= sr ; ++ t ) {
                long long coef = get_comb ( v[ i ] - 1 , t - 1 ) ;
                coef = ( coef * fac[ v[ i ] ] ) % MOD ;
                for ( int z = 0 ; z <= min ( j , t ) ; ++ z ) {
                    long long aux = get_comb ( j , z ) ;
                    aux = ( aux * get_comb ( sm + 1 - j , t - z ) ) % MOD ;
                    aux = ( aux * coef ) % MOD ;
                    aux = ( aux * dp[ prv ][ j ] ) % MOD ;
                    dp[ nxt ][ j - z + ( v[ i ] - t ) ] = ( dp[ nxt ][ j - z + ( v[ i ] - t ) ] + aux ) % MOD ;
                }
            }
        }
        sm += v[ i ] ;
        for ( int j = 0 ; j < n ; ++ j ) {
            dp[ prv ][ j ] = 0 ;
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    cout << dp[ prv ][ 0 ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}