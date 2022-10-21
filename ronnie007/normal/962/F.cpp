#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;

int lvl[ MAXN ] ;
bool used[ MAXN ] ;
int id[ MAXN ] ;
int vert[ MAXN ] ;

class DSU {
public :
    int prv[ MAXN ] ;
    int cnt[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= m ; ++ i ) {
            prv[ i ] = -1 ;
            cnt[ i ] = 0 ;
        }
    }
    int find ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        prv[ x ] = find ( prv[ x ] ) ;
        return prv[ x ] ;
    }
    void UNITE ( int x , int y ) {
        int k1 = find ( x ) ;
        int k2 = find ( y ) ;
        if ( k1 != k2 ) {
            if ( lvl[ k1 ] <= lvl[ k2 ] ) {
                prv[ k2 ] = k1 ;
                cnt[ k1 ] += cnt[ k2 ] ;
            }
            else {
                prv[ k1 ] = k2 ;
                cnt[ k2 ] += cnt[ k1 ] ;
            }
        }
    }
};

DSU w ;


void dfs ( int vertex , int lst_ver ) {
    used[ vertex ] = true ;
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == lst_ver ) { continue ; } 
        if ( used[ x ] == false ) {
            id[ x ] = y ;
            lvl[ y ] = lvl[ id[ vertex ] ] + 1 ;
            vert[ y ] = vertex ;
            dfs ( x , vertex ) ;
        }
        else if ( lvl[ id[ vertex ] ] > lvl[ id[ x ] ] ) {
            int dummy = id[ vertex ] ;
            ++ w.cnt[ y ] ;
            lvl[ y ] = MAXN ; 
            while ( lvl[ dummy ] > lvl[ id[ x ] ] ) {
                w.UNITE ( y , dummy ) ;
                dummy = id[ vert[ w.find ( dummy ) ] ] ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
}

void solve ( ) {
    w.init ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs ( i , -1 ) ;
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        ans += ( w.cnt[ w.find ( i ) ] == 1 ) ;
    }
    printf ( "%d\n" , ans ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( w.cnt[ w.find ( i ) ] == 1 ) {
            printf ( "%d " , i ) ;
        }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}