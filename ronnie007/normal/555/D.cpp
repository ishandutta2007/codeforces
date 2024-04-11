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

int n , q ;
pair < int , int > a[ MAXN ] ;
int pos[ MAXN ] ;


int getl ( int sr ) {
    int l , r , mid ;
    l = 1 , r = n ;
    while ( r - l > 1 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ].first > sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( r > 1 && a[ r ].first > sr ) { --r ; }
    return r ;
}

int getr ( int sr ) {
    int l , r , mid ;
    l = 1 , r = n ;
    while ( r - l > 1 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ].first < sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( l < n && a[ l ].first < sr ) { ++ l ; }
    return l ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pos[ a[ i ].second ] = i ;
    }
}

void solve ( ) {
    while ( q -- ) {
        int st , len ;
        scanf ( "%d%d" , &st , &len ) ;
        st = pos[ st ] ;
        int dir = 1 ;
        bool fst = true ;
        int cons = 0 ;
        while ( 1 ) {
            if ( len == 0 || cons >= 2 ) { printf ( "%d\n" , a[ st ].second ) ; break ; }
            if ( dir == 1 ) {
                int ret = getl ( a[ st ].first + len ) ;
                if ( ret == st ) { dir = -1 ; ++ cons ; continue ; }
                cons = 0 ;
                int diff = ( a[ ret ].first - a[ st ].first ) ;
                if ( fst == false ) {
                    len %= ( diff << 1 ) ;
                }
                if ( len >= diff ) {
                    len -= diff ;
                    dir = -1 ;
                    st = ret ;
                }
            }
            else {
                int ret = getr ( a[ st ].first - len ) ;
                if ( ret == st ) { dir = 1 ; ++ cons ; continue ; }
                cons = 0 ;
                int diff = ( a[ st ].first - a[ ret ].first ) ;
                if ( fst == false ) {
                    len %= ( diff << 1 ) ;
                }
                if ( len >= diff ) {
                    len -= diff ;
                    dir = 1 ;
                    st = ret ;
                }
            }
            fst = false ;
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