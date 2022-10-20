#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;

vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
bool root[ MAXN ] ;
int nxt[ MAXN ] ;

pair < int , int > srt[ MAXN ] ;

long long ans ;
queue < int > q ;

long long f[ MAXN ] ;

void bfs ( int vertex ) {
    q.push ( vertex ) ;
    lvl[ vertex ] = 0 ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            lvl[ v[ x ][ i ] ] = lvl[ x ] + 1 ;
            q.push ( v[ x ][ i ] ) ;
        }
    }
}

vector < int > ret ;
stack < int > aux ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        cin >> x ;
        nxt[ i ] = x ;
        if ( x > -1 ) {
            v[ x ].push_back ( i ) ;
        }
        else { root[ i ] = true ; }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( root[ i ] == true ) { bfs ( i ) ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        srt[ i ] = { lvl[ i ] , i } ;
    }
    sort ( srt + 1 , srt + n + 1 ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ srt[ i ].second ] > 0 ) {
            ans += a[ srt[ i ].second ] ;
            ret.push_back ( srt[ i ].second ) ;
            if ( nxt[ srt[ i ].second ] > 0 ) {
                a[ nxt[ srt[ i ].second ] ] += a[ srt[ i ].second ] ;
            }
        }
        else {
            ans += a[ srt[ i ].second ] ;
            aux.push ( srt[ i ].second ) ;
        }
    }
    while ( aux.empty ( ) == false ) {
        ret.push_back ( aux.top ( ) ) ;
        aux.pop ( ) ;
    }
    cout << ans << "\n" ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cout << ret[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}