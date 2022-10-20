#include<bits/stdc++.h>
using namespace std ;

#define MAXN 600007

int n , k ;
string s ;
vector < int > v[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int sz[ MAXN ] ;
bool fl[ MAXN ] ;
bool used[ MAXN ] ;

int ans ; 

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( used[ k1 ] == true ) {
        used[ k1 ] = false ;
        ans -= sz[ k1 ] ;
    }
    if ( used[ k2 ] == true ) {
        used[ k2 ] = false ;
        ans -= sz[ k2 ] ;
    }
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            sz[ k1 ] += sz[ k2 ] ;
            prv[ k2 ] = k1 ;
            fl[ k1 ] &= fl[ k2 ] ;
        }
        else {
            sz[ k2 ] += sz[ k1 ] ;
            prv[ k1 ] = k2 ;
            fl[ k2 ] &= fl[ k1 ] ;
        }
    }
}

void input ( ) {
    cin >> n >> k ;
    cin >> s ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int len ;
        cin >> len ;
        for ( int j = 0 ; j < len ; ++ j ) {
            int x ;
            cin >> x ;
            v[ x ].push_back ( i ) ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= k ; ++ i ) {
        prv[ i ] = prv[ i + k ] = -1 ;
        sz[ i ] = 1 ;
        fl[ i ] = fl[ i + k ] = true ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int len = v[ i ].size ( ) ;
        if ( len == 1 ) {
            int k1 = find ( v[ i ][ 0 ] ) ;
            int k2 = find ( v[ i ][ 0 ] + k ) ;
            if ( s[ i - 1 ] == '0' ) {
                fl[ k2 ] = false ;
                if ( used[ k2 ] == true ) {
                    ans -= sz[ k2 ] ;
                    used[ k2 ] = false ;
                }
                if ( used[ k1 ] == false ) {
                    ans += sz[ k1 ] ;
                    used[ k1 ] = true ;
                }
            }
            else {
                fl[ k1 ] = false ;
                if ( used[ k1 ] == true ) {
                    ans -= sz[ k1 ] ;
                    used[ k1 ] = false ;
                }
                if ( used[ k2 ] == false ) {
                    ans += sz[ k2 ] ;
                    used[ k2 ] = true ;
                }
            }
        }
        else if ( len == 2 ) {
            if ( s[ i - 1 ] == '1' ) { 
                unite ( v[ i ][ 0 ] , v[ i ][ 1 ] ) ;
                unite ( v[ i ][ 0 ] + k , v[ i ][ 1 ] + k ) ;
            }
            else {
                unite ( v[ i ][ 0 ] , v[ i ][ 1 ] + k ) ;
                unite ( v[ i ][ 0 ] + k , v[ i ][ 1 ] ) ;
            }
            int k1 = find ( v[ i ][ 0 ] ) ;
            int k2 = find ( v[ i ][ 0 ] + k ) ;
            if ( fl[ k1 ] == false ) {
                ans += sz[ k2 ] ;
                used[ k2 ] = true ;
            }
            else if ( fl[ k2 ] == false ) {
                ans += sz[ k1 ] ;
                used[ k1 ] = true ;
            }
            else {
                if ( sz[ k1 ] < sz[ k2 ] ) {
                    ans += sz[ k1 ] ;
                    used[ k1 ] = true ;
                }
                else {
                    ans += sz[ k2 ] ;
                    used[ k2 ] = true ;
                }
            }
        }
        printf ( "%d\n" , ans ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}