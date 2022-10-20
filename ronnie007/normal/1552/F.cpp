#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MOD 998244353
#define MAXN 400007

int n ;
pair < long long , long long > a[ MAXN ] ;
int init[ MAXN ] ;
int pos[ MAXN ] ;

long long ans = 0 ;
long long sub[ MAXN ] ;

int f ( int sr ) {
    int l , r , mid ;
    l = 1 , r = n ;
    while ( r - l > 3 ) {
        int mid = ( l + r ) / 2 ;
        if ( a[ mid ].first < sr ) {
            l = mid ; 
        }
        else { r = mid ; }
    }
    while ( a[ l ].first < sr ) { ++ l ; }
    return l ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second >> init[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        pos[ i ] = f ( a[ i ].second ) ;
    }
    ans = ( a[ n ].first + 1 ) % MOD ;
    long long coef = 1 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        coef = ( coef - sub[ i ] + MOD ) % MOD ;
        long long bad = 0 ;
        if ( init[ i ] == 0 ) {
            bad = coef - 1 ;
            coef = ( 2 * coef - 1 ) % MOD ;
        }
        else {
            bad = coef ;
            coef = ( 2 * coef ) % MOD ;
        }
        ans += ( bad * ( a[ i ].first - a[ i ].second ) ) % MOD ;
        ans %= MOD ;
        sub[ pos[ i ] - 1 ] += bad ;
        sub[ pos[ i ] - 1 ] %= MOD ;
    }
    cout << ans << "\n" ;
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