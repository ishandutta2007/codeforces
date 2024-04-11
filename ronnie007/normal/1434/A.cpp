#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define inf 1000000007

int h[ 7 ] ;
int n ;
int a[ MAXN ] ;

vector < pair < int , int > > ord ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = -inf ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int nw ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = nw ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nw ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( ) { return tr[ 1 ] ; }
};
Tree w ;

void input ( ) {
    for ( int i = 1 ; i <= 6 ; ++ i ) {
        scanf ( "%d" , &h[ i ] ) ;
    }
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        for ( int j = 1 ; j <= 6 ; ++ j ) {
            ord.push_back ( { a[ i ] - h[ j ] , i } ) ;
        }
    }
    sort ( ord.begin ( ) , ord.end ( ) ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int len = ord.size ( ) ;
    int min_ans = -1 ;
    for ( int i = 0 ; i < len ; ++ i ) {
        int j = i ;
        while ( j + 1 < len && ord[ j + 1 ].first == ord[ i ].first ) {
            ++ j ;
        }
        for ( int t = i ; t <= j ; ++ t ) {
            w.update ( 1 , 1 , n , ord[ t ].second , ord[ i ].first ) ;
        }
        int ret = w.query ( ) ;
        if ( ret > -inf ) {
            ret = ord[ i ].first - ret ;
            if ( min_ans < 0 || min_ans > ret ) { min_ans = ret ; }
        }
        i = j ;
    }
    printf ( "%d\n" , min_ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}