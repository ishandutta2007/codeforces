#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;
int tot ;
int pref[ MAXN ] ;
int suff[ MAXN ] ;

pair < int , int > aux[ MAXN ] ;

vector < int > v[ MAXN ] ;
bool used[ MAXN ] ;

priority_queue < int > q ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    tot = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        tot += ( a[ i ] == 0 ) ;
    }
    pref[ 0 ] = suff[ n + 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + ( a[ i ] == 0 ) ) ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        suff[ i ] = ( suff[ i + 1 ] + ( a[ i ] == 0 ) ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) { aux[ i ] = { 0 , 0 } ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == 0 ) { continue ; }
        if ( 2 * suff[ i ] >= tot ) {
            aux[ a[ i ] ].first = i ;
        }
        else { break ; }
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] == 0 ) { continue ; }
        if ( 2 * pref[ i ] >= tot ) {
            aux[ a[ i ] ].second = n - i + 1 ;
        }
        else { break ; }
    }
    for ( int i = 0 ; i <= n ; ++ i ) { v[ i ].clear ( ) ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
        if ( aux[ i ].first != 0 || aux[ i ].second != 0 ) {
            v[ aux[ i ].first ].push_back ( aux[ i ].second ) ;
        }
    }
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    int ans = 0 ;
    for ( int st = n ; st >= 0 ; -- st ) {
        int sz = v[ st ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            q.push ( - v[ st ][ j ] ) ;
        }
        if ( st > 0 && a[ st ] == 0 ) {
            if ( q.empty ( ) == false ) {
                q.pop ( ) ;
                used[ st ] = true ;
                ++ ans ;
            }
        }
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] == 0 && used[ i ] == false ) {
            while ( q.empty ( ) == false ) {
                int sr = - q.top ( ) ;
                q.pop ( ) ;
                if ( sr >= n - i + 1 ) {
                    ++ ans ;
                    break ;
                }
            }
        }
    }
    ans = min ( ans , tot / 2 ) ;
    printf ( "%d\n" , ans ) ;
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