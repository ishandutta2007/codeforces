#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;

struct tr {
    int x , y , z ;
};
tr a[ MAXN ] ;

int cnt[ MAXN ] ;
int nxt[ MAXN ] ;
int prv[ MAXN ] ;

vector < int > v[ MAXN ] ;
bool used[ MAXN ] ;

stack < pair < int , int > > st ;

int get_id ( int vert ) {
    int sz = v[ vert ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ v[ vert ][ i ] ] == false ) {
            return v[ vert ][ i ] ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n - 2 ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].z ) ;
        ++ cnt[ a[ i ].x ] , ++ cnt[ a[ i ].y ] , ++ cnt[ a[ i ].z ] ;
        v[ a[ i ].x ].push_back ( i ) ;
        v[ a[ i ].y ].push_back ( i ) ;
        v[ a[ i ].z ].push_back ( i ) ;
    }
}

void solve ( ) {
    while ( st.empty ( ) == false ) { st.pop ( ) ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] == 1 ) {
            st.push ( { i , v[ i ][ 0 ] } ) ;
        }
    }
    bool fst = true ;
    vector < int > ord ;
    vector < int > hh ;
    hh.clear ( ) ;
    ord.clear ( ) ;
    int tot = 0 ;
    while ( st.empty ( ) == false && tot < n - 2 ) {
        ++ tot ;
        pair < int , int > aux = st.top ( ) ;
        st.pop ( ) ;
        int id = aux.second ;
        used[ id ] = true ;
        ord.push_back ( id ) ;
        hh.push_back ( aux.first ) ;
            
        -- cnt[ a[ id ].x ] ;
        -- cnt[ a[ id ].y ] ;
        -- cnt[ a[ id ].z ] ;
        if ( cnt[ a[ id ].x ] == 1 ) {
            st.push ( { a[ id ].x , get_id ( a[ id ].x ) } ) ;
        }
        if ( cnt[ a[ id ].y ] == 1 ) {
            st.push ( { a[ id ].y , get_id ( a[ id ].y ) } ) ;
        }
        if ( cnt[ a[ id ].z ] == 1 ) {
            st.push ( { a[ id ].z , get_id ( a[ id ].z ) } ) ;
        }            
    }
    nxt[ a[ ord[ n - 3 ] ].x ] = a[ ord[ n - 3 ] ].y ;
    nxt[ a[ ord[ n - 3 ] ].y ] = a[ ord[ n - 3 ] ].z ;
    nxt[ a[ ord[ n - 3 ] ].z ] = a[ ord[ n - 3 ] ].x ;

    prv[ a[ ord[ n - 3 ] ].x ] = a[ ord[ n - 3 ] ].z ;
    prv[ a[ ord[ n - 3 ] ].z ] = a[ ord[ n - 3 ] ].y ;
    prv[ a[ ord[ n - 3 ] ].y ] = a[ ord[ n - 3 ] ].x ;

    for ( int i = n - 4 ; i >= 0 ; -- i ) {
        int id = ord[ i ] ;
        if ( a[ id ].y != hh[ i ] ) {
            if ( a[ id ].x == hh[ i ] ) {
                swap ( a[ id ].x , a[ id ].y ) ;
            }
            else {
                swap ( a[ id ].z , a[ id ].y ) ;
            }
        }
        if ( nxt[ a[ id ].x ] == a[ id ].z ) {
            nxt[ a[ id ].x ] = a[ id ].y ;
            nxt[ a[ id ].y ] = a[ id ].z ;
            prv[ a[ id ].z ] = a[ id ].y ;
            prv[ a[ id ].y ] = a[ id ].x ;
        }
        else {
            prv[ a[ id ].x ] = a[ id ].y ;
            prv[ a[ id ].y ] = a[ id ].z ;
            nxt[ a[ id ].z ] = a[ id ].y ;
            nxt[ a[ id ].y ] = a[ id ].x ;            
        }
    }
    int x = 1 ;
    printf ( "%d" , x ) ;
    x = nxt[ x ] ;
    while ( x != 1 ) {
        printf ( " %d" , x ) ;
        x = nxt[ x ] ;
    }
    printf ( "\n" ) ;
    for ( int i = 0 ; i < ord.size ( ) ; ++ i ) {
        printf ( "%d " , ord[ i ] ) ;
    }
    printf ( "\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
        v[ i ].clear ( ) ;
        prv[ i ] = nxt[ i ] = 0 ;
        used[ i ] = false ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}