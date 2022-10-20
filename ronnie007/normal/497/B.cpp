#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std ;

#define MAXN 300007 

int n ;
int a[ MAXN ] ;
int pref1[ MAXN ] ;
int pref2[ MAXN ] ;
int wh1[ MAXN ] ;
int wh2[ MAXN ] ;
//1166750

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
    int i ;
    int j ;
    int br1 , br2 ;
    int s1 , s2 ;
    vector < pair < int , int > > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == 1 ) { pref1[ i ] = pref1[ i - 1 ] + 1 ; wh1[ pref1[ i ] ] = i ; } 
        else pref1[ i ] = pref1[ i - 1 ] ;

        if ( a[ i ] == 2 ) { pref2[ i ] = pref2[ i - 1 ] + 1 ; wh2[ pref2[ i ] ] = i ; } 
        else pref2[ i ] = pref2[ i - 1 ] ;


        
    }
    int ind1 ; 
    int ind2 ; 
    int lst = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        br1 = 0 ;
        br2 = 0 ;
        int curpos = 0 ;
        s1 = 0 ;
        s2 = 0 ;
        lst = -1 ; 
        while ( curpos < n ) {
            ind1 = MAXN  ;
            ind2 = MAXN ;
            if ( wh1[ br1 + i ] != 0 ) ind1 = wh1[ br1 + i ] ;
            if ( wh2[ br2 + i ] != 0 ) ind2 = wh2[ br2 + i ] ;
            if ( ind1 == MAXN && ind2 == MAXN ) break ;
            if ( ind1 < ind2 ) {
                s1 ++ ;
                curpos = wh1[ br1 + i ] ;
                br1 = pref1[ curpos ] ;
                br2 = pref2[ curpos ] ;
                lst = 0 ; 
            }
            else if ( ind1 > ind2 ) {
                s2 ++ ;
                curpos = wh2[ br2 + i ] ;
                br1 = pref1[ curpos ] ;
                br2 = pref2[ curpos ] ;
                lst = 1 ;
            }
            else {
                curpos = wh1[ br1 + i ] ;
                br1 = pref1[ curpos ] ;
                br2 = pref2[ curpos ] ;
            }
        }
        //if ( i == 3 ) printf ( "%d %d\n" , s1 , s2 ) ;
        if ( curpos != n ) continue ;
        if ( s1 < s2 ) { swap ( s1 , s2 ) ; lst ^= 1 ; } 
        if ( lst == 1 ) continue ;
        if ( s1 == s2 ) continue ;
        //if ( s1 % i != 0 ) continue ;
        //  s1 /= i ;
        //s2 /= i ;
        if ( pref1[ curpos ] != pref1[ n ] || pref2[ curpos ] != pref2[ n ] ) continue ;
        v.push_back ( make_pair ( s1 , i ) ) ;
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}