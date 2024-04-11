#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

struct query {
    int type ;
    int x , y ;
    int id ;
};

int q ;
query a[ MAXN ] ;

vector < query > v ;

bool cmp ( query p1 , query p2 ) {
    return p1.x < p2.x ;
}
int n ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    long long sm[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void unite ( int where ) {
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = sm[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update_pos ( int where , int IL , int IR , int pos , int val , int len ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) { tr[ where ] += val ; sm[ where ] += len ; return ; }
        int mid = ( IL + IR ) / 2 ;
        update_pos ( 2 * where , IL , mid , pos , val , len ) ;
        update_pos ( 2 * where + 1 , mid + 1 , IR , pos , val , len ) ;
        unite ( where ) ;
    }
    void update_range ( int where , int IL , int IR , int CURL , int CURR , int add ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += add ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_range ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update_range ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
        unite ( where ) ;
    }
    long long get_sm ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return sm[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return get_sm ( 2 * where , IL , mid , CURL , CURR ) + get_sm ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
    long long get_mx ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( get_mx ( 2 * where , IL , mid , CURL , CURR ) , get_mx ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> q ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        char c ;
        cin >> c ;
        if ( c == '+' ) {
            a[ i ].type = 1 ;
            cin >> a[ i ].x >> a[ i ].y ;
            a[ i ].id = i ;
            v.push_back ( a[ i ] ) ;
        }
        else if ( c == '-' ) {
            a[ i ].type = 2 ;
            cin >> a[ i ].x ;
        }
        else {
            a[ i ].type = 3 ;
            cin >> a[ i ].x ;
        }
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    n = v.size ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        a[ v[ i ].id ].id = i + 1 ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( a[ i ].type == 1 ) {
            w.update_pos ( 1 , 1 , n , a[ i ].id , a[ i ].x , a[ i ].y ) ;
            w.update_range ( 1 , 1 , n , 1 , a[ i ].id , a[ i ].y ) ;
        }
        else if ( a[ i ].type == 2 ) {
            w.update_pos ( 1 , 1 , n , a[ a[ i ].x ].id , - a[ a[ i ].x ].x , - a[ a[ i ].x ].y ) ;
            w.update_range ( 1 , 1 , n , 1 , a[ a[ i ].x ].id , - a[ a[ i ].x ].y ) ;            
        }
        else {
            if ( n == 0 ) { cout << "0\n" ; continue ; }
            int l , r , mid ;
            l = 1 ;
            r = n ;
            while ( r - l > 3 ) {
                mid = ( l + r ) / 2 ;
                if ( v[ mid - 1 ].x > a[ i ].x ) { r = mid ; }
                else { l = mid ; }
            }
            while ( r >= 1 && v[ r - 1 ].x > a[ i ].x ) { -- r ; }
            long long sub = w.get_sm ( 1 , 1 , n , r + 1 , n ) ;
            long long ret = w.get_mx ( 1 , 1 , n , 1 , r ) ;
            cout << max ( 0LL , ret - sub - a[ i ].x ) << "\n" ;
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