#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;

int subtree[ MAXN ] ;
long long sm[ MAXN ][ 2 ] ;
int cnt[ MAXN ][ 2 ] ;


long long ans = 0 ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    cnt[ vertex ][ 0 ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( h == prv ) { continue ; }
        dfs ( h , vertex ) ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                ans += cnt[ vertex ][ j ] * sm[ h ][ t ] ;
                ans += cnt[ h ][ t ] * sm[ vertex ][ j ] ;
                long long diff = ( j + t + 2 ) / 2 ;
                ans += diff * cnt[ vertex ][ j ] * cnt[ h ][ t ] ;
            }
        }
        
        subtree[ vertex ] += subtree[ h ] ;
        cnt[ vertex ][ 0 ] += cnt[ h ][ 1 ] ;
        cnt[ vertex ][ 1 ] += cnt[ h ][ 0 ] ;

        sm[ vertex ][ 0 ] += sm[ h ][ 1 ] + cnt[ h ][ 1 ] ;
        sm[ vertex ][ 1 ] += sm[ h ][ 0 ] ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}