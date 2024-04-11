#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 500007

long long n ;
long long a[ MAXN ] ;
long long ans[ MAXN ] ;


class Tree {
    public :
    long long tr[ 3 * MAXN ] ;
    long long lst[ 3 * MAXN ] ;
    long long br[ 3 * MAXN ] ;
    void init ( long long where , long long IL , long long IR ) {
        if ( IL == IR ) {
            tr[ where ] = lst[ where ] = IL ;
            br[ where ] = 1 ;
            return ;
        }
        long long mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        lst[ where ] = max ( lst[ 2 * where ] , lst[ 2 * where + 1 ] ) ;
        br[ where ] = ( br[ 2 * where ] + br[ 2 * where + 1 ] ) ;
    }
    void update ( long long where , long long IL , long long IR , long long pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = 0 ;
            lst[ where ] = -1 ;
            br[ where ] = 0 ;
            return ;
        }
        long long mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos ) ;


        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        lst[ where ] = max ( lst[ 2 * where ] , lst[ 2 * where + 1 ] ) ;
        br[ where ] = ( br[ 2 * where ] + br[ 2 * where + 1 ] ) ;
    }
    long long query ( long long where , long long IL , long long IR , long long sm ) {
        if ( sm == tr[ where ] ) { return br[ where ] ; }
        long long mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where ] >= sm ) { return query ( 2 * where , IL , mid , sm ) ; }
        else { return ( br[ 2 * where ] + query ( 2 * where + 1 , mid + 1 , IR , sm - tr[ 2 * where ] ) ) ; }
    }

    long long get_id ( long long where , long long IL , long long IR , long long lft ) {
        if ( lft == br[ where ] ) { return lst[ where ] ; }
        long long mid = ( IL + IR ) / 2 ;
        if ( br[ 2 * where ] >= lft ) { return get_id ( 2 * where , IL , mid , lft ) ; }
        else { return get_id ( 2 * where + 1 , mid + 1 , IR , lft - br[ 2 * where ] ) ; }
    }
};

Tree w ;

void input ( ) {
    scanf ( "%I64d" , &n ) ;
    for ( long long i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
}


void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    for ( long long i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] != 0 ) {
            long long ret = w.query ( 1 , 1 , n , a[ i ] ) ;
            ans[ i ] = w.get_id ( 1 , 1 , n , ret + 1 ) ;
        }
        else {
            ans[ i ] = w.get_id ( 1 , 1 , n , 1 ) ;
        }
        w.update ( 1 , 1 , n , ans[ i ] ) ;
    }
    for ( long long i = 1 ; i <= n ; ++ i ) {
        printf ( "%I64d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}