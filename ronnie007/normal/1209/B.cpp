#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 107

int n ;
int init[ MAXN ] ;
int sm ;
int a[ MAXN ] ;
int b[ MAXN ] ;


void input ( ) {
    cin >> n ;
    string s ;
    cin >> s ;
    for ( int i = 0 ; i < n ; ++ i ) {
        init[ i + 1 ] = ( s[ i ] - '0' ) ;
        sm += init[ i + 1 ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] >> b[ i ] ;
    }
}

void solve ( ) {
    int ans = sm ;
    for ( int i = 0 ; i <= 50000 ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( b[ j ] <= i && ( ( i - b[ j ] ) % a[ j ] ) == 0 ) {
                sm -= init[ j ] ;
                init[ j ] ^= 1 ;
                sm += init[ j ] ;
            }
        }
        if ( ans < sm ) { ans = sm ; }
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