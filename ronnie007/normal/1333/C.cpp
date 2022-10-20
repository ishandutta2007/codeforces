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

#define MAXN 300007

int n ;
int a[ MAXN ] ;

map < long long , int > w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    int lst = -1 ;
    long long sm = 0 ;
    w[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sm += a[ i ] ;
        if ( w.find ( sm ) != w.end ( ) ) {
            lst = max ( lst , w[ sm ] ) ;
        }
        w[ sm ] = i ;
        ans += ( i - lst - 1 ) ;
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