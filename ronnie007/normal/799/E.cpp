#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2000007
#define inf 1000000007

int n , m , k ;
pair < int , int > a[ MAXN ] ;

int pos[ 4 ] ;

vector < int > v[ 4 ] ;

long long sm = 0 ;

pair < int , int > f ( ) {
    int cand = inf ;
    int id = 4 ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        if ( pos[ i ] < v[ i ].size ( ) ) {
            if ( cand > v[ i ][ pos[ i ] ] ) {
                cand = v[ i ][ pos[ i ] ] ;
                id = i ;
            }
        }
    }
    return { cand , id } ;
}

void input ( ) {
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first ;
    }
    int sz ;
    cin >> sz ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        int x ;
        cin >> x ;
        a[ x ].second = 1 ;
    }
    cin >> sz ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        int x ;
        cin >> x ;
        a[ x ].second += 2 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ a[ i ].second ].push_back ( a[ i ].first ) ;
    }
    for ( int i = 0 ; i < 4 ; ++ i ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
    }
}

void solve ( ) {
    long long ans = -1 ;
    pos[ 3 ] = -1 ;
    for ( int i = 0 ; i <= v[ 3 ].size ( ) ; ++ i ) {
        if ( i + min ( k , int ( v[ 1 ].size ( ) ) ) < k ) { continue ; }
        if ( i + min ( k , int ( v[ 2 ].size ( ) ) ) < k ) { continue ; }
        if ( i + ( k - i ) + ( k - i ) > m ) { continue ; }
        if ( v[ 0 ].size ( ) + v[ 1 ].size ( ) + v[ 2 ].size ( ) < m - i ) { continue ; }
        pos[ 3 ] = i ;
        break ;
    }
    if ( pos[ 3 ] == -1 ) {
        cout << "-1\n" ;
        return ;
    }
    pos[ 1 ] = pos[ 2 ] = max ( 0 , k - pos[ 3 ] ) ;
    for ( int i = 1 ; i < 4 ; ++ i ) {
        for ( int j = 0 ; j < pos[ i ] ; ++ j ) {
            sm += v[ i ][ j ] ;
        }
    }
    int lft = m - pos[ 3 ] - pos[ 2 ] - pos[ 1 ] ;
    while ( lft -- ) {
        pair < int , int > ret = f ( ) ;
        sm += ret.first ;
        ++ pos[ ret.second ] ;
    }
    ans = sm ;
    int lim = min ( m , int ( v[ 3 ].size ( ) ) ) ;
    for ( int i = pos[ 3 ] + 1 ; i <= lim ; ++ i ) {
        sm += v[ 3 ][ pos[ 3 ] ] ;
        ++ pos[ 3 ] ;
        if ( pos[ 1 ] > 0 ) {
            sm -= v[ 1 ][ -- pos[ 1 ] ] ;
        }
        if ( pos[ 2 ] > 0 ) {
            sm -= v[ 2 ][ -- pos[ 2 ] ] ;
        }
        for ( int aux = 0 ; aux < 2 ; ++ aux ) {
            if ( pos[ 0 ] > 0 ) {
                sm -= v[ 0 ][ -- pos[ 0 ] ] ;
            }
        }
        int lft = m - pos[ 3 ] - pos[ 2 ] - pos[ 1 ] - pos[ 0 ] ;
        while ( lft -- ) {
            pair < int , int > ret = f ( ) ;
            sm += ret.first ;
            ++ pos[ ret.second ] ;
        }
        ans = min ( ans , sm ) ;
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