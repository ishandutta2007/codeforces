#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MOD 1000000007

int n , m ;
vector < pair < int , long long > > v[ MAXN ] ;

int used[ MAXN ] ;
long long pref[ MAXN ] ;

long long cnt[ 62 ][ 2 ] ;

long long ans ;

class basis {
public :
    int sz ;
    vector < long long > h ;
    void init ( ) {
        sz = 0 ;
        h.clear ( ) ;
    }
    void add ( long long x ) {
        for ( int i = 0 ; i < sz ; ++ i ) {
            long long bit = ( h[ i ] - ( h[ i ] & ( h[ i ] - 1 ) ) ) ;
            if ( ( x & bit ) > 0 ) {
                x ^= h[ i ] ;
            }
        }
        if ( x == 0 ) { return ; }
        ++ sz ;
        h.push_back ( x ) ;
        long long bit = ( x - ( x & ( x - 1 ) ) ) ;
        for ( int i = 0 ; i < sz - 1 ; ++ i ) {
            if ( ( h[ i ] & bit ) > 0 ) {
                h[ i ] ^= x ; 
            }
        }
    }
    bool present ( long long bit ) {
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( ( h[ i ] & bit ) > 0 ) { return true ; }
        }
        return false ;
    }
};
basis w ;

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    for ( int i = 0 ; i <= 60 ; ++ i ) {
        long long bit = (1LL<<i) ;
        if ( ( pref[ vertex ] & bit ) > 0 ) { ++ cnt[ i ][ 1 ] ; }
        else { ++ cnt[ i ][ 0 ] ; }
    }
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        long long c = v[ vertex ][ i ].second ;
        if ( used[ h ] == 0 ) {
            pref[ h ] = pref[ vertex ] ^ c ;
            dfs ( h ) ;
        }
        else if ( used[ h ] == 1 ) {
            w.add ( pref[ vertex ] ^ pref[ h ] ^ c ) ;
        }
    }
    used[ vertex ] = 2 ;
}

void calc ( int x ) {
    w.init ( ) ;
    for ( int i = 0 ; i <= 60 ; ++ i ) {
        cnt[ i ][ 0 ] = cnt[ i ][ 1 ] = 0 ;
    }
    dfs ( x ) ;
    for ( int i = 0 ; i <= 60 ; ++ i ) {
        long long bit = (1LL<<i) ;
        if ( w.present ( bit ) == false ) {
            bit %= MOD ;
            long long aux = ( cnt[ i ][ 0 ] * cnt[ i ][ 1 ] ) % MOD ;
            aux = ( aux * bit ) % MOD ;
            long long h = (1LL<<w.sz) % MOD ;
            aux = ( aux * h ) % MOD ;
            ans = ans + aux ;
            if ( ans >= MOD ) { ans -= MOD ; }
        }
        else {
            bit %= MOD ;
            long long aux = ( cnt[ i ][ 0 ] + cnt[ i ][ 1 ] ) ;
            aux = ( aux * ( aux - 1 ) / 2 ) % MOD ;
            aux = ( aux * bit ) % MOD ;
            long long h = (1LL<<(w.sz-1)) % MOD ;
            aux = ( aux * h ) % MOD ;
            ans = ans + aux ;
            if ( ans >= MOD ) { ans -= MOD ; }
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        long long val ;
        cin >> x >> y >> val ;
        v[ x ].push_back ( { y , val } ) ;
        v[ y ].push_back ( { x , val } ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            calc ( i ) ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}