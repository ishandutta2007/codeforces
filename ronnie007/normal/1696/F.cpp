#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 102 ;

int n ;
bool f[ MAXN ][ MAXN ][ MAXN ] ;
int prv[ MAXN * MAXN ] , rnk[ MAXN * MAXN ] ;
vector < pair < int , int > > aux[ MAXN * MAXN ] ;
vector < int > v[ MAXN ] ;
int dist[ MAXN ][ MAXN ] ;

int encode ( int x , int y ) {
    return ( x - 1 ) * n + y ;
}

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

queue < int > q ;

void bfs ( int ori ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ ori ][ i ] = MAXN ;
    }
    dist[ ori ][ ori ] = 0 ;
    q.push ( ori ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ; q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            if ( dist[ ori ][ y ] == MAXN ) {
                dist[ ori ][ y ] = dist[ ori ][ x ] + 1 ;
                q.push ( y ) ;
            }
        }
    }
}

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            string s ;
            cin >> s ;
            for ( int t = 0 ; t < n ; ++ t ) {
                if ( s[ t ] == '0' ) { f[ i ][ j ][ t + 1 ] = false ; }
                else { f[ i ][ j ][ t + 1 ] = true ; }
            }
        }
    }
    for ( int i = 1 ; i <= n * n ; ++ i ) {
        prv[ i ] = -1 , rnk[ i ] = 0 ;
        aux[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            unite ( encode ( i , j ) , encode ( j , i ) ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            for ( int t = 1 ; t <= n ; ++ t ) {
                if ( f[ i ][ j ][ t ] == true ) {
                    unite ( encode ( i , t ) , encode ( j , t ) ) ;
                    unite ( encode ( t , i ) , encode ( t , j ) ) ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            aux[ get ( encode ( i , j ) ) ].push_back ( { i , j } ) ;
        }
    }
    for ( int ori = 1 ; ori <= n * n ; ++ ori ) {
        if ( (int)aux[ ori ].size ( ) == n - 1 ) {
            for ( int i = 1 ; i <= n ; ++ i ) {
                v[ i ].clear ( ) ;
            }
            for ( auto [ x , y ] : aux[ ori ] ) {
                v[ x ].push_back ( y ) ;
                v[ y ].push_back ( x ) ;
            }
            for ( int i = 1 ; i <= n ; ++ i ) {
                bfs ( i ) ;
            }
            bool fl = true ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                for ( int j = i + 1 ; j <= n ; ++ j ) {
                    for ( int t = 1 ; t <= n ; ++ t ) {
                        if ( f[ i ][ j ][ t ] == true && dist[ i ][ t ] != dist[ j ][ t ] ) {
                            fl = false ; break ;
                        }
                        if ( f[ i ][ j ][ t ] == false && dist[ i ][ t ] == dist[ j ][ t ] ) {
                            fl = false ; break ;
                        }
                        if ( dist[ i ][ t ] == MAXN || dist[ j ][ t ] == MAXN ) {
                            fl = false ; break ;
                        }
                    }
                    if ( fl == false ) { break ; }
                }
                if ( fl == false ) { break ; }
            }
            if ( fl == true ) {
                cout << "Yes\n" ;
                for ( auto [ x , y ] : aux[ ori ] ) {
                    cout << x << " " << y << "\n" ;
                }
                return ;
            }
        }
    }
    cout << "No\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}