#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 300007
#define MXVAL 300000

int n ;
int a[ MAXN ] ;
long long ans[ MAXN ] ;

class uptree {
public :
    pair < long long , int > tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { 0 , 0 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].first += pos ;
            ++ tr[ where ].second ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ].first = tr[ 2 * where ].first + tr[ 2 * where + 1 ].first ;
        tr[ where ].second = tr[ 2 * where ].second + tr[ 2 * where + 1 ].second ;
    }
    pair < long long , int > act = { 0 , 0 } ;
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            act.first += tr[ where ].first ;
            act.second += tr[ where ].second ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
uptree uptr ;


class downtr {
public :
    long long offset[ 4 * MAXN ] ;
    long long cnt[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        offset[ where ] = cnt[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    int tot = 1 ;
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            offset[ where ] += tot ;
            ++ cnt[ where ] ;
            tot += ( IR - IL + 1 ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
    long long ret = 0 ;
    void query ( int where , int IL , int IR , int pos ) {
        ret += offset[ where ] + ( pos - IL ) * cnt[ where ] ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            query ( 2 * where , IL , mid , pos ) ;
        }
        else {
            query ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
    }
};

downtr dwtr ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    uptr.init ( 1 , 1 , MXVAL ) ;
    dwtr.init ( 1 , 1 , MXVAL ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans[ i ] = ans[ i - 1 ] ;
        dwtr.ret = 0 ; dwtr.query ( 1 , 1 , MXVAL , a[ i ] ) ;
        ans[ i ] += dwtr.ret ;
        uptr.act = { 0 , 0 } ;
        uptr.query ( 1 , 1 , MXVAL , 1 , a[ i ] - 1 ) ;
        ans[ i ] += uptr.act.first ;
        for ( int j = 0 ; j <= MXVAL ; j += a[ i ] ) {
            int en = j + a[ i ] - 1 ;
            if ( en > MXVAL ) { en = MXVAL ; }
            
            if ( j > 0 ) {
                uptr.act = { 0 , 0 } ;
                uptr.query ( 1 , 1 , MXVAL , j , en ) ;
                pair < long long , int > ret = uptr.act ;
                ans[ i ] += ret.first - 1LL * ret.second * j ;
            }

            dwtr.tot = 1 ;
            dwtr.update ( 1 , 1 , MXVAL , j + 1 , en ) ;
        }
        uptr.update ( 1 , 1 , MXVAL , a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}