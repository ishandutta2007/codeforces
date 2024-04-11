#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n , m ;

struct edge {
    int x , y ;
    int w , id ;
    edge ( ) { x = y = w = id = 0 ; }
    edge ( int _x , int _y , int _w , int _id ) {
        x = _x , y = _y , w = _w , id = _id ;
    }
};

vector < edge > v ;

pair < int , int > hh[ MAXN ] ;


class uf {
public :
    int prv[ MAXN ] , rnk[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            prv[ i ] = -1 ;
            rnk[ i ] = 0 ;
        }
    }
    int get ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        int y = get ( prv[ x ] ) ;
        prv[ x ] = y ;
        return y ;
    }
    bool unite ( int x , int y ) {
        int k1 = get ( x ) , k2 = get ( y ) ;
        if ( k1 != k2 ) {
            if ( rnk[ k1 ] >= rnk[ k2 ] ) {
                rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
                prv[ k2 ] = k1 ;
            }
            else {
                prv[ k1 ] = k2 ;
            }
            return true ;
        }
        return false ;
    }
};

uf w ;

bool used[ MAXN ] ;
edge b[ MAXN ] ;

bool cmp ( edge p1 , edge p2 ) {
    if ( p1.w != p2.w ) { return ( p1.w < p2.w ) ; }
    return ( p1.id < p2.id ) ;
}

bool check ( int mid , int targ ) {
    w.init ( ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        b[ i ] = v[ i ] ;
        b[ i ].w = abs ( mid - b[ i ].w ) ;
    }
    sort ( b , b + m , cmp ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        if ( b[ i ].id == targ ) {
            return w.unite ( b[ i ].x , b[ i ].y ) ;
        }
        w.unite ( b[ i ].x , b[ i ].y ) ;
    }
}

int get_lst ( edge e ) {
    int l , r , mid ;
    l = 0 , r = e.w ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( check ( mid , e.id ) == false ) { l = mid ; }
        else { r = mid ; }
    }
    while ( l <= e.w && check ( l , e.id ) == false ) { ++ l ; }
    return l ;
}

int get_fst ( edge e ) {
    int l , r , mid ;
    l = e.w , r = 1e8 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( check ( mid , e.id ) == false ) { r = mid ; }
        else { l = mid ; }
    }
    while ( r >= e.w && check ( r , e.id ) == false ) { -- r ; }
    return r ;
}


void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        edge e ;
        cin >> e.x >> e.y >> e.w ;
        e.id = i ;
        v.push_back ( e ) ;
    }
}

struct evt {
    int x ;
    int ch , coef ;
    evt ( ) { x = ch = coef = 0 ; }
    evt ( int _x , int _ch , int _coef ) {
        x = _x , ch = _ch , coef = _coef ;
    }
};

vector < evt > srt ;
bool cmp_evt ( evt p1 , evt p2 ) {
    return p1.x < p2.x ;
}

#define MAXVAL 100000007

bool aux[ MAXVAL ] ;

void solve ( ) {
    for ( int i = 0 ; i < m ; ++ i ) {
        int l = get_lst ( v[ i ] ) ;
        int r = get_fst ( v[ i ] ) ;
        hh[ i ] = { l , r } ;
        if ( l <= v[ i ].w  ) {
            srt.push_back ( evt ( l , v[ i ].w , -1 ) ) ;
            srt.push_back ( evt ( v[ i ].w + 1 , -v[ i ].w , 1 ) ) ;
        }
        if ( v[ i ].w <= r ) {
            srt.push_back ( evt ( v[ i ].w + 1 , -v[ i ].w , 1 ) ) ;
            srt.push_back ( evt ( r + 1 , v[ i ].w , -1 ) ) ;
        }
    }
    long long p , k , a , b , c ;
    cin >> p >> k >> a >> b >> c ;
    long long lst = 0 ;
    for ( int i = 1 ; i <= p ; ++ i ) {
        long long x ;
        cin >> x ;
        lst = x ;

        aux[ x ] ^= 1 ;
    }
    for ( int i = p + 1 ; i <= k ; ++ i ) {
        long long x = ( lst * a + b ) % c ;
        lst = x ;
        
        aux[ x ] ^= 1 ;
    }
    sort ( srt.begin ( ) , srt.end ( ) , cmp_evt ) ;
    long long ans = 0 ;
    int sz = srt.size ( ) ;
    int pos = 0 ;
    long long sm = 0 ;
    long long cnt = 0 ;
    for ( int i = 0 ; i < c ; ++ i ) {
        while ( pos < sz && srt[ pos ].x <= i ) {
            cnt += srt[ pos ].coef ;
            sm += srt[ pos ].ch ;
            ++ pos ;
        }
        if ( aux[ i ] == true ) {
            ans ^= ( sm + cnt * i ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	int t ; t = 1 ;
	while ( t -- ) {
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}