#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define MOD 1000000007

int n ;
long long a[ MAXN ] ;

int ans ;
int cnt[ 63 ] ;

void add ( long long x , int coef ) {
    for ( int j = 0 ; j < 60 ; ++ j ) {
        long long sr = (1LL << j ) ;
        if ( ( x & sr ) > 0 ) { cnt[ j ] += coef ; }
    }
}

void input ( ) {
    for ( int i = 0 ; i <= 61 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lld" , &a[ i ] ) ;
        add ( a[ i ] , 1 ) ;
    }
}

void solve ( ) {
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int coef1 , coef2 ;
        coef1 = 0 ;
        coef2 = 0 ;
        for ( int j = 0 ; j < 60 ; ++ j ) {
            long long sr = (1LL << j ) ;
            if ( ( a[ i ] & sr ) > 0 ) {
                coef1 += ( ( sr % MOD ) * cnt[ j ] ) % MOD ;
                if ( coef1 >= MOD ) { coef1 -= MOD ; }

                coef2 += ( ( sr % MOD ) * n ) % MOD ;
                if ( coef2 >= MOD ) { coef2 -= MOD ; }
            }
            else {
                coef2 += ( ( sr % MOD ) * cnt[ j ] ) % MOD ;
                if ( coef2 >= MOD ) { coef2 -= MOD ; }
            }
        }
        ans += ( 1LL * coef1 * coef2 ) % MOD ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}