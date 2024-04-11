#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1000007

int n , m ;
vector < int > v[ MAXN ] ;
int val[ MAXN ] ;

struct query {
    int st , pos ;
    int id ;
    query ( int _st , int _pos , int _id ) {
        st = _st , pos = _pos , id = _id ;
    }
};

vector < query > q[ MAXN ] ;
int ans[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR ) {
            tr[ where ] += add ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ;
        }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    pair < int , int > get_kth ( int where , int IL , int IR , int st , int pos ) {
        if ( IR < st ) { return { -1 , 0 } ; }
        if ( st <= IL ) {
            if ( pos > tr[ where ] ) {
                return { -1 , tr[ where ] } ;
            }
            if ( IL == IR ) {
                return { IL , 0 } ;
            }
        }
        int mid = ( IL + IR ) / 2 ;
        auto ret1 = get_kth ( 2 * where , IL , mid , st , pos ) ;
        if ( ret1.first != -1 ) { return ret1 ; }
        auto ret2 = get_kth ( 2 * where + 1 , mid + 1 , IR , st , pos - ret1.second ) ;
        if ( ret2.first != -1 ) { return ret2 ; }
        return { -1 , ret1.second + ret2.second } ;
    }
};
Tree w ;

int cnt[ MAXN ] ;
set < int > s[ MAXN ] ;

void add ( int x , int coef ) {
    if ( cnt[ x ] > 0 ) { 
        s[ cnt[ x ] ].erase ( x ) ;
        w.update ( 1 , 1 , n , cnt[ x ] , -1 ) ;
    }
    cnt[ x ] += coef ;
    if ( cnt[ x ] > 0 ) {
        s[ cnt[ x ] ].insert ( x ) ;
        w.update ( 1 , 1 , n , cnt[ x ] , 1 ) ;
    }
}

void dfs ( int vertex ) {
    add ( val[ vertex ] , 1 ) ;
    for ( auto [ st , pos , id ] : q[ vertex ] ) {
        auto ret = w.get_kth ( 1 , 1 , n , st , pos ) ;
        if ( ret.first == -1 ) { ans[ id ] = -1 ; }
        else { ans[ id ] = *( s[ ret.first ].begin ( ) ) ; }
    }
    for ( auto x : v[ vertex ] ) {
        dfs ( x ) ;
    }
    add ( val[ vertex ] , -1 ) ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        q[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> val[ i ] ;
        cnt[ i ] = 0 ;
        s[ i ].clear ( ) ;
    }
    for ( int i = 2 , prv ; i <= n ; ++ i ) {
        cin >> prv ;
        v[ prv ].push_back ( i ) ;
    }
    for ( int i = 1 , wh , st , pos ; i <= m ; ++ i ) {
        cin >> wh >> st >> pos ;
        q[ wh ].push_back ( query ( st , pos , i ) ) ;
        
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    dfs ( 1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}