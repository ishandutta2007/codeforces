#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAXLEN 252

int n , q ;
string a ;

int fst[ MAXN ][ 26 ] ;

string w[ 3 ] ;
int sz[ 3 ] ;

int dp[ MAXLEN ][ MAXLEN ][ MAXLEN ] ;

void expand ( int i , int j , int t ) {
    int st = dp[ i ][ j ][ t ] ;
    if ( i < sz[ 0 ] && fst[ st + 1 ][ ( w[ 0 ][ i ] - 'a' ) ] < MAXN ) {
        dp[ i + 1 ][ j ][ t ] = min ( dp[ i + 1 ][ j ][ t ] , fst[ st + 1 ][ ( w[ 0 ][ i ] - 'a' ) ] ) ;
    }
    if ( j < sz[ 1 ] && fst[ st + 1 ][ ( w[ 1 ][ j ] - 'a' ) ] < MAXN ) {
        dp[ i ][ j + 1 ][ t ] = min ( dp[ i ][ j + 1 ][ t ] , fst[ st + 1 ][ ( w[ 1 ][ j ] - 'a' ) ] ) ;
    }
    if ( t < sz[ 2 ] && fst[ st + 1 ][ ( w[ 2 ][ t ] - 'a' ) ] < MAXN ) {
        dp[ i ][ j ][ t + 1 ] = min ( dp[ i ][ j ][ t + 1 ] , fst[ st + 1 ][ ( w[ 2 ][ t ] - 'a' ) ] ) ;
    }
}

void recalc ( int id ) {
    int pos = sz[ id ] ;
    if ( id == 0 ) {
        for ( int i = pos - 1 ; i <= pos ; ++ i ) {
            for ( int j = 0 ; j <= sz[ 1 ] ; ++ j ) {
                for ( int t = 0 ; t <= sz[ 2 ] ; ++ t ) {
                    if ( dp[ i ][ j ][ t ] == MAXN ) { continue ; }
                    expand ( i , j , t ) ;
                }
            }
        }
    }
    else if ( id == 1 ) {
        for ( int i = 0 ; i <= sz[ 0 ] ; ++ i ) {
            for ( int j = pos - 1 ; j <= pos ; ++ j ) {
                for ( int t = 0 ; t <= sz[ 2 ] ; ++ t ) {
                    if ( dp[ i ][ j ][ t ] == MAXN ) { continue ; }
                    expand ( i , j , t ) ;
                }
            }
        }
    }
    else {
        for ( int i = 0 ; i <= sz[ 0 ] ; ++ i ) {
            for ( int j = 0 ; j <= sz[ 1 ] ; ++ j ) {
                for ( int t = pos - 1 ; t <= pos ; ++ t ) {
                    if ( dp[ i ][ j ][ t ] == MAXN ) { continue ; }
                    expand ( i , j , t ) ;
                }
            }
        }
    }
}

void rem ( int id ) {
    int pos = sz[ id ] ;
    if ( id == 0 ) {
        for ( int i = 0 ; i <= sz[ 1 ] ; ++ i ) {
            for ( int j = 0 ; j <= sz[ 2 ] ; ++ j ) {
                dp[ pos + 1 ][ i ][ j ] = MAXN ;
            }
        }
    }
    else if ( id == 1 ) {
        for ( int i = 0 ; i <= sz[ 0 ] ; ++ i ) {
            for ( int j = 0 ; j <= sz[ 2 ] ; ++ j ) {
                dp[ i ][ pos + 1 ][ j ] = MAXN ;
            }
        }
    }
    else {
        for ( int i = 0 ; i <= sz[ 0 ] ; ++ i ) {
            for ( int j = 0 ; j <= sz[ 1 ] ; ++ j ) {
                dp[ i ][ j ][ pos + 1 ] = MAXN ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
    int lst[ 26 ] ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        lst[ i ] = MAXN ;
    }
    for ( int i = 0 ; i < 26 ; ++ i ) {
        fst[ n + 1 ][ i ] = MAXN ;
    }
    for ( int i = n ; i >= 0 ; -- i ) {
        if ( i > 0 ) {
            lst[ ( a[ i - 1 ] - 'a' ) ] = i ;
        }
        for ( int j = 0 ; j < 26 ; ++ j ) {
            fst[ i ][ j ] = lst[ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= 250 ; ++ i ) {
        for ( int j = 0 ; j <= 250 ; ++ j ) {
            for ( int t = 0 ; t <= 250 ; ++ t ) {
                dp[ i ][ j ][ t ] = MAXN ;
            }
        }
    }
    dp[ 0 ][ 0 ][ 0 ] = 0 ;
    while ( q -- ) {
        char type , c ;
        int id ;
        cin >> type ;
        if ( type == '+' ) {
            cin >> id >> c ;
            -- id ;
            ++ sz[ id ] ;
            w[ id ] += c ;
            recalc ( id ) ;
        }
        else {
            cin >> id ;
            -- id ;
            -- sz[ id ] ;
            w[ id ].pop_back ( ) ;
            rem ( id ) ;
        }
        if ( dp[ sz[ 0 ] ][ sz[ 1 ] ][ sz[ 2 ] ] < MAXN ) {
            cout << "YES\n" ;
        }
        else {
            cout << "NO\n" ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}