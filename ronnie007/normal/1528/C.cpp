#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
vector < int > v[ MAXN ][ 2 ] ;

int st[ MAXN ] , en[ MAXN ] ;
int rv[ MAXN ] ;


class hset {
public :
    set < int > s ;
    stack < pair < int , int > > hist ;

    void init ( ) {
        s.clear ( ) ;
        while ( hist.empty ( ) == false ) { hist.pop ( ) ; }
    }
    void add ( int x ) {
        set < int > :: iterator cand2 = s.lower_bound ( st[ x ] ) ;
        set < int > :: iterator cand1 = cand2 ;
        int addval = st[ x ] , remval = -1 ;
        
        if ( cand1 != s.begin ( ) ) {
            -- cand1 ;
            int wh = rv[ *cand1 ] ;
            if ( st[ x ] <= en[ wh ] ) {
                addval = st[ x ] ;
                remval = st[ wh ] ;
            }
        }
        if ( cand2 != s.end ( ) ) {
            int wh = rv[ *cand2 ] ;
            if ( st[ wh ] <= en[ x ] ) {
                addval = -1 ;
                remval = -1 ;
            }
        }
        if ( addval > 0 ) { s.insert ( addval ) ; }
        s.erase ( remval ) ;
        hist.push ( { addval , remval } ) ;
    }
    void undo ( ) {
        auto [ add , rem ] = hist.top ( ) ;
        hist.pop ( ) ;
        if ( rem > 0 ) {
            s.insert ( rem ) ;
        }
        s.erase ( add ) ;
    }
    
};

hset w ;

int tpsz = 0 ;
void init ( int vertex ) {
    st[ vertex ] = ++ tpsz ;
    rv[ tpsz ] = vertex ; 
    for ( auto x : v[ vertex ][ 1 ] ) {
        init ( x ) ;
    }
    en[ vertex ] = tpsz ; 
}
int ans = 0 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ][ 0 ].clear ( ) ; v[ i ][ 1 ].clear ( ) ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ; scanf ( "%d" , &x ) ;
        v[ x ][ 0 ].push_back ( i ) ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ; scanf ( "%d" , &x ) ;
        v[ x ][ 1 ].push_back ( i ) ;
    }
}

void dfs ( int vertex ) {
    w.add ( vertex ) ;
    ans = max ( ans , (int)w.s.size ( ) ) ;
    for ( auto x : v[ vertex ][ 0 ] ) {
        dfs ( x ) ;
    }
    w.undo ( ) ;
}

void solve ( ) {
    tpsz = 0 ;
    init ( 1 ) ;
    w.init ( ) ;

    ans = 0 ;
    dfs ( 1 ) ;
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    // cin >> t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}