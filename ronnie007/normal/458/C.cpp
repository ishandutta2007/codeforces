#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;

priority_queue < int > q ;
int n ;
int c ;
vector < int > v[ 100007 ] ;

int f ( int e ) {
    int cur = v[ 0 ].size ( ) ;
    int i ;
    int sz ;
    int j ;
    int ret = 0 ;
    int r ;
    while ( q.empty ( ) == false ) q.pop ( ) ;
    for ( i = 1 ; i <= 100000 ; i ++ ) {
        if ( v[ i ].size ( ) == 0 ) continue ;
        sz = v[ i ].size ( ) ;
        for ( j = e ; j < sz ; j ++ ) {
            ret += v[ i ][ j ] ;
            cur ++ ;
        }

        for ( j = 0 ; j < sz ; j ++ ) {
            if ( j >= e ) break ;
            q.push ( -v[ i ][ j ] ) ;
        }
    }
    while ( cur <= e ) {
        ret -= q.top ( ) ;
        q.pop ( ) ;
        cur ++ ;
    }
    return ret ;
}


void input ( ) ;
void solve ( ) ;

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    int x , y ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
    }
    for ( i = 0 ; i <= 100000 ; i ++ ) {
        sort ( v[ i ].begin ( )  , v[ i ].end ( ) , greater<int>()) ;
    }
}

void solve ( ) {
    int l , r , mid1 , mid2  ;
    l = 0 ;
    r = n - 1 ;
    int x , y ;

    while ( r - l > 7 ) {
        mid1 = l + ( r - l ) / 3 ;
        mid2 = r - ( r - l ) / 3 ;
        if ( f ( mid1 ) <= f ( mid2 ) ) r = mid2 ;
        else l = mid1 ;
    }
    int i ;
    int mn = f ( l ) ;
    for ( i = l + 1 ; i <= r ; i ++ ) {
        mn = min ( mn , f( i ) ) ;
    }
    printf ( "%d\n" , mn ) ;
}