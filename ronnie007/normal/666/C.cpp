#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MOD 1000000007
#define MAXN 100007
#define LIM 307

long long pw26[ MAXN ] ;
long long pw25[ MAXN ] ;

long long fac[ MAXN ] ;
long long invfac[ MAXN ] ;

long long dp[ LIM + 7 ][ MAXN ] ;
long long curans[ MAXN ] ;

long long fastpow ( long long a , long long x ) {
	long long ret = 1 ;
    while ( x != 0 ) {
    	if ( x % 2 == 0 ) {
        	a = a * a ;
            a %= MOD ;
            x /= 2 ;
        }
        else {
        	ret = ret * a ;
            ret %= MOD ;
            x -- ;
        }
    }
    return ret ;
}

long long comb ( long long n , long long k ) {
	long long ret = fac[ n ] ;
    ret = ( ret * invfac[ k ] ) % MOD ;
    ret = ( ret * invfac[ ( n - k ) ] ) % MOD ;
    return ret ;
}

void input ( ) {
	int i , j ;
    pw25[ 0 ] = pw26[ 0 ] = 1 ;
    fac[ 0 ] = invfac[ 0 ] = 1 ;
    for ( i = 1 ; i <= 100000 ; i ++ ) {
    	pw25[ i ] = ( pw25[ i - 1 ] * 25 ) % MOD ;
        pw26[ i ] = ( pw26[ i - 1 ] * 26 ) % MOD ;
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
        invfac[ i ] = fastpow ( fac[ i ] , MOD - 2 ) ;
    }
    for ( i = 1 ; i <= LIM ; i ++ ) {
    	dp[ i ][ i ] = 1 ;
    	for ( j = i + 1 ; j <= 100000 ; j ++ ) {
        	dp[ i ][ j ] = ( dp[ i ][ j - 1 ] * 26 ) % MOD ;
            dp[ i ][ j ] += ( comb ( j - 1 , i - 1 ) * pw25[ j - i ] ) % MOD ;
            dp[ i ][ j ] %= MOD ;
        }
    }
}

void solve ( ) {
	int n ;
	cin >> n ;
    string s ;
    long long curlen ;
    cin >> s ;
    curlen = s.size ( ) ;
    int type , x ;
    int i ;    
	if ( curlen > LIM ) {
		for ( i = 0 ; i < curlen ; i ++ ) { curans[ i ] = 0 ; }
		curans[ curlen ] = 1 ;
		for ( i = curlen + 1 ; i <= 100000 ; i ++ ) {
			curans[ i ] = ( curans[ i - 1 ] * 26 ) % MOD ;
			curans[ i ] += ( comb ( i - 1 , curlen - 1 ) * pw25[ i - curlen ] ) % MOD ;
			curans[ i ] %= MOD ;
		}
	}    
    while ( n != 0 ) {
    	n -- ;
        cin >> type ;
        if ( type == 1 ) {
        	cin >> s ;
            curlen = s.size ( ) ;
            if ( curlen > LIM ) {
            	for ( i = 0 ; i < curlen ; i ++ ) { curans[ i ] = 0 ; }
                curans[ curlen ] = 1 ;
                for ( i = curlen + 1 ; i <= 100000 ; i ++ ) {
                	curans[ i ] = ( curans[ i - 1 ] * 26 ) % MOD ;
                    curans[ i ] += ( comb ( i - 1 , curlen - 1 ) * pw25[ i - curlen ] ) % MOD ;
                    curans[ i ] %= MOD ;
                }
            }
        }
        else {
        	cin >> x ;
            if ( curlen <= LIM ) { cout << dp[ curlen ][ x ] << "\n" ; }
            else { cout << curans[ x ] << "\n" ; }
        }
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}