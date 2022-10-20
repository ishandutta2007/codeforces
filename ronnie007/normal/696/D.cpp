#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207
#define inf 1e17

int n ;
long long len ;
int a[ MAXN ] ;
string s[ MAXN ] ;

class aho {
public :
    int tpsz = 0 ;
    int f[ MAXN ][ 26 ] ;
    int add[ MAXN ] ;
    int link[ MAXN ] ;
    void init ( ) {
        for ( int i = 0 ; i < MAXN ; ++ i ) {
            for ( int j = 0 ; j < 26 ; ++ j ) {
                f[ i ][ j ] = 0 ;
            }
            link[ i ] = 0 ;
            add[ i ] = 0 ;
        }
        tpsz = 1 ;
    }
    void add_word ( string s , int val ) {
        int sz = s.size ( ) ;
        int aux = 0 ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( f[ aux ][ ( s[ i ] - 'a' ) ] == 0 ) {
                f[ aux ][ ( s[ i ] - 'a' ) ] = tpsz ++ ;
            }
            aux = f[ aux ][ ( s[ i ] - 'a' ) ] ;
        }
        add[ aux ] += val ;
    }
    void upd_links ( ) {
        queue < int > q ;
        q.push ( 0 ) ;
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            for ( int i = 0 ; i < 26 ; ++ i ) {
                if ( f[ x ][ i ] == 0 ) { continue ; }
                int nxt = f[ x ][ i ] ;
                int aux = link[ x ] ;
                while ( aux > 0 && f[ aux ][ i ] == 0 ) {
                    aux = link[ aux ] ;
                }
                if ( f[ aux ][ i ] != 0 && aux != x ) {
                    link[ nxt ] = f[ aux ][ i ] ;
                    add[ nxt ] += add[ f[ aux ][ i ] ] ;
                }
                q.push ( nxt ) ;
            }
        }
    }
    int get ( int st , int let ) {
        while ( st > 0 && f[ st ][ let ] == 0 ) {
            st = link[ st ] ; 
        }
        if ( f[ st ][ let ] > 0 ) {
            st = f[ st ][ let ] ;
        }
        return st ;
    }
};

aho w ;
vector < vector < long long > > v ;

vector < vector < long long > > mul ( vector < vector < long long > > x , vector < vector < long long > > y ) {
    vector < vector < long long > > ret ;
    ret.resize ( w.tpsz ) ;
    for ( int i = 0 ; i < w.tpsz ; ++ i ) {
        ret[ i ].resize ( w.tpsz ) ;
        for ( int j = 0 ; j < w.tpsz ; ++ j ) {
            ret[ i ][ j ] = -inf ;
        }
    }
    for ( int i = 0 ; i < w.tpsz ; ++ i ) {
        for ( int j = 0 ; j < w.tpsz ; ++ j ) {
            for ( int t = 0 ; t < w.tpsz ; ++ t ) {
                ret[ i ][ j ] = max ( ret[ i ][ j ] , x[ i ][ t ] + y[ t ][ j ] ) ;
            }
        }
    }
    return ret ;
}

vector < vector < long long > > fpow ( vector < vector < long long > > x , long long pw ) {
    vector < vector < long long > > ret ;
    ret = x ;
    -- pw ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = mul ( x , x ) ;
            pw /= 2 ;
        }
        else {
            ret = mul ( ret , x ) ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n >> len ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> s[ i ] ;
    }
}

void solve ( ) {
    w.init ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        w.add_word ( s[ i ] , a[ i ] ) ;
    }
    w.upd_links ( ) ;
    v.resize ( w.tpsz ) ;
    for ( int i = 0 ; i < w.tpsz ; ++ i ) {
        v[ i ].resize ( w.tpsz ) ;
        for ( int j = 0 ; j < w.tpsz ; ++ j ) {
            v[ i ][ j ] = -inf ;
        }
    }
    for ( int i = 0 ; i < w.tpsz ; ++ i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            int nxt = w.get ( i , j ) ;
            v[ i ][ nxt ] = max ( v[ i ][ nxt ] , 1LL * w.add[ nxt ] ) ;
        }
    }
    v = fpow ( v , len ) ;
    long long ans = -inf ;
    for ( int i = 0 ; i < w.tpsz ; ++ i ) {
        ans = max ( ans , v[ 0 ][ i ] ) ;
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