#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
long long b , c ;
vector < long long > v[ 5 ] ;
vector < long long > cand[ 5 ] ;
int sz[ 5 ] ;

int st[ 5 ] ;
int en[ 5 ] ;

long long cost ( long long x , long long y ) {
    long long diff = ( y - x ) ;
    return ( diff / 5 ) * b + ( diff % 5 ) * c ;
}

void input ( ) {
    scanf ( "%d%d%lld%lld" , &n , &k , &b , &c ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long x ;
        scanf ( "%lld" , &x ) ;
        int id = ( x % 5 ) ;
        id = ( id + 5 ) % 5 ;
        v[ id ].push_back ( x ) ;
        for ( int j = 0 ; j < 5 ; ++ j ) {
            cand[ ( id + j ) % 5 ].push_back ( x + j ) ;
        }
    }
    for ( int i = 0 ; i < 5 ; ++ i ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
        sort ( cand[ i ].begin ( ) , cand[ i ].end ( ) ) ;
        sz[ i ] = v[ i ].size ( ) ;
    }
}

void solve ( ) {
    if ( b > 5 * c ) { b = 5 * c ; }
    long long ans = -1 ;
    for ( int i = 0 ; i < 5 ; ++ i ) {
        for ( int j = 0 ; j < 5 ; ++ j ) {
            st[ j ] = 0 ;
            en[ j ] = -1 ;
        }
        int hh = 0 ;
        long long sm = 0 ;
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( j > 0 ) {
                sm += ( ( cand[ i ][ j ] - cand[ i ][ j - 1 ] ) / 5 ) * b * hh ;
            }
            for ( int t = 0 ; t < 5 ; ++ t ) {
                while ( en[ t ] + 1 < sz[ t ] && v[ t ][ en[ t ] + 1 ] <= cand[ i ][ j ] ) {
                    sm += cost ( v[ t ][ ++ en[ t ] ] , cand[ i ][ j ] ) ;
                    ++ hh ;
                }
            }
            while ( hh > k ) {
                long long mx = -1 ;
                int id = -1 ;
                for ( int t = 0 ; t < 5 ; ++ t ) {
                    if ( st[ t ] <= en[ t ] ) {
                        long long aux = cost ( v[ t ][ st[ t ] ] , cand[ i ][ j ] ) ;
                        if ( mx < aux ) {
                            mx = aux ;
                            id = t ;
                        }
                    }
                }
                -- hh ;
                sm -= mx ;
                ++ st[ id ] ;
            }
            if ( hh == k ) {
                if ( ans < 0 || ans > sm ) { ans = sm ; }
            }
        }
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}