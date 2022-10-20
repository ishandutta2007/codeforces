#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 1007

int n , m , tot , st , en ;
long long inf ;

struct tuhla {
	int x , y ;
    long long len ;
};
vector < struct tuhla > edges ;

vector < pair < int , long long > > v[ MAXN ] ;

pair < int , int > edgid[ MAXN ] ;

long long dist[ MAXN ] ;
int prv[ MAXN ] ;

struct state {
	int where ;
    long long cost ;
};

bool operator < ( struct state p1 , struct state p2 ) {
	return ( p1.cost > p2.cost ) ;
}

priority_queue < struct state > q ;

map < pair < int , int > , int > ZX ; 

void dijkstra ( int val ) {
	int i ;
    for ( i = 0 ; i <= n ; i ++ ) {
    	dist[ i ] = inf ;
        prv[ i ] = -1 ;
        edgid[ i ] = make_pair ( 0 , 0 ) ;
    }
    dist[ st ] = 0 ;
    struct state u , e ;
    u.where = st ;
    u.cost = 0 ;
    q.push ( u ) ;
    while ( q.empty ( ) == false ) {
    	u = q.top ( ) ;
        q.pop ( ) ;
        if ( u.cost != dist[ u.where ] ) { continue ; }
       	int sz = v[ u.where ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
        	int to = v[ u.where ][ i ].first ;
            long long len = v[ u.where ][ i ].second ;
            if ( val == 0 && len == 0 ) { continue ; }
            if ( val == 1 && len == 0 ) { len = 1 ; }
            if ( dist[ to ] > u.cost + len ) {
            	prv[ to ] = u.where ;
                edgid[ to ] = make_pair ( u.where , i ) ;
            	dist[ to ] = u.cost + len ;
                e.where = to ;
                e.cost = dist[ to ] ;
                q.push ( e ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m >> tot >> st >> en ; 
    edges.resize ( m ) ;
    int i ;
    for ( i = 0 ; i < m ; i ++ ) {
        cin >> edges[ i ].x >> edges[ i ].y >> edges[ i ].len ; 
        v[ edges[ i ].x ].push_back ( make_pair ( edges[ i ].y , edges[ i ].len ) ) ;
        v[ edges[ i ].y ].push_back ( make_pair ( edges[ i ].x , edges[ i ].len ) ) ;
    }
    inf = 1 ;
    for ( i = 1 ; i <= 10 ; i ++ ) { inf *= 10 ; }
}

void solve ( ) {
	dijkstra ( 0 ) ;
    if ( dist[ en ] < tot ) { cout << "NO\n" ; return ; }
    dijkstra ( 1 ) ;
    if ( dist[ en ] > tot ) { cout << "NO\n" ; return ; }
    cout << "YES\n" ;
    while ( 1 ) {
    	dijkstra ( 1 ) ;
        if ( dist[ en ] == tot ) { break ; }
	    int x = en ;
        long long h = ( tot - dist[ en ] ) ;
    	while ( x != st ) {
			int p , q ;
            p = edgid[ x ].first ;
            q = edgid[ x ].second ;
            if ( v[ p ][ q ].second == 0 ) { v[ p ][ q ].second = h + 1 ; ZX[ make_pair ( p , v[ p ][ q ].first ) ] = h + 1 ; break ; }
	        x = prv[ x ] ;
    	}
	}
    int i ;
    for ( i = 0 ; i < m ; i ++ ) {
    	if ( edges[ i ].len != 0 ) {
        	cout << edges[ i ].x << " " << edges[ i ].y << " " << edges[ i ].len << "\n" ; 
        }
       	else {
        	if ( ZX.find ( make_pair ( edges[ i ].x , edges[ i ].y ) ) == ZX.end ( ) && ZX.find ( make_pair ( edges[ i ].y , edges[ i ].x ) ) == ZX.end ( ) ) {
            	cout << edges[ i ].x << " " << edges[ i ].y << " " << 1 << "\n" ;
            }
            else {
            	long long val ;
                if ( ZX.find ( make_pair ( edges[ i ].x , edges[ i ].y ) ) != ZX.end ( ) ) { val = ZX[ make_pair ( edges[ i ].x , edges[ i ].y ) ] ; }
                if ( ZX.find ( make_pair ( edges[ i ].y , edges[ i ].x ) ) != ZX.end ( ) ) { val = ZX[ make_pair ( edges[ i ].y , edges[ i ].x ) ] ; }                
            	cout << edges[ i ].x << " " << edges[ i ].y << " " << val << "\n" ;
            }
        }
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}