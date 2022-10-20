#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m , k ;
pair < int , int > a[ 2 * MAXN ] ;

void input ( ) {
    scanf ( "%d%*d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%*d%d" , &a[ i ].first ) ;
        if ( a[ i ].first >= ( m / 2 ) ) {
            a[ i ].first -= ( m / 2 ) ;
        }
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = n + 1 ; i <= 2 * n ; ++ i ) {
        a[ i ] = a[ i - n ] ;
        a[ i ].first += ( m / 2 ) ;
    }
}

void solve ( ) {
    int id = 0 ;
    int ans = MAXN ;
    int pos = 0 ;
    for ( int i = n + 1 ; i <= 2 * n ; ++ i ) {
        int sr = a[ i ].first - k ;
        while ( pos < i && a[ pos + 1 ].first <= sr ) {
            ++ pos ;
        }
        int aux = i - pos - 1 ;
        if ( ans > aux ) {
            ans = aux ;
            id = i ;
        }
    }
    printf ( "%d %d\n" , ans , a[ id ].first - ( m / 2 ) ) ;
    int sr = a[ id ].first - k ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( sr < a[ i ].first && a[ i ].first < a[ id ].first ) {
            printf ( "%d " , a[ i ].second ) ;
        }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}