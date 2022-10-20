#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;
int a[ MAXN ][ MAXN ] ;
bool done[ MAXN ][ MAXN ] ;
int init[ MAXN ][ MAXN ] ;
bool seen[ MAXN ][ MAXN ] ;

struct el {
    int x , y , c ;
    el ( ) { x = y = c = 0 ; }
    el ( int _x , int _y , int _c ) {
        x = _x , y = _y , c = _c ;
    }
};

vector < el > ord ;

set < int > s ;

int f ( int x , int y ) {
    s.clear ( ) ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            if ( done[ x + i ][ y + j ] == false ) { s.insert ( a[ x + i ][ y + j ] ) ; }
        }
    }
    if ( s.size ( ) != 1 ) { return -1 ; }
    return *s.begin ( ) ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
            init[ i ][ j ] = a[ i ][ j ] ;
        }
    }
}
queue < pair < int , int > > q ;

void solve ( ) {
    for ( int i = 1 ; i < n ; ++ i ) {
        for ( int j = 1 ; j < m ; ++ j ) {
            if ( f ( i , j ) > 0 ) {
                q.push ( { i , j } ) ;
                seen[ i ][ j ] = true ;
            }
        }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ).first ;
        int y = q.front ( ).second ;
        q.pop ( ) ;
        if ( f ( x , y ) > 0 ) {
            ord.push_back ( el ( x , y , f ( x , y ) ) ) ;
            for ( int i = 0 ; i < 2 ; ++ i ) {
                for ( int j = 0 ; j < 2 ; ++ j ) {
                    done[ x + i ][ y + j ] = true ;
                }
            }
        }

        for ( int i = -1 ; i <= 1 ; ++ i ) {
            for ( int j = -1 ; j <= 1 ; ++ j ) {
                if ( x + i > 0 && x + i < n ) {
                    if ( y + j > 0 && y + j < m ) {
                        if ( seen[ x + i ][ y + j ] == false ) {
                            if ( f ( x + i , y + j ) > 0 ) {
                                seen[ x + i ][ y + j ] = true ;
                                q.push ( { x + i , y + j } ) ;
                            }
                        }
                    }
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( done[ i ][ j ] == false ) {
                cout << "-1\n" ;
                return ;
            }
        }
    }
    int sz = ord.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        cout << ord[ i ].x << " " << ord[ i ].y << " " << ord[ i ].c << "\n" ;
    }
}

int main ( ) {
    /// freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}