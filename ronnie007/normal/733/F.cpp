#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std ;

#define MAXN 200007
#define inf 1000000007
int n , m ;
long long val[ MAXN ] ;
long long cost[ MAXN ] ;

long long BUDGET ;
long long TOTDIST ;

int lstedgeid[ MAXN ] ;

int prv[ MAXN ] ;

pair < int , int > a[ MAXN ] ;
int f[ MAXN ][ 27 ] ;
int mxedge[ MAXN ][ 27 ] ;

long long sm[ MAXN ] ;
int lvl[ MAXN ] ;

struct tuhla {
	long long h ;
    int x , y ;
    int id ;
};

vector < struct tuhla > v ;

vector < struct tuhla > gr[ MAXN ] ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.h < p2.h ) ;
}

int find ( int x ) {
	if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( struct tuhla u ) {
	int k1 = find ( u.x ) ;
    int k2 = find ( u.y ) ;
    if ( k1 != k2 ) {
    	prv[ k1 ] = k2 ;
        struct tuhla e ;
        e.h = u.h ;
        e.x = u.y ;
        e.id = u.id ;
        gr[ u.x ].push_back ( e ) ;
        e.x = u.x ;
        gr[ u.y ].push_back ( e ) ;
        TOTDIST += e.h ;
    }
}


void dfs_calc ( int vertex , int lst ) {
	int i ;
    for ( i = 1 ; i <= 20 ; i ++ ) {
    	f[ vertex ][ i ] = f[ f[ vertex ][ i - 1 ] ][ i - 1 ] ;
        mxedge[ vertex ][ i ] = max ( mxedge[ vertex ][ i - 1 ] , mxedge[ f[ vertex ][ i - 1 ] ][ i - 1 ] ) ;
    }
    int sz = gr[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( gr[ vertex ][ i ].x != lst ) {
        	f[ gr[ vertex ][ i ].x ][ 0 ] = vertex ;
            lvl[ gr[ vertex ][ i ].x ] = lvl[ vertex ] + 1 ;
            sm[ gr[ vertex ][ i ].x ] = sm[ vertex ] + gr[ vertex ][ i ].h ;
            mxedge[ gr[ vertex ][ i ].x ][ 0 ] = gr[ vertex ][ i ].h ;
            lstedgeid[ gr[ vertex ][ i ].x ] = gr[ vertex ][ i ].id ;
            dfs_calc ( gr[ vertex ][ i ].x , vertex ) ;
        }
    }
}

int LCA ( int x , int y ) {
	int i ;
    for ( i = 20 ; i >= 0 ; i -- ) {
    	if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
        	x = f[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
        	y = f[ y ][ i ] ;
        }
    }
    for ( i = 20 ; i >= 0 ; i -- ) {
    	if ( f[ x ][ i ] != f[ y ][ i ] ) {
        	x = f[ x ][ i ] ;
            y = f[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = f[ x ][ 0 ] ; }
    return x ; 
}

int getmxedge ( int x , int y ) {
	int i ;
    int ret = 0 ;
    for ( i = 20 ; i >= 0 ; i -- ) {
    	if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
        	ret = max ( ret , mxedge[ x ][ i ] ) ;
        	x = f[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
        	ret = max ( ret , mxedge[ y ][ i ] ) ;        
        	y = f[ y ][ i ] ;
        }
    }
    for ( i = 20 ; i >= 0 ; i -- ) {
    	if ( f[ x ][ i ] != f[ y ][ i ] ) {
        	ret = max ( ret , mxedge[ x ][ i ] ) ;
        	ret = max ( ret , mxedge[ y ][ i ] ) ;            
        	x = f[ x ][ i ] ;
            y = f[ y ][ i ] ;
        }
    }
    if ( x != y ) {
        ret = max ( ret , mxedge[ x ][ 0 ] ) ;
        ret = max ( ret , mxedge[ y ][ 0 ] ) ;                        
    	x = f[ x ][ 0 ] ;
	}
    return ret ; 
}

long long calc ( struct tuhla u ) {
	int id = LCA ( u.x , u.y ) ;
    long long ret = TOTDIST - getmxedge ( u.y , u.x ) + u.h ;
    return ret ;
}

void printans ( struct tuhla u ) {
	int id = LCA ( u.x , u.y ) ;
    int val = getmxedge ( u.x , u.y ) ;
    int pr = u.x ;
    int mx = -inf ;
    int edgeid = 0 ;
    int i , j ;
    while ( pr != id ) {
    	if ( mx < mxedge[ pr ][ 0 ] ) {
        	mx = mxedge[ pr ][ 0 ] ;
            edgeid = lstedgeid[ pr ] ;
        }
        pr = f[ pr ][ 0 ] ;
    }
	pr = u.y ;
    while ( pr != id ) {
    	if ( mx < mxedge[ pr ][ 0 ] ) {
        	mx = mxedge[ pr ][ 0 ] ;
            edgeid = lstedgeid[ pr ] ;
        }
        pr = f[ pr ][ 0 ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	int sz = gr[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
	    	if ( gr[ i ][ j ].id == edgeid ) { continue ; }
            if ( i >= gr[ i ][ j ].x ) { continue ; }
            cout << gr[ i ][ j ].id << " " << gr[ i ][ j ].h << "\n" ;
		}
    }
    cout << u.id << " " << u.h << "\n" ;
}

void input ( ) {
	cin >> n >> m ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	cin >> val[ i ] ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	cin >> cost[ i ] ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	cin >> a[ i ].first >> a[ i ].second ;
        struct tuhla u ;
        u.h = val[ i ] ;
        u.x = a[ i ].first ;
        u.y = a[ i ].second ;
        u.id = i ;
        v.push_back ( u ) ;
    }
    cin >> BUDGET ;
    for ( i = 1 ; i <= n ; i ++ ) { prv[ i ] = -1 ; }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
	int i ;
    for ( i = 0 ; i < m ; i ++ ) {
    	UNITE ( v[ i ] ) ;
    }
    dfs_calc ( 1 , 0 ) ;
    for ( i = 0 ; i < m ; i ++ ) {
    	v[ i ].h = ( v[ i ].h - ( BUDGET / cost[ v[ i ].id ] ) ) ;
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    long long bestval = 0 ;
    int id = -1 ;
    for ( i = 0 ; i < m ; i ++ ) {
    	long long curval = calc ( v[ i ] ) ;
        if ( id == -1 || bestval > curval ) {
        	bestval = curval ;
            id = i ;
        }
    }
    cout << bestval << "\n" ;
    printans ( v[ id ] ) ;
}

int main ( ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input ( ) ;
	solve ( ) ;
	return 0 ;
}