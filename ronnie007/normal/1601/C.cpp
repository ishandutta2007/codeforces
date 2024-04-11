#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

class fenwick {
public :
    int tr[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= n ; ++ i ) { tr[ i ] = 0 ; }
    }
    void update ( int id , int x ) {
        for ( int i = id ; i <= n ; i += ( i & ( -i ) ) ) {
            tr[ i ] += x ;
        }
    }
    int query ( int id ) {
        int ret = 0 ;
        for ( int i = id ; i >= 1 ; i -= ( i & ( -i ) ) ) {
            ret += tr[ i ] ;
        }
        return ret ;
    }
};

fenwick foo ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int add ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += add ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( ) { return tr[ 1 ] ; }
};

Tree w ;

pair < int , int > srt[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        srt[ i ] = { a[ i ] , i } ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ] ;
    }
    sort ( b + 1 , b + m + 1 ) ;
    sort ( srt + 1 , srt + n + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    foo.init ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += foo.query ( n ) - foo.query ( srt[ i ].second ) ;
        foo.update ( srt[ i ].second , 1 ) ;
    }
    w.init ( 1 , 1 , n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        w.update ( 1 , 1 , n + 1 , i + 1 , n + 1 , 1 ) ;
    }
    int posl = 0 , posr = 1 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        while ( posl < n && srt[ posl + 1 ].first < b[ i ] ) {
            ++ posl ;
            w.update ( 1 , 1 , n + 1 , 1 , srt[ posl ].second , 1 ) ;
        }
        while ( posr <= n && srt[ posr ].first <= b[ i ] ) {
            w.update ( 1 , 1 , n + 1 , srt[ posr ].second + 1 , n + 1 , -1 ) ;
            ++ posr ;
        }
        ans += w.query ( ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}