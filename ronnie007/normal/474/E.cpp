#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

set < int > s ;
int n ;
long long d ;

long long a[ 100007 ] ; 
int pred[ 100007 ] ;
int len[ 100007 ] ;

long long f ( long long x ) {
    if ( x < 0 ) x = -x ;
    return x ; 
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    int i ;
    cin >> n >> d ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ; 
    }
    pred[ 1 ] = -1 ;
    len[ 1 ] = 1 ;
    s.insert ( 1 ) ;
}

void solve ( )  {
    int i ;
    //long long mx = a[ 0 ] ;
    //long long mn = a[ 0 ] ; 
    set < int > ::iterator j ;
    int br = -1 ;
    int ind = -1 ; 
    int tot = 0 ; 
    int cur = 0 ;
    for ( i = 2 ; i <= n ; i ++ ) {

        br = -1 ;
        ind = -1 ; 
        tot = 0 ;
        for ( j = s.begin ( ) ; j != s.end ( ) ; j ++ ) {
            int u = (*j) ;
            cur = 0 ; 
            while ( u != -1 ) {
                tot ++ ;
                cur ++ ;
                //  printf ( "%d\n" , u ) ;
                if ( f ( a[ i ] - a[ u ] ) >= d ) {
                    if ( len[ u ] + 1 > br || br == -1 ) { br = len[ u ] + 1 ; ind = u ; }
                    break ;
                }
                u = pred[ u ] ; 
                if ( n * cur >= 30000000 ) break ; 
            }
            if ( tot * n >= 30000000 ) break ;
        }
        tot = 0 ;
        for ( j = s.end ( ) ; j != s.begin ( ) ; j -- ) {
            int u = (*j) ;
            cur = 0 ; 
            while ( u != -1 ) {
                tot ++ ;
                cur ++ ;
                //  printf ( "%d\n" , u ) ;
                if ( f ( a[ i ] - a[ u ] ) >= d ) {
                    if ( len[ u ] + 1 > br || br == -1 ) { br = len[ u ] + 1 ; ind = u ; }
                    break ;
                }
                u = pred[ u ] ; 
                if ( n * cur >= 30000000 ) break ; 
            }
            if ( tot * n >= 30000000 ) break ;
        }
        if ( br != -1 ) {
            pred[ i ] = ind ;
            len[ i ] = br ;
            s.erase ( ind ) ;
            s.insert ( i ) ;
        }
        else {
            pred[ i ] = -1 ;
            len[ i ] = 1 ;
            s.insert ( i ) ;
        }
            //if ( mx < a[ i ] ) mx = a[ i ] ;
            //if ( mn > a[ i ] ) mn = a[ i ] ;
    }
    vector < int > ans ;
    br = -1 ; 
    ind = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( br < len[ i ] ) { br = len[ i ] ; ind = i ; } 
    }
    ans.push_back ( ind ) ;
    while ( ind != -1 ) {
        ind = pred[ ind ] ;
        if ( ind != -1 ) ans.push_back ( ind ) ;
    }
    int sz = ans.size ( ) ;
    cout << sz << "\n" ; 
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        cout << ans[ i ] ;
        if ( i == 0 ) cout << "\n" ; 
        else cout << " " ;
    }
}