#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n ;
string a , b ;

long long br[ 7 ] ;

void input ( ) {
    cin >> n ;
    cin >> a >> b ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        int h1 , h2 ;
        h1 = ( a[ i ] - '0' ) ;
        h2 = ( b[ i ] - '0' ) ;
        br[ 2 * h2 + h1 ] ++ ;
    }
    long long ans = 0 ;
    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( j = i ; j < 4 ; j ++ ) {
            int w1 , w2 ;
            int p1 , p2 ;
            w1 = ( i % 2 ) ;
            w2 = ( j % 2 ) ;
            p1 = ( i / 2 ) ;
            p2 = ( j / 2 ) ;
            int val1 = 2 * ( w1 | p1 ) + ( w2 | p2 ) ;
            int val2 = 2 * ( w2 | p1 ) + ( w1 | p2 ) ;
            if ( val1 != val2 ) {
                if ( i != j ) { ans += ( br[ i ] * br[ j ] ) ; }
                else { ans += ( br[ i ] * ( br[ i ] - 1 ) / 2 ) ; }
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}