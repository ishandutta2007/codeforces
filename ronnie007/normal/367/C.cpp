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

#define MAXN 100007

int n , m ;
pair < int , int > a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].second , &a[ i ].first ) ;
    }
    sort ( a + 1 , a + m + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        long long aux = ( ( 1LL * i * ( i - 1 ) ) >> 1 ) ;
        ++ aux ;
        if ( ( i & 1 ) == 0 ) { aux += ( ( i - 2 ) >> 1 ) ; }
        if ( aux <= n ) { ans += a[ m - i + 1 ].first ; }
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