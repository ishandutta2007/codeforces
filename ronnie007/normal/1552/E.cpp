#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define MAXN 107

int n , k ;
int a[ MAXN * MAXN ] ;
vector < int > col[ MAXN ] ;

vector < pair < int , int > > aux ;
bool used[ MAXN ] ;
pair < int , int > ans[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n * k ; ++ i ) {
        cin >> a[ i ] ;
        col[ a[ i ] ].push_back ( i ) ;
    }
}

void solve ( ) {
    int lim = ( n + k - 2 ) / ( k - 1 ) ;
    aux.resize ( n ) ;
    auto cmp = [ & ] ( pair < int , int > p1 , pair < int , int > p2 ) {
        return ( p1.second < p2.second ) ;
    };
    for ( int j = 0 ; j < k - 1 ; ++ j ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            aux[ i - 1 ] = { col[ i ][ j ] , col[ i ][ j + 1 ] } ;
        }
        sort ( aux.begin ( ) , aux.end ( ) , cmp ) ;
        int lft = lim ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( lft <= 0 ) { break ; }
            if ( used[ a[ aux[ i ].first ] ] == true ) { continue ; }
            -- lft ;
            used[ a[ aux[ i ].first ] ] = true ;
            ans[ a[ aux[ i ].first ] ] = aux[ i ] ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ].first << " " << ans[ i ].second << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    //  cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}