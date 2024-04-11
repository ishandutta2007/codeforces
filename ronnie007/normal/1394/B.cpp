#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m , k ;
struct edge {
    int st , en ;
    int val ;
};
edge w[ MAXN ] ;

int tot[ MAXN ] ;
int sz[ MAXN ] ;

bool can[ MAXN ][ 10 ][ 10 ] ;
bool bad[ 10 ][ 10 ][ 10 ][ 10 ] ;

int ans ;


vector < pair < int , int > > hh ;

bool cmp ( edge p1 , edge p2 ) {
    return ( p1.val < p2.val ) ;
}

pair < int , int > pr[ 17 ] ;

void rec ( int len ) {
    if ( len == k ) {
        ++ ans ;
        return ;
    }
    for ( int i = 1 ; i <= len + 1 ; ++ i ) {
        bool fl = false ;
        if ( bad[ i ][ len + 1 ][ i ][ len + 1 ] == true ) {
            fl = true ;
        }
        for ( int j = 1 ; j <= len ; ++ j ) {
            if ( fl == true ) { break ; }
            if ( bad[ pr[ j ].first ][ pr[ j ].second ][ i ][ len + 1 ] == true ) {
                fl = true ;
                break ;
            }
        }
        if ( fl == false ) {
            pr[ len + 1 ] = { i , len + 1 } ;
            rec ( len + 1 ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d%d" , &w[ i ].st , &w[ i ].en , &w[ i ].val ) ;
        ++ tot[ w[ i ].st ] ;
    }
    sort ( w + 1 , w + m + 1 , cmp ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        ++ sz[ w[ i ].st ] ;
        if ( can[ w[ i ].en ][ sz[ w[ i ].st ] ][ tot[ w[ i ].st ] ] == true ) {
            bad[ sz[ w[ i ].st ] ][ tot[ w[ i ].st ] ][ sz[ w[ i ].st ] ][ tot[ w[ i ].st ] ] = true ;
        }
        can[ w[ i ].en ][ sz[ w[ i ].st ] ][ tot[ w[ i ].st ] ] = true ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        hh.clear ( ) ;
        int len = 0 ;
        for ( int j = 1 ; j <= k ; ++ j ) {
            for ( int t = j ; t <= k ; ++ t ) {
                if ( can[ i ][ j ][ t ] == true ) {
                    hh.push_back ( { j , t } ) ;
                }
            }
        }
        len = hh.size ( ) ;
        for ( int j = 0 ; j < len ; ++ j ) {
            for ( int t = j + 1 ; t < len ; ++ t ) {
                bad[ hh[ j ].first ][ hh[ j ].second ][ hh[ t ].first ][ hh[ t ].second ] = true ;
                bad[ hh[ t ].first ][ hh[ t ].second ][ hh[ j ].first ][ hh[ j ].second ] = true ;
            }
        }
    }

    rec ( 0 ) ;
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}