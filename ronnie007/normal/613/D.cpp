#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define LOG 20


int n ;
vector < int > gr[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;
int tpsz ;
int st[ MAXN ] , en[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > pts ;

int coef[ MAXN ] ;

void init ( int vertex , int prv ) {
    st[ vertex ] = ++ tpsz ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( auto x : gr[ vertex ] ) {
        if ( x == prv ) { continue ; }
        LCA[ x ][ 0 ] = vertex ;
        lvl[ x ] = lvl[ vertex ] + 1 ;
        init ( x , vertex ) ;
    }
    en[ vertex ] = tpsz ;
}

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - ( 1 << i ) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - ( 1 << i ) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ;
}

bool is_par ( int x , int y ) {
    return ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) ;
}

int ans ;

int dfs ( int vertex , int prv ) {
    int aux = 0 ;
    int cnt = 0 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( LCA[ x ][ 0 ] == vertex && coef[ x ] > 0 && coef[ vertex ] > 0 ) { return -1 ; }
        int ret = dfs ( x , vertex ) ;
        if ( ret == -1 ) { return -1 ; }
        if ( ret > 0 ) {
            ++ cnt ;
        }
    }
    if ( coef[ vertex ] == 0 ) {
        if ( cnt > 1 ) {
            ++ ans ;
            return 0 ;
        }
        else { return cnt ; }
    }
    else {
        ans += cnt ;
        return 1 ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        gr[ x ].push_back ( y ) ;
        gr[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    init ( 1 , -1 ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        pts.resize ( sz ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            scanf ( "%d" , &pts[ i ] ) ;
            coef[ pts[ i ] ] = 1 ;
        }
        auto cmp = [&] ( int x , int y ) {
            return ( st[ x ] < st[ y ] ) ;
        };
        sort ( pts.begin ( ) , pts.end ( ) , cmp ) ;
        bool bad = false ;
        for ( int i = 0 ; i < sz - 1 ; ++ i ) {
            pts.push_back ( get_LCA ( pts[ i ] , pts[ i + 1 ] ) ) ;
        }
        sort ( pts.begin ( ) , pts.end ( ) , cmp ) ;
        stack < int > s ;
        s.push ( pts[ 0 ] ) ;
        sz = pts.size ( ) ;
        for ( int i = 1 ; i < sz ; ++ i ) {
            if ( pts[ i ] == pts[ i - 1 ] ) { continue ; }
            while ( is_par ( s.top ( ) , pts[ i ] ) == false ) {
                s.pop ( ) ;
            }
            v[ s.top ( ) ].push_back ( pts[ i ] ) ;
            v[ pts[ i ] ].push_back ( s.top ( ) ) ;
            s.push ( pts[ i ] ) ;
        }
        ans = 0 ;
        int ret = dfs ( pts[ 0 ] , -1 ) ;
        if ( ret == -1 ) { printf ( "-1\n" ) ; }
        else { printf ( "%d\n" , ans ) ; }
        for ( auto x : pts ) {
            coef[ x ] = 0 ;
            v[ x ].clear ( ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}