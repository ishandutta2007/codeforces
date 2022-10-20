#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;

long long sm ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

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
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

void solve ( ) {
    if ( ( sm % n ) != 0 ) {
        cout << "0\n" ;
        return ;
    }
    map < int , int > w ;
    long long ans = 1 ;
    long long aux = ( sm / n ) ;
    int x , y , eq ;
    x = y = eq = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        x += ( a[ i ] > aux ) ;
        y += ( a[ i ] < aux ) ;
        eq += ( a[ i ] == aux ) ;
        if ( a[ i ] != aux ) { ++ w[ a[ i ] ] ; }
    }
    if ( eq == n ) {
        cout << "1\n" ;
        return ;
    }
    ans = ( fac[ x ] * fac[ y ] ) % MOD ;
    ans = ( ans * 2 ) % MOD ;

    if ( x == 1 || y == 1 ) {
        ans = fac[ x + y ] ;
    }
    
    for ( auto [ val , freq ] : w ) {
        ans = ( ans * inv[ freq ] ) % MOD ;
    }
    ans = ( ans * fac[ n ] ) % MOD ;
    ans = ( ans * inv[ eq ] ) % MOD ;
    ans = ( ans * inv[ n - eq ] ) % MOD ;
    cout << ans << "\n" ;
}


int main ( ) {
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