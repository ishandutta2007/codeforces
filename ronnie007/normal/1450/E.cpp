#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;

int mxval ;
int ans[ MAXN ] ;

int col[ MAXN ] ;
int dist[ MAXN ] ;

bool is_bip ( int vertex , int c ) {
    col[ vertex ] = c ; 
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ vertex ][ i ].first ;
        if ( col[ to ] != 0 && col[ to ] == c ) {
            return false ;
        }
        if ( col[ to ] == 0 ) {
            bool ret = is_bip ( to , 3 - c ) ;
            if ( ret == false ) { return false ; }
        }
    }
    return true ;
}

bool f ( int x ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] = MAXN ; 
    }
    dist[ x ] = 0 ;
    for ( int tm = 1 ; tm <= n + 1 ; ++ tm ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            int sz = v[ i ].size ( ) ;
            for ( int j = 0 ; j < sz ; ++ j ) {
                int to = v[ i ][ j ].first ;
                int cost = v[ i ][ j ].second ;
                if ( dist[ to ] > dist[ i ] + cost ) {
                    if ( tm == n + 1 ) { return false ; } 
                    dist[ to ] = dist[ i ] + cost ; 
                }
            }
        }
    }
    int mn = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mn = min ( mn , dist[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] -= mn ;
    }
    int mx = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx = max ( mx , dist[ i ] ) ;
    }
    if ( mxval < mx ) {
        mxval = mx ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            ans[ i ] = dist[ i ] ;
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( z == 0 ) {
            v[ x ].push_back ( { y , 1 } ) ;
            v[ y ].push_back ( { x , 1 } ) ;
        }
        else {
            v[ x ].push_back ( { y , 1 } ) ;
            v[ y ].push_back ( { x , -1 } ) ;
        }
    }
}

void solve ( ) {
    if ( is_bip ( 1 , 1 ) == false ) {
        printf ( "NO\n" ) ;
        return ;
    }
    mxval = -1 ; 
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( f ( i ) == false ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    if ( mxval == -1 ) {
        printf ( "NO\n" ) ;
        return ;
    }
    printf ( "YES\n" ) ;
    printf ( "%d\n" , mxval ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
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