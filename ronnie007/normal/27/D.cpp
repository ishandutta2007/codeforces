#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207

int n , m ;
pair < int , int > a[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > rev[ MAXN ] ;

stack < int > s ;
int used[ MAXN ] ;
int comp[ MAXN ] ;


void dfs_fw ( int vertex ) {
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs_fw ( v[ vertex ][ i ] ) ;
        }
    }
    s.push ( vertex ) ;
}

void dfs_bw ( int vertex , int id ) {
    comp[ vertex ] = id ;
    int sz = rev[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( comp[ rev[ vertex ][ i ] ] == 0 ) {
            dfs_bw ( rev[ vertex ][ i ] , id ) ;
        }
    }
}

void scc ( ) {
    for ( int i = 1 ; i <= 2 * m ; ++ i ) {
        if ( used[ i ] == 0 ) {
            dfs_fw ( i ) ;
        }
    }
    int id = 0 ; 
    while ( s.empty ( ) == false ) {
        int x = s.top ( ) ;
        s.pop ( ) ;
        if ( comp[ x ] > 0 ) { continue ; }
        dfs_bw ( x , ++ id ) ;
    }
}

bool f ( int x , int y ) {
    if ( a[ x ].first <= a[ y ].first && a[ y ].second <= a[ x ].second ) { return false ; }
    if ( a[ y ].first <= a[ x ].first && a[ x ].second <= a[ y ].second ) { return false ; }
    if ( a[ x ].second <= a[ y ].first ) { return false ; }
    if ( a[ y ].second <= a[ x ].first ) { return false ; }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        if ( a[ i ].first > a[ i ].second ) { swap ( a[ i ].first , a[ i ].second ) ; }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        for ( int j = i + 1 ; j <= m ; ++ j ) {
            if ( f ( i , j ) == true ) {
                v[ i ].push_back ( m + j ) ;
                v[ m + i ].push_back ( j ) ;
                v[ j ].push_back ( m + i ) ;
                v[ m + j ].push_back ( i ) ;

                rev[ m + j ].push_back ( i ) ;
                rev[ j ].push_back ( m + i ) ;
                rev[ m + i ].push_back ( j ) ;
                rev[ i ].push_back ( m + j ) ;
            }
        }
    }
    scc ( ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( comp[ i ] == comp[ i + m ] ) {
            printf ( "Impossible\n" ) ;
            return ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( comp[ i ] < comp[ i + m ] ) { printf ( "i" ) ; }
        else { printf ( "o" ) ; }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}