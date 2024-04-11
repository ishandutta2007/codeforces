#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAGIC 2000

int n , q ;
int a[ MAXN ] ;
int ans[ MAXN ] ;
bool fl[ MAXN ] ;


struct query {
    int l , r , k ;
    int prv ;
    int id ;
    query ( ) { l = r = k = prv = id = 0 ; }
    query ( int _l , int _r , int _k , int _prv , int _id ) {
        l = _l , r = _r , k = _k , prv = _prv , id = _id ;
    }
};

struct update {
    int wh ;
    int prv , nxt ;
    update ( ) { wh = prv = nxt = 0 ; }
    update ( int _wh , int _prv , int _nxt ) {
        wh = _wh , prv = _prv , nxt = _nxt ;
    }
};

vector < query > v ;
vector < update > aux ;

int cnt[ MAXN ] ;
int hh[ MAXN ] ;
pair < int , int > range[ MAXN ] ;

int curl , curr ;

void add_val ( int x ) {
    ++ hh[ range[ cnt[ x ] ].first ] ;
    if ( range[ cnt[ x ] + 1 ].first == MAXN ) {
        range[ cnt[ x ] + 1 ] = { range[ cnt[ x ] ].first , range[ cnt[ x ] ].first } ;
    }
    else {
        ++ range[ cnt[ x ] + 1 ].second ;
    }
    ++ range[ cnt[ x ] ].first ;
    if ( range[ cnt[ x ] ].second < range[ cnt[ x ] ].first ) {
        range[ cnt[ x ] ] = { MAXN , MAXN } ;
    }
    ++ cnt[ x ] ;
}

void rem_val ( int x ) {
    -- hh[ range[ cnt[ x ] ].second ] ;
    if ( range[ cnt[ x ] - 1 ].first == MAXN ) {
        range[ cnt[ x ] - 1 ] = { range[ cnt[ x ] ].second , range[ cnt[ x ] ].second } ;
    }
    else {
        -- range[ cnt[ x ] - 1 ].first ;
    }
    -- range[ cnt[ x ] ].second ;
    if ( range[ cnt[ x ] ].second < range[ cnt[ x ] ].first ) {
        range[ cnt[ x ] ] = { MAXN , MAXN } ;
    }
    -- cnt[ x ] ;
}

void add_update ( int pos ) {
    if ( curl <= aux[ pos ].wh && aux[ pos ].wh <= curr ) {
        rem_val ( aux[ pos ].prv ) ;
        add_val ( aux[ pos ].nxt ) ;
    }
    a[ aux[ pos ].wh ] = aux[ pos ].nxt ;
}

void rem_update ( int pos ) {
    if ( curl <= aux[ pos ].wh && aux[ pos ].wh <= curr ) {
        rem_val ( aux[ pos ].nxt ) ;
        add_val ( aux[ pos ].prv ) ;
    }
    a[ aux[ pos ].wh ] = aux[ pos ].prv ;
}


bool cmp ( query p1 , query p2 ) {
    if ( p1.prv / MAGIC != p2.prv / MAGIC ) {
        return ( p1.prv / MAGIC < p2.prv / MAGIC ) ;
    }
    if ( p1.l / MAGIC != p2.l / MAGIC ) {
        return ( p1.l / MAGIC < p2.l / MAGIC ) ;
    }
    return ( p1.r > p2.r ) ;
}

int b[ MAXN ] ;

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        b[ i ] = a[ i ] ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        int type ;
        cin >> type ;
        if ( type == 1 ) {
            int l , r , k ;
            cin >> l >> r >> k ;
            fl[ i ] = true ;
            v.push_back ( query ( l , r , k , aux.size ( ) , i ) ) ;
        }
        else {
            int p , x ;
            cin >> p >> x ;
            aux.push_back ( update ( p , b[ p ] , x ) ) ;
            b[ p ] = x ;
        }
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        cnt[ i ] = 0 ;
        hh[ i ] = 0 ;
        range[ i ] = { MAXN , MAXN } ;
    }
    range[ 0 ] = { 1 , n } ;
    curl = 1 , curr = 0 ;
    int curpos = 0 ;
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        while ( curpos < v[ i ].prv ) {
            add_update ( curpos ++ ) ;
        }
        while ( curpos > v[ i ].prv ) {
            rem_update ( -- curpos ) ;
        }

        while ( curl > v[ i ].l ) {
            add_val ( a[ -- curl ] ) ;
        }
        while ( curr < v[ i ].r ) {
            add_val ( a[ ++ curr ] ) ;
        }
        
        while ( curl < v[ i ].l ) {
            rem_val ( a[ curl ++ ] ) ;
        }
        while ( curr > v[ i ].r ) {
            rem_val ( a[ curr -- ] ) ;
        }

        ans[ v[ i ].id ] = MAXN ;
        int en = 0 ;
        int tot = 0 ;
        for ( int st = 1 ; st <= n ; st = range[ hh[ st ] ].second + 1 ) {
            while ( en + 1 <= n && hh[ en + 1 ] > 0 && tot < v[ i ].k ) {
                tot += ( range[ hh[ en + 1 ] ].second - range[ hh[ en + 1 ] ].first + 1 ) ;
                en = range[ hh[ en + 1 ] ].second ;
            }
            if ( tot >= v[ i ].k ) {
                ans[ v[ i ].id ] = min ( ans[ v[ i ].id ] , hh[ st ] - hh[ en ] ) ;
            }
            tot -= ( range[ hh[ st ] ].second - range[ hh[ st ] ].first + 1 ) ;
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( fl[ i ] == true ) {
            if ( ans[ i ] == MAXN ) { ans[ i ] = -1 ; }
            cout << ans[ i ] << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}