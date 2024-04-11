#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
using namespace std ;

unsigned long long inf = 1 ;

unsigned long long k ;
unsigned long long n ;
string a ;

unsigned long long dp[ 72 ] ;
bool f[ 72 ] ;

void input ( ) {
    cin >> k ;
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    f[ 0 ] = true ;
    dp[ 0 ] = 0 ;
    int i , j , t ;
    for ( i = 1 ; i <= 18 ; i ++ ) { inf *= 10 ; }
    for ( i = 1 ; i <= n ; i ++ ) {
        f[ i ] = false ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        string u ;
        u.clear ( ) ;
        for ( j = i ; j >= 1 ; j -- ) {
            u.clear ( ) ;
            for ( t = j ; t <= i ; t ++ ) {
                u += a[ t - 1 ] ;
            }
            unsigned long long p = atol( u.c_str() ) ;
            if ( p >= k ) { break ; }
            if ( a[ j - 1 ] == '0' && j != i ) { continue ; }
            if ( f[ j - 1 ] == false ) { continue ; }
            if ( inf / k < dp[ j - 1 ] ) { continue ; }
            unsigned long long aux = dp[ j - 1 ] * k + p ;
            if ( f[ i ] == false ) {
                f[ i ] = true ;
                dp[ i ] = aux ;
            }
            else {
                if ( dp[ i ] > aux ) { dp[ i ] = aux ; }
            }
        }
    }
    cout << dp[ n ] << "\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}