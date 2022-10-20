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

#define MAXN 200007
#define magic 400

int n ;
string a ;
vector < int > v ;

long long ans ;

int pref[ MAXN ] ;

void f ( int coef ) {
    pref[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] - ( a[ i - 1 ] == '0' ) + ( a[ i - 1 ] == '1' ) * ( coef - 1 ) ) ;
    }
    sort ( pref , pref + n + 1 ) ;
    int aux = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( pref[ i ] == pref[ i - 1 ] ) { ++ aux ; }
        else { aux = 1 ; }
        ans += ( aux - 1 ) ;
    }
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '1' ) { v.push_back ( i ) ; }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= magic ; ++ i ) {
        f ( i ) ;
    }
    v.push_back ( n ) ;
    int sz = v.size ( ) - 1 ;
    for ( int cnt = 1 ; cnt * ( magic + 1 ) <= n ; ++ cnt ) {
        for ( int i = 0 ; i + cnt - 1 < sz ; ++ i ) {
            int en = i + cnt - 1 ;
            int cap = v[ i ] - ( ( i == 0 ) ? 0 : v[ i - 1 ] + 1 ) ;
            for ( int r = v[ en ] ; r < v[ en + 1 ] ; ++ r ) {
                int mn = ( ( r - v[ i ] + cnt ) / cnt ) ;
                mn = max ( mn , magic + 1 ) ;
                int mx = ( ( r - v[ i ] + cap + 1 ) / cnt ) ;
                ans += max ( 0 , mx - mn + 1 ) ;
            }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}