#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;


int n , m ;

unsigned long long a[ 100007 ] ;
unsigned long long b[ 100007 ] ;

unsigned long long pr1[ 100007 ] ;
unsigned long long pr2[ 100007 ] ;

void input ( ) ;
void solve ( ) ;



int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n >> m ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        cin >> b[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    sort ( b + 1 , b + m + 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        pr1[ i ] = pr1[ i - 1 ] + a[ i ] ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        pr2[ i ] = pr2[ i - 1 ] + b[ i ] ;
    }
}


void solve ( )  {
    int i ;
    unsigned long long best = -1 ;
    unsigned long long cur ;
    /// A
    for ( i = 1 ; i <= n ; i ++ ) {
        cur = i * pr2[ m ] ;
        cur += pr1[ ( n - i ) ] ;
        if ( best < 0 || best > cur ) best = cur ;
    }
    /// B
    for ( i = 1 ; i <= m ; i ++ ) {
        cur = i * pr1[ n ] ;
        cur += pr2[ ( m - i ) ] ;
        if ( best < 0 || best > cur ) best = cur ;
    }
    cout << best << "\n" ;
}