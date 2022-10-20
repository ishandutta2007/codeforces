#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 2007

int n ;
pair < long long , long long > a[ MAXN ] ;

long long ans = 0 ;
long long c[ MAXN ] ;
long long k[ MAXN ] ;

long long dist[ MAXN ] ;
long long used[ MAXN ] ;

int lst_ver[ MAXN ] ;

vector < int > hubs ;
vector < pair < int , int > > edges ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> c[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> k[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) { dist[ i ] = c[ i ] ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long mn = -1 ;
        int id = -1 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( used[ j ] != 0 ) { continue ; }
            if ( mn == -1 || mn > dist[ j ] ) { mn = dist[ j ] ; id = j ; }
        }
        ans += mn ;
        if ( dist[ id ] == c[ id ] ) {
            hubs.push_back ( id ) ;
        }
        else {
            edges.push_back ( { lst_ver[ id ] , id } ) ;
        }
        used[ id ] = 1 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( used[ j ] != 0 ) { continue ; }
            long long aux = abs ( a[ j ].first - a[ id ].first ) + abs ( a[ j ].second - a[ id ].second ) ;
            aux *= k[ id ] + k[ j ] ;
            if ( aux < dist[ j ] ) {
                dist[ j ] = aux ;
                lst_ver[ j ] = id ;
            }
        }
    }
    cout << ans << "\n" ;
    int sz = hubs.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << hubs[ i ] << " " ;
    }
    cout << "\n" ;
    sz = edges.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << edges[ i ].first << " " << edges[ i ].second << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}