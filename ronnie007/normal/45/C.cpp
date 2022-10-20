#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
string s ;
int a[ MAXN ] ;
int prv[ MAXN ] ;
int nxt[ MAXN ] ;
int used[ MAXN ] ;

struct tuhla {
	int diff ;
    int l , r ;
};

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
	if ( p1.diff != p2.diff ) { return ( p1.diff > p2.diff ) ; }
    return ( p1.l > p2.l ) ;
}

priority_queue < struct tuhla > q ;

void input ( ) {
	cin >> n ;
    cin >> s ;
    int i ;
    s = '#' + s ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> a[ i ] ;
        prv[ i ] = i - 1 ;
        nxt[ i ] = i + 1 ; 
    }
    struct tuhla u ;
    for ( i = 1 ; i < n ; i ++ ) {
    	if ( s[ i ] != s[ i + 1 ] ) {
        	u.l = i ;
            u.r = i + 1 ;
            u.diff = abs ( a[ i ] - a[ i + 1 ] ) ;
            q.push ( u ) ;
        }
    }
}

void solve ( ) {
	int i ;
    struct tuhla u , e ;
    vector < pair < int , int > > v ;
    while ( q.empty ( ) == false ) {
    	u = q.top ( ) ;
        q.pop ( ) ;
        if ( used[ u.l ] == 1 || used[ u.r ] == 1 ) { continue ; }
        used[ u.l ] = used[ u.r ] = 1 ;
        v.push_back ( make_pair ( u.l , u.r ) ) ;
        nxt[ prv[ u.l ] ] = nxt[ u.r ] ;
        prv[ nxt[ u.r ] ] = prv[ u.l ] ;
        int id = prv[ u.l ] ;
        if ( id != 0 && nxt[ id ] <= n ) {
        	if ( s[ id ] != s[ nxt[ id ] ] ) {
            	e.l = id ;
                e.r = nxt[ id ] ;
                e.diff = abs ( a[ e.l ] - a[ e.r ] ) ;
                q.push ( e ) ;
            }
        }
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	cout << v[ i ].first << " " << v[ i ].second << "\n" ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}