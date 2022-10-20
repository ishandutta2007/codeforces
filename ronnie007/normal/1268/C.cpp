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

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int pos[ MAXN ] ;
long long inv[ MAXN ] ;

class Tree {
    public :
    int tr[ 5 * MAXN ] ;
    long long sm[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = sm[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            ++ tr[ where ] ;
            sm[ where ] = IL ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ;
        }
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        sm[ where ] = ( sm[ 2 * where ] + sm[ 2 * where + 1 ] ) ;
    }
    int query_cnt ( int where , int IL , int IR , int st , int en ) {
        if ( st > en || IL > IR ) { return 0 ; }
        if ( IR < st || en < IL ) { return 0 ; }
        if ( st <= IL && IR <= en ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query_cnt ( 2 * where , IL , mid , st , en ) + query_cnt ( 2 * where + 1 , mid + 1 , IR , st , en ) ) ;
    }
    long long query_sm ( int where , int IL , int IR , int st , int en ) {
        if ( st > en || IL > IR ) { return 0 ; }
        if ( IR < st || en < IL ) { return 0 ; }
        if ( st <= IL && IR <= en ) { return sm[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query_sm ( 2 * where , IL , mid , st , en ) + query_sm ( 2 * where + 1 , mid + 1 , IR , st , en ) ) ;
    }
};

Tree w ;

long long calc ( int arg ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    int h = ( arg / 2 ) + ( arg & 1 ) ;
    while ( r - l > 3 ) {
        int mid = ( l + r ) / 2 ;
        int aux = w.query_cnt ( 1 , 1 , n , 1 , mid ) ;
        if ( aux < h ) { l = mid ; }
        else { r = mid ; }
    }
    while ( w.query_cnt ( 1 , 1 , n , 1 , l ) < h ) { ++ l ; }
    long long aux = w.query_sm ( 1 , 1 , n , l + 1 , n ) - w.query_sm ( 1 , 1 , n , 1 , l ) ;
    aux += 1LL * ( l - h ) * h - 1LL * ( l - h ) * ( arg - h ) ;
    aux += ( 1LL + h ) * h / 2 ;
    aux -= 1LL * h * ( arg - h ) + ( 1LL + arg - h ) * ( arg - h ) / 2 ;
    return aux ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        inv[ i ] = inv[ i - 1 ] + w.query_cnt ( 1 , 1 , n , pos[ i ] + 1 , n ) ;
        w.update ( 1 , 1 , n , pos[ i ] , 1 ) ;
        printf ( "%I64d " , inv[ i ] + calc ( i ) ) ;
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