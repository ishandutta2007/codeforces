#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MOD 998244353
#define MAXN 400007
#define mxval 200000

int n , m ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;


void init ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

long long comb ( int up , int down ) {
    if ( up < 0 || down < 0 ) { return 0 ; }
    if ( up < down ) { return 0 ; }
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

pair < int , int > a[ MAXN ] ;
int mxdepth[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = ( IR - IL + 1 ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] += val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    int get ( int where , int IL , int IR , int k ) {
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where ] >= k ) { return get ( 2 * where , IL , mid , k ) ; }
        return get ( 2 * where + 1 , mid + 1 , IR , k - tr[ 2 * where ] ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
}

void solve ( ) {
    vector < int > v ;
    set < int > s ;
    for ( int i = m ; i >= 1 ; -- i ) {
        int x = w.get ( 1 , 1 , mxval , a[ i ].second ) ;
        int y = w.get ( 1 , 1 , mxval , a[ i ].second + 1 ) ;

        w.update ( 1 , 1 , mxval , x , -1 ) ;
        s.insert ( y ) ;
        v.push_back ( x ) ;
    }
    for ( auto x : v ) {
        w.update ( 1 , 1 , mxval , x , 1 ) ;
    }
    cout << comb ( 2 * n - (int)s.size ( ) - 1 , n ) << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    w.init ( 1 , 1 , mxval ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}