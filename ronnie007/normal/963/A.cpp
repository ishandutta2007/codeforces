#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MOD 1000000009

long long n ;
long long a , b ;
int k ;

string str ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw != 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            pw -- ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    cin >> a >> b ;
    cin >> k ;
    cin >> str ;
}

void solve ( ) {
    int i ;
    long long sm = 0 ;
    long long cur = 1 ;
    cur = fastpow ( a , n ) ;
    long long inva = fastpow ( a , MOD - 2 ) ;
    for ( i = 0 ; i < k ; i ++ ) {
        long long zn = 1 ;
        if ( str[ i ] == '-' ) { zn = -1 ; }
        sm = ( sm + zn * cur ) % MOD ;
        if ( sm < 0 ) { sm += MOD ; }
        cur = ( cur * inva ) % MOD ;
        cur = ( cur * b ) % MOD ;
    }
    long long period = ( fastpow ( b , k ) * fastpow ( inva , k ) ) % MOD ;
    long long h = ( n + 1 ) / k ;
    long long numerator = 1 - fastpow ( period , h ) ;
    if ( numerator <= 0 ) { numerator += MOD ; }
    long long denominator = 1 - period ;
    if ( denominator == 0 ) {
        cout << ( h * sm ) % MOD << "\n" ;
        return ;
    }
    if ( denominator <= 0 ) { denominator += MOD ; }
    denominator = fastpow ( denominator , MOD - 2 ) ;
    cout << ( ( ( sm * numerator ) % MOD ) * denominator ) % MOD << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}