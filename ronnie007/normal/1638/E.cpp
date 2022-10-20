#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1100007

int n , q ;

struct op {
    string type ;
    int x , y , z ;
};

op hist[ MAXN ] ;

long long ans[ MAXN ] ;

struct sweep {
    int pos , type ;
    int id ;
    sweep ( ) { pos = type = id = 0 ; }
    sweep ( int _pos , int _type , int _id ) {
        pos = _pos , type = _type , id = _id ;
    }
};

vector < int > qlist[ MAXN ] ;
vector < sweep > v ;
set < int > act ;

vector < pair < int , long long > > all_events[ MAXN ] ;

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        all_events[ i ].push_back ( { 0 , 0 } ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        cin >> hist[ i ].type ;
        if ( hist[ i ].type == "Color" ) {
            cin >> hist[ i ].x >> hist[ i ].y >> hist[ i ].z ;
            v.push_back ( sweep ( hist[ i ].x , 1 , i ) ) ;
            v.push_back ( sweep ( hist[ i ].y + 1 , -1 , i ) ) ;
        }
        if ( hist[ i ].type == "Add" ) {
            cin >> hist[ i ].x >> hist[ i ].y ;
            long long sm = all_events[ hist[ i ].x ].back ( ).second ;
            all_events[ hist[ i ].x ].push_back ( { i , sm + hist[ i ].y } ) ;
        }
        if ( hist[ i ].type == "Query" ) {
            cin >> hist[ i ].x ;
            qlist[ hist[ i ].x ].push_back ( i ) ;
        }
    }
    auto cmp = [ & ] ( sweep p1 , sweep p2 ) {
        return ( p1.pos < p2.pos ) ;
    };
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

long long get_up_to ( int wh , int sr ) {
    int l , r , mid ;
    l = 0 , r = all_events[ wh ].size ( ) - 1 ;
    if ( all_events[ wh ][ r ].first < sr ) {
        return all_events[ wh ][ r ].second ;
    }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( all_events[ wh ][ mid ].first <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( all_events[ wh ][ r ].first > sr ) { -- r ; }
    return all_events[ wh ][ r ].second ;
}

long long eval ( int wh , int st , int en ) {
    return get_up_to ( wh , en ) - get_up_to ( wh , st - 1 ) ;
}

class Tree {
public :
    long long tr[ 2 * MAXN ] ;
    int lazy[ 2 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] = eval ( lazy[ where ] , IL , IR ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = lazy[ where ] ;
            lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int nw ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = nw ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , nw ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , nw ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

void add ( int wh ) {
    auto it = act.upper_bound ( wh ) ;
    w.update ( 1 , 1 , q , wh , (*it) - 1 , hist[ wh ].z ) ;
    act.insert ( wh ) ;
}

void rem ( int wh ) {
    act.erase ( wh ) ;
    auto it = act.upper_bound ( wh ) ;
    auto lst = act.upper_bound ( wh ) ;
    -- lst ;
    w.update ( 1 , 1 , q , wh , (*it) - 1 , hist[ (*lst) ].z ) ;
}

void solve ( ) {
    hist[ 0 ].z = 1 ;
    act.insert ( 0 ) ;
    act.insert ( q + 1 ) ;
    int sz = v.size ( ) ;
    int hh = 0 ;
    w.init ( 1 , 1 , q ) ;
    w.update ( 1 , 1 , q , 1 , q , 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( hh < sz && v[ hh ].pos <= i ) {
            if ( v[ hh ].type == 1 ) {
                add ( v[ hh ].id ) ;
            }
            else {
                rem ( v[ hh ].id ) ;
            }
            ++ hh ;
        }

        for ( auto wh : qlist[ i ] ) {
            ans[ wh ] = w.query ( 1 , 1 , q , 1 , wh ) ;
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( hist[ i ].type == "Query" ) {
            cout << ans[ i ] << "\n" ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}