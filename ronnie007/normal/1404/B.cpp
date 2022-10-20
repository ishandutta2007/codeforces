#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , sta , stb , lena , lenb ;
vector < int > v[ MAXN ] ;

int f[ MAXN ] ;

queue < int > q ;

void bfs ( int vertex ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ] = MAXN ;
    }
    f[ vertex ] = 0 ;
    q.push ( vertex ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( f[ v[ x ][ i ] ] == MAXN ) {
                f[ v[ x ][ i ] ] = f[ x ] + 1 ;
                q.push ( v[ x ][ i ] ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> sta >> stb >> lena >> lenb ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    if ( lenb <= 2 * lena ) {
        cout << "Alice\n" ;
        return ;
    }
    bfs ( sta ) ;
    if ( f[ stb ] <= lena ) {
        cout << "Alice\n" ;
        return ;
    }
    int mx , id ;
    mx = id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < f[ i ] ) {
            mx = f[ i ] ;
            id = i ;
        }
    }
    bfs ( id ) ;
    int diam = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( diam < f[ i ] ) {
            diam = f[ i ] ;
        }
    }
    if ( diam <= 2 * lena ) {
        cout << "Alice\n" ;
        return ;
    }
    cout << "Bob\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}