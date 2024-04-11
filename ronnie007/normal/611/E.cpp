#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ 3 ] ;
int b[ MAXN ] ;


map < int , int > w ;
vector < int > v ;

int cap[ 3 ] ;
int ans ;

bool check ( int sr ) {
    for ( int i = 0 ; i < 3 ; ++ i ) { cap[ i ] = sr ; }
    int sz = v.size ( ) ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        bool fl = false ;
        for ( int j = 0 ; j < 3 ; ++ j ) {
            if ( a[ j ] >= v[ i ] && cap[ j ] > 0 ) {
                -- cap[ j ] ; fl = true ;
                break ;
            }
        }
        if ( fl == false ) {
            if ( a[ 0 ] + a[ 1 ] >= v[ i ] && cap[ 0 ] > 0 && cap[ 1 ] > 0 ) {
                -- cap[ 0 ] ; -- cap[ 1 ] ;
                fl = true ;
            }
        }
        if ( fl == false ) { return false ; }
    }
    return true ;
}

int get_mn ( ) {
    int l , r , mid ;
    if ( v.size ( ) == 0 ) { return 0 ; }
    l = 1 ;
    r = MAXN ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( check ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( check ( l ) == false ) { ++ l ; }
    return l ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    sort ( a , a + 3 ) ;
    sort ( b , b + n ) ;
}

void solve ( ) {
    if ( b[ n - 1 ] > a[ 0 ] + a[ 1 ] + a[ 2 ] ) {
        printf ( "-1\n" ) ;
        return ;
    }
    int init = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( b[ i ] > a[ 1 ] + a[ 2 ] ) {
            ++ init ;
        }
        else {
            if ( b[ i ] <= a[ 2 ] ) {
                ++ w[ b[ i ] ] ;
            }
            else {
                v.push_back ( b[ i ] ) ;
            }
        }
    }
    int sz = v.size ( ) ;
    ans = init + sz ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        int tot = a[ 0 ] + a[ 1 ] + a[ 2 ] ;
        if ( w.empty ( ) == true ) { break ; }
        for ( int j = 2 ; j >= 0 ; -- j ) {
            if ( tot - a[ j ] >= v[ i ] ) {
                auto it = w.upper_bound ( a[ j ] ) ;
                if ( it != w.begin ( ) ) {
                    -- it ;
                    if ( it->second > 1 ) { -- it->second ; }
                    else { w.erase ( it ) ; }
                    break ;
                }
            }
        }
    }
    v.clear ( ) ;
    for ( auto it = w.begin ( ) ; it != w.end ( ) ; ++ it ) {
        for ( int j = 0 ; j < it->second ; ++ j ) {
            v.push_back ( it->first ) ;
        }
    }
    ans += get_mn ( ) ;
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}