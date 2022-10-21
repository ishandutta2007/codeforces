#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 2000007

int n , m , k ;
int a[ MAXN ] ;
int br[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
    int i ;
    int cur = 0 ;
    stack < int > s ;
    int ans = 0 ;
    for ( i = 1 ; i <= 1000000 ; i ++ ) {
        cur += br[ i ] ;
        if ( br[ i ] > 0 ) { s.push ( i ) ; }
        if ( i > m ) { cur -= br[ i - m ] ; }
        if ( cur >= k ) {
            ans ++ ;
            int h = s.top ( ) ;
            s.pop ( ) ;
            br[ h ] -- ;
            cur -- ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}