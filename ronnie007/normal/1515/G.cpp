#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < pair < int , int > > v[ MAXN ] ;
vector < pair < int , int > > rv[ MAXN ] ;

bool used[ MAXN ] ;
stack < int > s ;
int comp[ MAXN ] ;

long long st[ MAXN ] , en[ MAXN ] ;

long long sr[ MAXN ] ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto [ nxt , c ] : v[ vertex ] ) {
        if ( used[ nxt ] == false ) {
            dfs ( nxt ) ;
        }
    }
    s.push ( vertex ) ;
}

void rev_dfs ( int vertex , int id ) {
    comp[ vertex ] = id ;
    for ( auto [ nxt , c ] : rv[ vertex ] ) {
        if ( comp[ nxt ] == 0 ) {
            rev_dfs ( nxt , id ) ;
        }
    }
}

void fill_fw ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto [ nxt , c ] : v[ vertex ] ) {
        if ( used[ nxt ] == false && comp[ nxt ] == comp[ vertex ] ) {
            st[ nxt ] = st[ vertex ] + c ;
            fill_fw ( nxt ) ;
        }
    }
}

void fill_bw ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto [ nxt , c ] : rv[ vertex ] ) {
        if ( used[ nxt ] == false && comp[ nxt ] == comp[ vertex ] ) {
            en[ nxt ] = en[ vertex ] + c ;
            fill_bw ( nxt ) ;
        }
    }
}

void input ( ) {
    int m ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( { y , z } ) ;
        rv[ y ].push_back ( { x , z } ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs ( i ) ;
        }
    }
    int mxid = 0 ;
    while ( s.empty ( ) == false ) {
        int x = s.top ( ) ;
        s.pop ( ) ;
        if ( comp[ x ] != 0 ) { continue ; }
        rev_dfs ( x , ++ mxid ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            fill_fw ( i ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            fill_bw ( i ) ;
        }
    }
    auto gcd__ = [ & ] ( long long x , long long y ) {
        if ( x < y ) { swap ( x , y ) ; }
        while ( y != 0 ) {
            x %= y ;
            swap ( x , y ) ;
        }
        return x ;
    };
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto [ nxt , c ] : v[ i ] ) {
            if ( comp[ i ] == comp[ nxt ] ) {
                long long hh = st[ i ] + c + en[ nxt ] ;
                sr[ comp[ i ] ] = gcd__ ( sr[ comp[ i ] ] , hh ) ;
            }
        }
    }
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int vertex , init , mod ;
        scanf ( "%d%d%d" , &vertex , &init , &mod ) ;
        long long aux = gcd__ ( sr[ comp[ vertex ] ] , mod ) ;
        if ( ( mod - init ) % aux != 0 ) { printf ( "NO\n" ) ; }
        else { printf ( "YES\n" ) ; }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}