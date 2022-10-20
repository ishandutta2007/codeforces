#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007
#define MAGIC 350

int n , q ;
int a[ MAXN ] ;

int lst[ MAXN ] ;
int cnt[ MAXN ] ;

void upd ( int id ) {
    int st = id * MAGIC ;
    int en = min ( ( id + 1 ) * MAGIC - 1 , n - 1 ) ;
    for ( int i = en ; i >= st ; -- i ) {
        lst[ i ] = i ; cnt[ i ] = 0 ;
        if ( i + a[ i ] < n && ( i + a[ i ] ) / MAGIC == i / MAGIC ) {
            lst[ i ] = lst[ i + a[ i ] ] ;
            cnt[ i ] = cnt[ i + a[ i ] ] + 1 ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = ( n - 1 ) / MAGIC ; i >= 0 ; -- i ) {
        upd ( i ) ;
    }
    auto advance = [ & ] ( int st ) {
        int ans = 0 ;
        while ( st + a[ st ] < n ) {
            if ( ( st + a[ st ] ) / MAGIC == st / MAGIC ) {
                ans += cnt[ st ] ;
                st = lst[ st ] ;
                continue ;
            }
            st += a[ st ] ;
            ++ ans ;
        }
        ++ ans ;
        return make_pair ( st , ans ) ;
    };
    while ( q -- ) {
        int type ;
        int x , y ;
        scanf ( "%d" , &type ) ;
        if ( type == 0 ) {
            scanf ( "%d%d" , &x , &y ) ; -- x ;
            a[ x ] = y ;
            upd ( x / MAGIC ) ;
        }
        else {
            scanf ( "%d" , &x ) ; -- x ;
            auto ret = advance ( x ) ;
            printf ( "%d %d\n" , ret.first + 1 , ret.second ) ;
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