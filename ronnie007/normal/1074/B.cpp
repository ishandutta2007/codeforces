#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
vector < int > v[ MAXN ] ;

bool fl1[ MAXN ] ;
bool fl2[ MAXN ] ;

int dfs ( int vertex , int prv ) {
    if ( fl1[ vertex ] == true ) {
        printf ( "A %d\n" , vertex ) ;
        fflush ( stdout ) ;
        int ret ;
        scanf ( "%d" , &ret ) ;
        if ( fl2[ ret ] == true ) { return vertex ; }
        return -1 ;
    }
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        int ret = dfs ( v[ vertex ][ i ] , vertex ) ;
        if ( ret != 0 ) { return ret ; }
    }
    return 0 ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        fl1[ i ] = fl2[ i ] = false ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    int sz ;
    scanf ( "%d" , &sz ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        fl1[ x ] = true ;
    }
    scanf ( "%d" , &sz ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        fl2[ x ] = true ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl2[ i ] == true ) {
            printf ( "B %d\n" , i ) ;
            fflush ( stdout ) ;
            int id ;
            scanf ( "%d" , &id ) ;
            int ret = dfs ( id , -1 ) ;
            printf ( "C %d\n" , ret ) ;
            fflush ( stdout ) ;
            return ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}