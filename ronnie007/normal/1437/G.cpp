#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , q ;
string a[ MAXN ] ;
int d[ MAXN ] ;
pair < string , int > b[ MAXN ] ;
int comp[ MAXN ] ;
map < int , int > hh[ MAXN ] ;

class aho {
public :
    struct node {
        int to[ 26 ] ;
        int fail ;
        int val ;
        int jump ;
        node ( ) {
            for ( int i = 0 ; i < 26 ; ++ i ) {
                to[ i ] = -1 ;
            }
            fail = 0 ;
            val = -1 ;
            jump = 0 ;
        }
    };
    int where[ MAXN ] ;
    vector < node > v ;
    void init ( ) {
        v.push_back ( node ( ) ) ;
    }
    void add_word ( string &s , int id ) {
        int aux = 0 ;
        int sz = s.size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int nxt = ( s[ i ] - 'a' ) ;
            if ( v[ aux ].to[ nxt ] == -1 ) {
                v.push_back ( node ( ) ) ;
                v[ aux ].to[ nxt ] = v.size ( ) - 1 ;
            }
            aux = v[ aux ].to[ nxt ] ;
        }
        v[ aux ].val = 0 ;
        where[ id ] = aux ;
    }
    void calc_links ( ) {
        queue < int > q ;
        for ( int i = 0 ; i < 26 ; ++ i ) {
            if ( v[ 0 ].to[ i ] > -1 ) {
                q.push ( v[ 0 ].to[ i ] ) ;
                if ( v[ v[ 0 ].to[ i ] ].val == 0 ) {
                    v[ v[ 0 ].to[ i ] ].jump = v[ 0 ].to[ i ] ;
                }
            }
        }
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            for ( int i = 0 ; i < 26 ; ++ i ) {
                if ( v[ x ].to[ i ] > -1 ) {
                    int aux = v[ x ].fail ;
                    while ( aux > 0 && v[ aux ].to[ i ] == -1 ) {
                        aux = v[ aux ].fail ;
                    }
                    if ( v[ aux ].to[ i ] > -1 ) {
                        aux = v[ aux ].to[ i ] ;
                    }
                    v[ v[ x ].to[ i ] ].fail = aux ;
                    if ( v[ v[ x ].to[ i ] ].val == 0 ) {
                        v[ v[ x ].to[ i ] ].jump = v[ x ].to[ i ] ;
                    }
                    else {
                        v[ v[ x ].to[ i ] ].jump = v[ aux ].jump ;
                    }
                    q.push ( v[ x ].to[ i ] ) ;
                }
            }
        }
    }
    void advance ( int &pos , int nxt ) {
        while ( pos > 0 && v[ pos ].to[ nxt ] == -1 ) {
            pos = v[ pos ].fail ;
        }
        if ( v[ pos ].to[ nxt ] != -1 ) {
            pos = v[ pos ].to[ nxt ] ;
        }
    }
    int get_val ( int pos ) {
        int ret = -1 ;
        while ( pos > 0 ) {
            pos = v[ pos ].jump ;
            ret = max ( ret , v[ pos ].val ) ;
            pos = v[ pos ].fail ;
        }
        return ret ;
    }
};
aho w ;

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        b[ i ] = { a[ i ] , i } ;
    }
    sort ( b + 1 , b + n + 1 ) ;
    comp[ b[ 1 ].second ] = b[ 1 ].second ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( b[ i ].first == b[ i - 1 ].first ) {
            comp[ b[ i ].second ] = comp[ b[ i - 1 ].second ] ;
        }
        else {
            comp[ b[ i ].second ] = b[ i ].second ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ hh[ comp[ i ] ][ 0 ] ;
    }
}

void solve ( ) {
    w.init ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( comp[ i ] == i ) {
            w.add_word ( a[ i ] , i ) ;
        }
    }
    w.calc_links ( ) ;
    int type ;
    while ( q -- ) {
        cin >> type ;
        if ( type == 1 ) {
            int id , x ;
            cin >> id >> x ;
            int ori = comp[ id ] ;
            if ( hh[ ori ][ d[ id ] ] == 1 ) {
                hh[ ori ].erase ( d[ id ] ) ;
            }
            else { -- hh[ ori ][ d[ id ] ] ; }
            d[ id ] = x ;
            ++ hh[ ori ][ d[ id ] ] ;
            w.v[ w.where[ ori ] ].val = hh[ ori ].rbegin()->first ;
        }
        else {
            string s ;
            cin >> s ;
            int sz = s.size ( ) ;
            int ret = -1 ;
            int pos = 0 ;
            for ( int i = 0 ; i < sz ; ++ i ) {
                w.advance ( pos , ( s[ i ] - 'a' ) ) ;
                ret = max ( ret , w.get_val ( pos ) ) ;
            }
            cout << ret << "\n" ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}