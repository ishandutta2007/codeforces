#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000001

int n ;
long long k ;

long long pref[ MAXN ] ;
int nxt[ MAXN ][ 62 ] ;
int lst[ 62 ] ;

int l[ MAXN ] ;
int r[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    pref[ 1 ] = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int prv ;
        long long x ;
        cin >> prv >> x ;
        pref[ i ] = pref[ prv ] ^ x ;
    }
    for ( int i = 0 ; i < 62 ; ++ i ) {
        lst[ i ] = n + 1 ; 
    }
    sort ( pref + 1 , pref + n + 1 ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j < 62 ; ++ j ) {
            long long bit = (1LL<<j) ;
            if ( (pref[ i ] & bit ) > 0 ) {
                lst[ j ] = i ;
            }
            nxt[ i ][ j ] = lst[ j ] ;
        }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        l[ i ] = 1 ;
        r[ i ] = n ;
    }
    for ( int i = 61 ; i >= 0 ; -- i ) {
        long long cnt = 0 ;
        long long bit = (1LL<<i) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( l[ j ] <= r[ j ] ) {
                int mid = nxt[ l[ j ] ][ i ] ;
                if ( mid > r[ j ] + 1 ) { mid = r[ j ] + 1 ; }
                if ( ( pref[ j ] & bit ) == 0 ) {
                    cnt += max ( 0 , mid - l[ j ] ) ;
                }
                else {
                    cnt += max ( 0 , r[ j ] - mid + 1 ) ;
                }
            }
        }
        if ( k <= cnt ) {
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( l[ j ] <= r[ j ] ) {
                    int mid = nxt[ l[ j ] ][ i ] ;
                    if ( mid > r[ j ] + 1 ) { mid = r[ j ] + 1 ; }
                    if ( ( pref[ j ] & bit ) == 0 ) {
                        r[ j ] = mid - 1 ;
                    }
                    else {
                        l[ j ] = mid ; 
                    }
                }
            }
        }
        else {
            ans += bit ;
            k -= cnt ;
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( l[ j ] <= r[ j ] ) {
                    int mid = nxt[ l[ j ] ][ i ] ;
                    if ( mid > r[ j ] + 1 ) { mid = r[ j ] + 1 ; }
                    if ( ( pref[ j ] & bit ) != 0 ) {
                        r[ j ] = mid - 1 ;
                    }
                    else {
                        l[ j ] = mid ; 
                    }
                }
            }            
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}