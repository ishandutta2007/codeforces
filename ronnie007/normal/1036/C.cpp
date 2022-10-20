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

int q ;

long long dp[ 22 ][ 5 ][ 3 ] ;

long long calc ( string x ) {
    int i , j , t , z ;
    for ( i = 0 ; i <= 20 ; i ++ ) {
        for ( j = 0 ; j <= 4 ; j ++ ) {
            for ( t = 0 ; t < 2 ; t ++ ) {
                dp[ i ][ j ][ t ] = 0 ;
            }
        }
    }
    dp[ 0 ][ 0 ][ 1 ] = 1 ;
    int sz = x.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        for ( j = 0 ; j < 4 ; j ++ ) {
            for ( t = 0 ; t < 2 ; t ++ ) {
                if ( j == 3 ) {
                    int nw = t ;
                    if ( x[ i ] != '0' ) { nw = 0 ; }
                    dp[ i + 1 ][ j ][ nw ] += dp[ i ][ j ][ t ] ;
                }
                else {
                    int sr = ( x[ i ] - '0' ) ;
                    for ( z = 0 ; z < 10 ; z ++ ) {
                        if ( z > sr && t == 1 ) { break ; }
                        int nw = t ;
                        if ( z < sr ) { nw = 0 ; }
                        int add = 0 ;
                        if ( z > 0 ) { add ++ ; }
                        dp[ i + 1 ][ j + add ][ nw ] += dp[ i ][ j ][ t ] ;
                    }
                }
            }
        }
    }
    long long ans = 0 ;
    for ( j = 0 ; j < 4 ; j ++ ) {
        for ( t = 0 ; t < 2 ; t ++ ) {
            ans += dp[ sz ][ j ][ t ] ;
        }
    }
    return ans ;
}

string get_str ( long long x ) {
    string aux ;
    aux.clear ( ) ;
    while ( x != 0 ) {
        aux += ( char ( ( x % 10 ) + '0' ) ) ;
        x /= 10 ;
    }
    int sz = aux.size ( ) ;
    string ret ;
    for ( int i = sz - 1 ; i >= 0 ; i -- ) {
        ret += aux[ i ] ;
    }
    return ret ;
}

void input ( ) {
    cin >> q ;
}

void solve ( ) {
    while ( q != 0 ) {
        q -- ;
        long long st , en ;
        cin >> st >> en ;
        cout << calc ( get_str ( en ) ) - calc ( get_str ( st - 1 ) ) << "\n" ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}