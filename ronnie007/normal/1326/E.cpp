#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 300007
int n ;
int a[ MAXN ] ;
int pos[ MAXN ] ;
int b[ MAXN ] ;

int ans[ MAXN ] ;

class Tree {
public :
    int sm[ 5 * MAXN ] ;
    int mx[ 5 * MAXN ] ;
    void merge ( int where ) {
        int l = 2 * where ;
        int r = l + 1 ;
        sm[ where ] = sm[ l ] + sm[ r ] ;
        mx[ where ] = max ( mx[ r ] , sm[ r ] + mx[ l ] ) ;
    }
    void init ( int where , int IL , int IR ) {
        mx[ where ] = sm[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            sm[ where ] += add ;
            mx[ where ] = sm[ where ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ;
        }
        merge ( where ) ;
    }
    int query ( ) { return mx[ 1 ] ; }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int id = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        w.update ( 1 , 1 , n , pos[ i ] , 1 ) ;
        while ( id < n && w.query ( ) > 0 ) {
            w.update ( 1 , 1 , n , b[ ++ id ] , -1 ) ;
            ans[ id ] = i ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
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