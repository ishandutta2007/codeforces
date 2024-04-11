#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define MOD 1000000007

int vecs , n ;


int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int obt[ MAXN ] ;

int ans ;
vector < int > v ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    prv[ x ] = find ( prv[ x ] ) ;
    return prv[ x ] ;
}

int unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            obt[ k1 ] = ( obt[ k1 ] | obt[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
            obt[ k2 ] = ( obt[ k1 ] | obt[ k2 ] ) ;
        }
        return 1 ;
    }
    else { return 0 ; }
}

void input ( ) {
    scanf ( "%d%d" , &vecs , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        obt[ i ] = 0 ;
    }
}

void solve ( ) {
    v.clear ( ) ;
    for ( int i = 1 ; i <= vecs ; ++ i ) {
        int k , x , y ;
        scanf ( "%d" , &k ) ;
        if ( k == 1 ) {
            scanf ( "%d" , &x ) ;
            int root = find ( x ) ;
            if ( obt[ root ] == 0 ) {
                v.push_back ( i ) ;
                obt[ root ] = 1 ;
            }
        }
        else {
            scanf ( "%d%d" , &x , &y ) ;
            int root1 = find ( x ) ;
            int root2 = find ( y ) ;
            if ( obt[ root1 ] == 1 && obt[ root2 ] == 1 ) {
                continue ;
            }
            if ( unite ( x , y ) == 1 ) {
                v.push_back ( i ) ;
            }
        }
    }
    ans = 1 ;
    int sz = v.size ( ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        ans = ( ans * 2 ) ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    printf ( "%d %d\n" , ans , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d " , v[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}