#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;

class uf {
public :
    int prv[ MAXN ] , rnk[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            prv[ i ] = -1 , rnk[ i ] = 0 ;
        }
    }
    int get ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        int y = get ( prv[ x ] ) ;
        prv[ x ] = y ;
        return y ;
    }
    void unite ( int x , int y ) {
        int k1 = get ( x ) ;
        int k2 = get ( y ) ;
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
};
uf w ;

int perm[ MAXN ] ;
vector < int > v[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
        v[ a[ i ] ].push_back ( i ) ;
    }
}

void solve ( ) {
    int tot = 0 , lst ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] % 2 == 1 ) {
            ++ tot ;
            lst = i ;
        }
    }
    if ( tot > 1 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( tot == 1 && cnt[ a[ ( n / 2 ) + 1 ] ] == 1 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( n % 2 == 1 ) {
        for ( int i = 0 ; i < cnt[ lst ] ; ++ i ) {
            if ( v[ lst ][ i ] != ( n / 2 ) + 1 ) {
                perm[ ( n / 2 ) + 1 ] = v[ lst ][ i ] ;
                if ( i < cnt[ lst ] - 1 ) {
                    swap ( v[ lst ][ i ] , v[ lst ][ cnt[ lst ] - 1 ] ) ;
                }
                v[ lst ].pop_back ( ) ;
                -- cnt[ lst ] ;
                break ;
            }
        }
    }
    int tp = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < cnt[ i ] ; j += 2 ) {
            perm[ tp ] = v[ i ][ j ] ;
            perm[ n - tp + 1 ] = v[ i ][ j + 1 ] ;
            ++ tp ;
        }
    }
    w.init ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        w.unite ( i , perm[ i ] ) ;
    }

    for ( int i = 1 ; i <= n / 2 ; ++ i ) {
        if ( w.get ( i ) != w.get ( n - i + 1 ) ) {
            swap ( perm[ i ] , perm[ n - i + 1 ] ) ;
            w.unite ( i , n - i + 1 ) ;
        }
    }
    for ( int i = 2 ; i <= n / 2 ; ++ i ) {
        if ( w.get ( i ) != w.get ( 1 ) ) {
            swap ( perm[ 1 ] , perm[ i ] ) ;
            swap ( perm[ n ] , perm[ n - i + 1 ] ) ;
            swap ( perm[ i ] , perm[ n - i + 1 ] ) ;
            w.unite ( 1 , i ) ;
        }
    }
    
    cout << "YES\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << perm[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}