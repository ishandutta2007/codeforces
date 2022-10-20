#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MOD 1000000007

int n ;
long long ans = 0 ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;
int tot[ MAXN ] ;

long long dp[ 2 ][ 20 ][ 2 ] ;


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

void init ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

void f ( int st1 , int st2 ) {
    int prv = 0 ;
    int nxt = 1 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 20 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dp[ i ][ j ][ t ] = 0 ;
            }
        }
    }
    dp[ prv ][ st1 ][ st2 ] = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 20 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                if ( dp[ prv ][ j ][ t ] == 0 ) { continue ; }
                int val = (1<<j) ;
                if ( t == 1 ) { val *= 3 ; }
                int lft = n / val ;
                if ( lft >= i ) {
                    dp[ nxt ][ j ][ t ] += ( lft - i + 1 ) * dp[ prv ][ j ][ t ] ;
                    dp[ nxt ][ j ][ t ] %= MOD ;
                }
                if ( j > 0 ) {
                    dp[ nxt ][ j - 1 ][ t ] += ( n / ( val / 2 ) - lft ) * dp[ prv ][ j ][ t ] ;
                    dp[ nxt ][ j - 1 ][ t ] %= MOD ;
                }
                if ( t > 0 ) {
                    dp[ nxt ][ j ][ t - 1 ] += ( n / ( val / 3 ) - lft  ) * dp[ prv ][ j ][ t ] ;
                    dp[ nxt ][ j ][ t - 1 ] %= MOD ;
                }
            }
        }
        for ( int j = 0 ; j < 20 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dp[ prv ][ j ][ t ] = 0 ;
            }
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    ans = ( ans + dp[ prv ][ 0 ][ 0 ] ) % MOD ;
}


void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int h = 1 ;
    int cnt = 0 ;
    while ( 2 * h <= n ) { h *= 2 ; ++ cnt ; }
    f ( cnt , 0 ) ;
    if ( 3 * ( h / 2 ) <= n ) {
        f ( cnt - 1 , 1 ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}