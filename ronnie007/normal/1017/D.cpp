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
using namespace std ;


int n , m , q ;
int w[ 17 ] ;
int to_end[ 17 ] ;

struct tuhla {
    int br ;
    int to[ 2 ] ;
    tuhla ( ) { br = to[ 0 ] = to[ 1 ] = 0 ; }
};

vector < tuhla > v ;
int sz ;

string sr ;
int aux ;
int ans = 0 ;

int mm[ 5007 ][ 107 ] ;
int hh[ 107 ] ;

void gen ( int where , int lft ) {
    if ( lft == 0 ) { return ; }
    v[ where ].to[ 0 ] = sz ;
    sz ++ ;
    v.push_back  ( tuhla ( ) ) ;
    v[ where ].to[ 1 ] = sz ;
    sz ++ ;
    v.push_back ( tuhla ( ) ) ;
    gen ( v[ where ].to[ 0 ] , lft - 1 ) ;
    gen ( v[ where ].to[ 1 ] , lft - 1 ) ;
}

void add ( string a ) {
    int i ;
    int where = 1 ;
    for ( i = 0 ; i < n ; i ++ ) {
        v[ where ].br ++ ;
        int h = ( a[ i ] - '0' ) ;
        where = v[ where ].to[ h ] ;
    }
    v[ where ].br ++ ;
}

int curdig ;
int cursm ;

void f ( int where ) {
    if ( cursm > 100 ) { return ; }
    if ( curdig == n ) {
        hh[ cursm ] += v[ where ].br ;
        return ;
    }
    int val = ( sr[ curdig ] - '0' ) ;
    if ( cursm + w[ curdig + 1 ] <= 100 ) {
        cursm += w[ curdig + 1 ] ;
        curdig ++ ;
        f ( v[ where ].to[ val ] ) ;
        curdig -- ;
        cursm -= w[ curdig + 1 ] ;
    }
    curdig ++ ;
    f ( v[ where ].to[ val^1 ] ) ;
    curdig -- ;
}

void input ( ) {
    cin >> n >> m >> q ;
    int i ;
    v.resize ( 2 ) ;
    sz = 2 ;
    gen ( 1 , n ) ;
    string a ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> w[ i ] ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        to_end[ i ] = ( to_end[ i + 1 ] + w[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        cin >> a ;
        add ( a ) ;
    }
}

void solve ( ) {
    int i , j ;
    sr.clear ( ) ;
    sr.resize ( n ) ;
    for ( i = 0 ; i < (1<<n) ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            int aux ;
            if ( (i&(1<<j)) != 0 ) { aux = 1 ; }
            else { aux = 0 ; }
            sr[ j ] = char ( '0' + aux ) ;
        }
        f ( 1 ) ;
        for ( j = 0 ; j <= 100 ; j ++ ) {
            mm[ i ][ j ] = hh[ j ] ;
            hh[ j ] = 0 ;
        }
    }
    while ( q != 0 ) {
        q -- ;
        cin >> sr >> aux ;
        int val = 0 ;
        for ( i = 0 ; i < n ; i ++ ) {
            if ( sr[ i ] == '1' ) { val += (1<<i) ; }
        }
        int ret = 0 ;
        for ( i = 0 ; i <= aux ; i ++ ) {
            ret += mm[ val ][ i ] ;
        }
        cout << ret << "\n" ;
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}