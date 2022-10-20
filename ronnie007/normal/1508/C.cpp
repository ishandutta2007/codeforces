#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;

map < pair < int , int > , int > w ;


int xorsm ;

struct edge {
    int x , y ;
    int cost ;
    edge ( ) { x = y = cost = 0 ; }
    edge ( int _x , int _y , int _cost ) {
        x = _x ; y = _y ;
        cost = _cost ;
    }
};

vector < edge > srt ;

long long ans = 0 ;
int tree_edges = 0 ;

vector < int > cont[ MAXN ] ;

int min_unused = -1 ;

class uf {
public :
    int prv[ MAXN ] ;
    int rnk[ MAXN ] ;
    void init ( int sz ) {
        for ( int i = 0 ; i <= sz ; ++ i ) {
            prv[ i ] = -1 ;
            rnk[ i ] = 0 ;
            cont[ i ].clear ( ) ;
            cont[ i ].push_back ( i ) ;
        }
    }
    int get ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        int y = get ( prv[ x ] ) ;
        prv[ x ] = y ;
        return y ;
    }
    void unite ( int x , int y , int cost , bool fl ) {
        int k1 = get ( x ) ;
        int k2 = get ( y ) ;
        if ( k1 != k2 ) {
            ans += cost ;
            if ( rnk[ k1 ] >= rnk[ k2 ] ) {
                prv[ k2 ] = k1 ;
                rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            }
            else {
                prv[ k1 ] = k2 ;
            }
        }
        else {
            if ( min_unused == -1 && fl == true ) { min_unused = cost ; }
        }
    }
    void setup ( int x , int y ) {
        int k1 = get ( x ) ;
        int k2 = get ( y ) ;
        if ( k1 == k2 ) { return ; }
        ++ tree_edges ;
        if ( (int)cont[ k1 ].size ( ) < (int)cont[ k2 ].size ( ) ) {
            swap ( k1 , k2 ) ;
        }
        for ( auto nw : cont[ k2 ] ) {
            prv[ nw ] = k1 ;
            cont[ k1 ].push_back ( nw ) ;
        }
    }
};

uf prv , act ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        cin >> x >> y >> z ;
        xorsm ^= z ;
        if ( x > y ) { swap ( x , y ) ; }

        ++ w[ { x , y } ] ;

        srt.push_back ( edge ( x , y , z ) ) ;
    }
    auto cmp = [ & ] ( edge p1 , edge p2 ) {
        return ( p1.cost < p2.cost ) ;
    };
    sort ( srt.begin ( ) , srt.end ( ) , cmp ) ;
}

void solve ( ) {
    act.init ( n ) ;
    prv.init ( n ) ;
    set < int > cand ;
    cand.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cand.insert ( i ) ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        vector < int > to_rem ;
        to_rem.clear ( ) ;
        for ( auto hh : cand ) {
            if ( hh >= i ) { break ; }
            if ( prv.get ( i ) == hh ) { continue ; }

            bool fl = false ;
            for ( auto con : cont[ hh ] ) {
                if ( w[ { con , i } ] == 0 ) {
                    fl = true ;
                    break ;
                }
            }
            if ( fl == true ) {
                prv.setup ( hh , i ) ;
                if ( prv.get ( i ) == hh ) {
                    to_rem.push_back ( i ) ;
                }
                else {
                    to_rem.push_back ( hh ) ;
                }
            }
        }
        for ( auto hh : to_rem ) {
            cand.erase ( hh ) ;
        }
    }
    for ( int i = 0 ; i < m ; ++ i ) {
        int comp1 = prv.get ( srt[ i ].x ) ;
        int comp2 = prv.get ( srt[ i ].y ) ;
        bool fl = false ;
        if ( (int)cont[ comp1 ].size ( ) > 1 || (int)cont[ comp2 ].size ( ) > 1 ) { fl = true ; }
        act.unite ( comp1 , comp2 , srt[ i ].cost , fl ) ;
    }

    long long tot_edges = 1LL * n * ( n - 1 ) / 2 ;
    if ( tot_edges - m == tree_edges ) {
        if ( min_unused > -1 && min_unused < xorsm ) {
            ans += min_unused ;
        }
        else { 
            ans += xorsm ;
        }
    }
    
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}