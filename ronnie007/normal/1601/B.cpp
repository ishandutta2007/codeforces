#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int dist[ MAXN ] ;
int prv[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
}

vector < int > v ;

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        dist[ i ] = MAXN ; 
    }
    int mn = n ;
    queue < int > q ;
    q.push ( n ) ;
    dist[ n ] = 0 ;
    prv[ n ] = -1 ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int act = x + b[ x ] ;
        int aux = act - a[ act ] ;
        if ( aux < mn ) {
            for ( int i = aux ; i < mn ; ++ i ) {
                dist[ i ] = dist[ x ] + 1 ;
                prv[ i ] = x ;
                q.push ( i ) ;
            }
            mn = aux ;
        }
    }
    if ( dist[ 0 ] == MAXN ) {
        cout << "-1\n" ;
        return ;
    }
    cout << dist[ 0 ] << "\n" ;
    int x = 0 ;
    while ( x != n ) {
        v.push_back ( x ) ;
        x = prv[ x ] ;
    }
    for ( int i = dist[ 0 ] - 1 ; i >= 0 ; -- i ) {
        cout << v[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}