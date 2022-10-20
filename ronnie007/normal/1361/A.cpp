#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n , m ;
vector < int > v[ MAXN ] ;

pair < int , int > a[ MAXN ] ;
int mx[ MAXN ] ;
bool done[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x = a[ i ].second ;
        int val = a[ i ].first ;
        if ( mx[ x ] != val - 1 ) {
            printf ( "-1\n" ) ;
            return ;
        }
        done[ x ] = true ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int h = v[ x ][ i ] ;
            if ( done[ h ] == true ) { continue ; }
            if ( mx[ h ] < val - 1 ) {
                printf ( "-1\n" ) ;
                return ;
            }
            mx[ h ] = val ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , a[ i ].second ) ;
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