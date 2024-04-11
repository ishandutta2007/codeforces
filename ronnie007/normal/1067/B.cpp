#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
vector < int > v[ MAXN ] ;

int init[ MAXN ] ;
int deg[ MAXN ] ;
int nxt[ MAXN ] ;
int lvl[ MAXN ] ;

queue < int > q ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        ++ deg[ x ] ; ++ deg[ y ] ; 
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        init[ i ] = deg[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( deg[ i ] == 1 ) {
            q.push ( i ) ;
            lvl[ i ] = 1 ;
        }
    }
    int mx = 0 ;
    int cnt = 0 ;
    int root ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        ++ cnt ;
        if ( deg[ x ] != 1 && cnt != n ) {
            printf ( "No\n" ) ;
            return ;
        }
        if ( cnt == n ) { root = x ; }
        mx = max ( mx , lvl[ x ] ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int to = v[ x ][ i ] ;
            if ( lvl[ to ] == 0 ) {
                lvl[ to ] = lvl[ x ] + 1 ;
                q.push ( to ) ;
            }
            else if ( x != nxt[ to ] && lvl[ to ] != lvl[ x ] + 1 ) {
                printf ( "No\n" ) ;
                return ;
            }
            if ( lvl[ to ] > lvl[ x ] ) {
                nxt[ x ] = to ;
            }
            -- deg[ to ] ;
        }
    }
    if ( mx != k + 1 ) {
        printf ( "No\n" ) ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == root && init[ i ] >= 3 ) { continue ; }
        if ( lvl[ i ] > 1 && init[ i ] < 4 ) {
            printf ( "No\n" ) ;
            return ;
        }
    }
    printf ( "Yes\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}