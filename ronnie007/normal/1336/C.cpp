#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MOD 998244353
#define MAXN 3007

int n ;
int pattern_size ;

string a ;
string pattern ;

long long dp[ MAXN ][ MAXN ][ 2 ] ;

long long pw[ MAXN ] ;

string rev ( string x ) {
    string ret ;
    ret.clear ( ) ;
    int sz = x.size ( ) ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        ret += x[ i ] ;
    }
    return ret ;
}

void input ( ) {
    cin >> a ;
    cin >> pattern ;
    pattern_size = pattern.size ( ) ;
    a = rev ( a ) ;
    n = a.size ( ) ;
}

void solve ( ) {
    dp[ 0 ][ 0 ][ 0 ] = 1 ;
    long long ans = 0 ;

    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= pattern_size ; ++ j ) {
            for ( int type = 0 ; type < 2 ; ++ type ) {
                if ( dp[ i ][ j ][ type ] == 0 ) { continue ; }
                if ( type == 0 && n - i < pattern_size ) { continue ; }
                if ( j < pattern_size ) {
                    if ( a[ i ] == pattern[ j ] ) {
                        dp[ i + 1 ][ j + 1 ][ 1 ] += dp[ i ][ j ][ type ] ;
                        while ( dp[ i + 1 ][ j + 1 ][ 1 ] >= MOD ) {
                            dp[ i + 1 ][ j + 1 ][ 1 ] -= MOD ;
                        }
                    }
                }
                else {
                    dp[ i + 1 ][ j ][ 1 ] += dp[ i ][ j ][ type ] ;
                    while ( dp[ i + 1 ][ j ][ 1 ] >= MOD ) {
                        dp[ i + 1 ][ j ][ 1 ] -= MOD ;
                    }                    
                }
                if ( type == 0 ) {
                    dp[ i + 1 ][ j ][ 0 ] += dp[ i ][ j ][ type ] ;
                    while ( dp[ i + 1 ][ j ][ 0 ] >= MOD ) {
                        dp[ i + 1 ][ j ][ 0 ] -= MOD ;
                    }                
                }
                int sr_id = n - ( i - j ) - 1 ;
                if ( sr_id >= pattern_size ) {
                    dp[ i + 1 ][ j ][ 1 ] += dp[ i ][ j ][ type ] ;
                    while ( dp[ i + 1 ][ j ][ 1 ] >= MOD ) {
                        dp[ i + 1 ][ j ][ 1 ] -= MOD ;
                    }
                }
                if ( sr_id < pattern_size && pattern[ sr_id ] == a[ i ] ) {
                    dp[ i + 1 ][ j ][ 1 ] += dp[ i ][ j ][ type ] ;
                    while ( dp[ i + 1 ][ j ][ 1 ] >= MOD ) {
                        dp[ i + 1 ][ j ][ 1 ] -= MOD ;
                    }
                }
            }
        }
    }
    for ( int i = 0 ; i <= pattern_size ; ++ i ) {
        ans += dp[ n ][ i ][ 1 ] ;
        while ( ans >= MOD ) { ans -= MOD ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}