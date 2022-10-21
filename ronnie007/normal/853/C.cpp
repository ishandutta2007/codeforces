#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

int to_add[ MAXN ] ;
long long ans[ 5 * MAXN ] ;

long long xpref[ MAXN ] ;
long long xsuff[ MAXN ] ;

long long ypref[ MAXN ] ;
long long ysuff[ MAXN ] ;

struct tuhla {
    int row ;
    int st , en ;
    int coef ;
    int id ;
    tuhla ( ) { row = st = en = coef = id = 0 ; }
    tuhla ( int _row , int _st , int _en , int _coef , int _id ) {
        row = _row ;
        st = _st ;
        en = _en ;
        coef = _coef ;
        id = _id ;
    }
};
vector < tuhla > v[ MAXN ] ;


struct qq {
    int l , d , r , u ;
};

qq f[ MAXN ] ;

class Tree {
    public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
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
        update ( 2 * where , IL , mid , pos , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;


void process ( int l , int d , int r , int u , int id ) {
        if ( l > r || d > u ) { return ; }
        if ( d != 1 ) {
            v[ d - 1 ].push_back ( tuhla ( d - 1 , l , r , -1 , id ) ) ;
        }
        v[ u ].push_back ( tuhla ( u , l , r , 1 , id ) ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ypref[ i ] ++ ;
        ysuff[ i ] ++ ;
        scanf ( "%d" , &a[ i ] ) ;
        xpref[ a[ i ] ] ++ ;
        xsuff[ a[ i ] ] ++ ;
        to_add[ a[ i ] ] = i ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        xpref[ i ] += xpref[ i - 1 ] ;
        ypref[ i ] += ypref[ i - 1 ] ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        xsuff[ i ] += xsuff[ i + 1 ] ;
        ysuff[ i ] += ysuff[ i + 1 ] ;
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        scanf ( "%d%d%d%d" , &f[ i ].l , &f[ i ].d , &f[ i ].r , &f[ i ].u ) ;
        /**
        if ( f[ i ].l > f[ i ].r || f[ i ].d > f[ i ].u ) { continue ; }
        if ( f[ i ].d != 1 ) {
            v[ f[ i ].d - 1 ].push_back ( tuhla ( f[ i ].d - 1 , f[ i ].l , f[ i ].r , -1 , i ) ) ;
        }
        v[ f[ i ].u ].push_back ( tuhla ( f[ i ].u , f[ i ].l , f[ i ].r , 1 , i ) ) ;
        **/
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        process ( 1 , 1 , f[ i ].l - 1 , f[ i ].d - 1 , 4 * i ) ;
        process ( f[ i ].r + 1 , 1 , n , f[ i ].d - 1 , 4 * i + 1 ) ;
        process ( f[ i ].r + 1 , f[ i ].u + 1 , n , n , 4 * i + 2 ) ;
        process ( 1 , f[ i ].u + 1 , f[ i ].l - 1 , n , 4 * i + 3 ) ;
    }
}

void solve ( ) {
    int i , j ;
    w.init ( 1 , 1 , n ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        w.update ( 1 , 1 , n , to_add[ i ] , 1 ) ;
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            ans[ v[ i ][ j ].id ] += v[ i ][ j ].coef * w.query ( 1 , 1 , n , v[ i ][ j ].st , v[ i ][ j ].en ) ;
        }
    }
    long long tot = n ;
    tot *= ( n - 1 ) ;
    tot /= 2 ;
    for ( i = 1 ; i <= q ; i ++ ) {
        long long x , y , z , t ;
        x = xsuff[ f[ i ].u + 1 ] ;
        y = xpref[ f[ i ].d - 1 ] ;
        z = ysuff[ f[ i ].r + 1 ] ;
        t = ypref[ f[ i ].l - 1 ] ;
        long long cur = 0 ;
        cur += ( x * ( x - 1 ) / 2 ) ;
        cur += ( y * ( y - 1 ) / 2 ) ;
        cur += ( z * ( z - 1 ) / 2 ) ;
        cur += ( t * ( t - 1 ) / 2 ) ;
        x = ans[ 4 * i ] ;
        y = ans[ 4 * i + 1 ] ;
        z = ans[ 4 * i + 2 ] ;
        t = ans[ 4 * i + 3 ] ;
        cur -= ( x * ( x - 1 ) / 2 ) ;
        cur -= ( y * ( y - 1 ) / 2 ) ;
        cur -= ( z * ( z - 1 ) / 2 ) ;
        cur -= ( t * ( t - 1 ) / 2 ) ;
        long long ret = tot ;
        ret -= cur ;
        printf ( "%I64d\n" , ret ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}