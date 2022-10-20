#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
vector < int > aux[ MAXN ] ;

vector < int > v[ MAXN ] ;
int c[ MAXN ] ;
long long sm ;

void dfs ( int vertex , int type ) {
    if ( type == 1 ) { sm += vertex ; }
    c[ vertex ] = type ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( c[ v[ vertex ][ i ] ] == 0 ) {
            dfs ( v[ vertex ][ i ] , 3 - type ) ;
        }
    }
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( ( n % 2 ) == 0 ) {
        cout << "First\n" ;
        fflush ( stdout ) ;
        for ( int i = 1 ; i <= 2 * n ; ++ i ) {
            if ( i <= n ) {
                cout << i << " " ;
            }
            else {
                cout << i - n << " " ;
            }
        }
        cout << "\n" ;
        fflush ( stdout ) ;
        int foo ; cin >> foo ;
        return ;
    }
    cout << "Second\n" ;
    fflush ( stdout ) ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        int id ;
        cin >> id ;
        aux[ id ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ aux[ i ][ 0 ] ].push_back ( aux[ i ][ 1 ] ) ;
        v[ aux[ i ][ 1 ] ].push_back ( aux[ i ][ 0 ] ) ;
        v[ i ].push_back ( n + i ) ;
        v[ n + i ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( c[ i ] == 0 ) {
            dfs ( i , 1 ) ;
        }
    }
    if ( sm % ( 2 * n ) == 0 ) {
        for ( int i = 1 ; i <= 2 * n ; ++ i ) {
            if ( c[ i ] == 1 ) {
                cout << i << " " ;
            }
        }
        cout << "\n" ;
        fflush ( stdout ) ;
    }
    else {
        for ( int i = 1 ; i <= 2 * n ; ++ i ) {
            if ( c[ i ] == 2 ) {
                cout << i << " " ;
            }
        }
        cout << "\n" ;
        fflush ( stdout ) ;
    }
    int foo ;
    cin >> foo ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}