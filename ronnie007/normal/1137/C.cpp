#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<string>
using namespace std ;

#define MAXN 100007

int n , m , d ;
vector < int > v[ MAXN ] ;
vector < int > rv[ MAXN ] ;

int used[ MAXN ][ 57 ] ;
int cleared[ MAXN ][ 57 ] ;
int COMP[ MAXN ][ 57 ] ;

vector < int > dag[ 57 * MAXN ] ;
int val[ 57 * MAXN ] ;

string a[ MAXN ] ;

stack < pair < int , int > > st ;
int cnt[ MAXN ] ;
int hh ;

int dp[ 57 * MAXN ] ;

static void dfs_fw ( int x , int y ) {
    used[ x ][ y ] = 1 ;
    int sz = v[ x ].size ( ) ;
    int nwy = y + 1 ;
    if ( nwy > d ) { nwy = 1 ; }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ x ][ i ] ;
        if ( used[ h ][ nwy ] == 0 ) {
            dfs_fw ( h , nwy ) ;
        }
    }
    st.push ( { x , y } ) ;
}

static void dfs_bw ( int x , int y , int id ) {
    if ( a[ x ][ y ] == '1' ) {
        ++ cnt[ x ] ;
        if ( cnt[ x ] == 1 ) { ++ hh ; } 
    }
    COMP[ x ][ y ] = id ;
    int sz = rv[ x ].size ( ) ;
    int nwy = y - 1 ;
    if ( nwy < 1 ) { nwy = d ; }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = rv[ x ][ i ] ;
        if ( COMP[ h ][ nwy ] == 0 ) {
            dfs_bw ( h , nwy , id ) ;
        }
    }
}

static void unmark ( int x , int y ) {
    cleared[ x ][ y ] = 1 ;
    if ( a[ x ][ y ] == '1' ) {
        -- cnt[ x ] ;
    }
    int sz = rv[ x ].size ( ) ;
    int nwy = y - 1 ;
    if ( nwy < 1 ) { nwy = d ; }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = rv[ x ][ i ] ;
        if ( COMP[ h ][ nwy ] == COMP[ x ][ y ] && cleared[ h ][ nwy ] == 0 ) {
            unmark ( h , nwy ) ;
        }
    }
}

static void calc ( int vertex ) {
    dp[ vertex ] = 0 ;
    int sz = dag[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = dag[ vertex ][ i ] ;
        calc ( h ) ;
        if ( dp[ vertex ] < dp[ h ] ) { dp[ vertex ] = dp[ h ] ; }
    }
    dp[ vertex ] += val[ vertex ] ;
}

void input ( ) {
    cin >> n >> m >> d ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        rv[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '#' + a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= d ; ++ j ) {
            if ( used[ i ][ j ] == 0 ) {
                dfs_fw ( i , j ) ;
            }
        }
    }
    int id = 0 ;
    while ( st.empty ( ) == false ) {
        pair < int , int > aux = st.top ( ) ;
        st.pop ( ) ;
        if ( COMP[ aux.first ][ aux.second ] > 0 ) { continue ; }
        dfs_bw ( aux.first , aux.second , ++ id ) ;
        val[ id ] = hh ;
        hh = 0 ;
        unmark ( aux.first , aux.second ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int h = v[ i ][ j ] ;
            for ( int t = 1 ; t <= d ; ++ t ) {
                int nwy = t + 1 ;
                if ( nwy > d ) { nwy = 1 ; } 
                if ( COMP[ i ][ t ] != COMP[ h ][ nwy ] ) {
                    dag[ COMP[ i ][ t ] ].push_back ( COMP[ h ][ nwy ] ) ;
                }
            }
        }
    }
    calc ( COMP[ 1 ][ 1 ] ) ;
    printf ( "%d\n" , dp[ COMP[ 1 ][ 1 ] ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}