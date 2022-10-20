#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , x , y ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;
int emp ;

vector < int > v[ MAXN ] ;
int pos[ MAXN ] ;

priority_queue < pair < int , int > > q ;
vector < int > hh ;

int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &x , &y ) ;
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        cnt[ i ] = 0 ;
        v[ i ].clear ( ) ;
        pos[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ cnt[ a[ i ] ] ;
        v[ a[ i ] ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        if ( cnt[ i ] == 0 ) {
            emp = i ;
            break ;
        }
    }
    while ( q.empty ( ) == false ) {
        q.pop ( ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        ans[ i ] = emp ;
        if ( cnt[ i ] > 0 ) {
            q.push ( { cnt[ i ] , i } ) ;
        }
    }
    int lft = x ;
    while ( lft -- ) {
        pair < int , int > aux = q.top ( ) ;
        q.pop ( ) ;
        ans[ v[ aux.second ][ pos[ aux.second ] ] ] = aux.second ;
        ++ pos[ aux.second ] ;
        -- aux.first ;
        if ( aux.first > 0 ) { q.push ( aux ) ; }
    }
    if ( y > x ) {
        hh.clear ( ) ;
        int mxperiod = ( q.top ( ) ).first ;
        for ( int i = 1 ; i <= n + 1 ; ++ i ) {
            int sz = v[ i ].size ( ) ;
            while ( pos[ i ] < sz ) {
                hh.push_back ( v[ i ][ pos[ i ] ] ) ;
                ++ pos[ i ] ;
            }
        }
        int sz = hh.size ( ) ;
        lft = ( y - x ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( lft == 0 ) { break ; }
            int nxt = ( i + mxperiod ) % sz ;
            if ( a[ hh[ i ] ] == a[ hh[ nxt ] ] ) {
                continue ;
            }
            -- lft ;
            ans[ hh[ nxt ] ] = a[ hh[ i ] ] ;
        }
        if ( lft > 0 ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    printf ( "YES\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
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