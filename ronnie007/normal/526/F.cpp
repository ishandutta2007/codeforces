#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
pair < int , int > a[ MAXN ] ;

pair < int , int > merge ( pair < int , int > p1 , pair < int , int > p2 ) {
    pair < int , int > ret ;
    ret.first = min ( p1.first , p2.first ) ;
    ret.second = 0 ;
    if ( ret.first == p1.first ) { ret.second += p1.second ; }
    if ( ret.first == p2.first ) { ret.second += p2.second ; }
    return ret ;
}

class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { IL , 1 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ].first += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
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
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    pair < int , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return { MAXN , 0 } ; }
        if ( IR < CURL || CURR < IL ) { return { MAXN , 0 } ; }
        if ( CURL <= IL && CURR <= IR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    stack < int > smin , smax ;
    smin.push ( 0 ) ;
    smax.push ( 0 ) ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( smin.top ( ) != 0 && a[ smin.top ( ) ].second > a[ i ].second ) {
            int en = smin.top ( ) ;
            smin.pop ( ) ;
            w.update ( 1 , 1 , n , smin.top ( ) + 1 , en , a[ en ].second ) ;
        }
        w.update ( 1 , 1 , n , smin.top ( ) + 1 , i , -a[ i ].second ) ;
        smin.push ( i ) ;

        while ( smax.top ( ) != 0 && a[ smax.top ( ) ].second < a[ i ].second ) {
            int en = smax.top ( ) ;
            smax.pop ( ) ;
            w.update ( 1 , 1 , n , smax.top ( ) + 1 , en , -a[ en ].second ) ;
        }
        w.update ( 1 , 1 , n , smax.top ( ) + 1 , i , a[ i ].second ) ;
        smax.push ( i ) ;
        w.update ( 1 , 1 , n , 1 , n , -1 ) ;
        pair < int , int > ret = w.query ( 1 , 1 , n , 1 , i ) ;
        if ( ret.first == 0 ) {
            ans += ret.second ;
        }
    }
    printf ( "%lld\n" , ans ) ;
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