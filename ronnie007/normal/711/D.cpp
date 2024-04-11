#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;
int used[ MAXN ] ;
int dist[ MAXN ] ;

long long fpow ( long long a , long long x ) {
	long long ret = 1 ;
    while ( x != 0 ) {
    	if ( ( x % 2 ) == 0 ) {
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

int dfs ( int vertex , int id ) {
	used[ vertex ] = id ;
	if ( used[ a[ vertex ] ] == 0 ) {
    	dist[ a[ vertex ] ] = dist[ vertex ] + 1 ;
        return dfs ( a[ vertex ] , id ) ;
    }
    else {
    	if ( used[ a[ vertex ] ] == used[ vertex ] ) {
	    	return ( dist[ vertex ] - dist[ a[ vertex ] ] + 1 ) ;
		}
        return 0 ;
    }
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int i ;
    int id = 1 ;
    long long ans = 1 ;
    int tot = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( used[ i ] == 0 ) {
        	int ret = dfs ( i , id ) ;
            id ++ ;
           	if ( ret >= 2 ) { ans *= ( fpow ( 2 , ret ) - 2 + MOD ) % MOD ; }
            ans %= MOD ;
            tot += ret ;
        }
    }
    ans *= fpow ( 2 , ( n - tot ) ) ;
    ans %= MOD ;
	cout << ans << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}