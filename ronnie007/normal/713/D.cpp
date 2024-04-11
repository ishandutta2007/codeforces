#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 1007

int n , m ;
int a[ MAXN ][ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;

short RMQ[ MAXN ][ MAXN ][ 11 ][ 11 ] ;

int stid[ MAXN ] ;

int xx1 , yy1 , xx2 , yy2 ;

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    //cin >> n >> m ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= m ; j ++ ) {
        	scanf ( "%d" , &a[ i ][ j ] ) ;
            //cin >> a[ i ][ j ] ;
            pref[ i ][ j ] = a[ i ][ j ] + pref[ i - 1 ][ j ] + pref[ i ][ j - 1 ] - pref[ i - 1 ][ j - 1 ] ;
        }
    }
}

void solve ( ) {
	int i , j , t , z ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= m ; j ++ ) {
        	if ( a[ i ][ j ] == 0 ) { RMQ[ i ][ j ][ 0 ][ 0 ] = 0 ; continue ; }
        	int l , r , mid ;
            l = 1 ;
            r = min ( ( n - i + 1 ) , ( m - j + 1 ) ) ;
            while ( r - l > 3 ) {
            	mid = ( l + r ) / 2 ;
                int val = pref[ i + mid - 1 ][ j + mid - 1 ] - pref[ i + mid - 1 ][ j - 1 ] - pref[ i - 1 ][ j + mid - 1 ] + pref[ i - 1 ][ j - 1 ] ;
                if ( val == mid * mid ) { l = mid ; }
                else { r = mid ; }
            }
            while ( 1 ) {
            	int val = pref[ i + r - 1 ][ j + r - 1 ] - pref[ i + r - 1 ][ j - 1 ] - pref[ i - 1 ][ j + r - 1 ] + pref[ i - 1 ][ j - 1 ] ;
                if ( val == r * r ) { break ; }
				else { r -- ; }
            }
            RMQ[ i ][ j ][ 0 ][ 0 ] = r ;
        }
    }
    for ( t = 0 ; t <= 9 ; t ++ ) {
		for ( z = 0 ; z <= 9 ; z ++ ) {
        	if ( t + z == 0 ) { continue ; }
        	for ( i = 1 ; i <= n ; i ++ ) {
            	if ( ( i + (1<<t) - 1 ) > n ) { break ; }
            	for ( j = 1 ; j <= m ; j ++ ) {
                	if ( ( j + (1<<z) - 1 ) > m ) { break ; }
					if ( t != 0 && z == 0 ) {
                    	RMQ[ i ][ j ][ t ][ z ] = RMQ[ i ][ j ][ t - 1 ][ z ] ;
                        RMQ[ i ][ j ][ t ][ z ] = max ( RMQ[ i ][ j ][ t ][ z ] , RMQ[ i + (1<<(t-1)) ][ j ][ t - 1 ][ z ] ) ;
                    }
                    else if ( t == 0 && z != 0 ) {
                    	RMQ[ i ][ j ][ t ][ z ] = RMQ[ i ][ j ][ t ][ z - 1 ] ;
                        RMQ[ i ][ j ][ t ][ z ] = max ( RMQ[ i ][ j ][ t ][ z ] , RMQ[ i ][ j + (1<<(z-1)) ][ t ][ z - 1 ] ) ;
                    }
                    else {
                    	RMQ[ i ][ j ][ t ][ z ] = RMQ[ i ][ j ][ t - 1 ][ z - 1 ] ;
                        RMQ[ i ][ j ][ t ][ z ] = max ( RMQ[ i ][ j ][ t ][ z ] , RMQ[ i + (1<<(t-1)) ][ j ][ t - 1 ][ z ] ) ;
                        RMQ[ i ][ j ][ t ][ z ] = max ( RMQ[ i ][ j ][ t ][ z ] , RMQ[ i ][ j + (1<<(z-1)) ][ t ][ z - 1 ] ) ;
                        RMQ[ i ][ j ][ t ][ z ] = max ( RMQ[ i ][ j ][ t ][ z ] , RMQ[ i + (1<<(t-1)) ][ j + (1<<(z-1)) ][ t - 1 ][ z - 1 ] ) ;                        
                    }
                }
            }
        }
    }
    int br = 0 ;
    int val = 1 ;
    for ( i = 1 ; i <= 1000 ; i ++ ) {
    	while ( 2 * val < i ) {
        	br ++ ;
            val *= 2 ;
        }
        stid[ i ] = br ;
    }
    int q ;
    scanf ( "%d" , &q ) ;
    //cin >> q ;
    while ( q != 0 ) {
    	q -- ;
        scanf ( "%d%d%d%d" , &xx1 , &yy1 , &xx2 , &yy2 ) ;
        //cin >> xx1 >> yy1 >> xx2 >> yy2 ;
        int l , r , mid ;
        l = 0 ;
        r = min ( xx2 - xx1 + 1 , yy2 - yy1 + 1 ) ;
        while ( r - l > 3 ) {
        	int mid = ( l + r ) / 2 ;
			int p , q ;
		    p = xx2 - mid + 1 ;
		    q = yy2 - mid + 1 ;
		    int id1 = stid[ p - xx1 + 1 ] ;
		    int id2 = stid[ q - yy1 + 1 ] ;
		    int len1 = (1<<id1) ;
		    int len2 = (1<<id2) ;
		    short mx = 0 ;
		    mx = max ( mx , RMQ[ xx1 ][ yy1 ][ id1 ][ id2 ] ) ;
		    mx = max ( mx , RMQ[ xx1 ][ q - len2 + 1 ][ id1 ][ id2 ] ) ;
		    mx = max ( mx , RMQ[ p - len1 + 1 ][ yy1 ][ id1 ][ id2 ] ) ;
		    mx = max ( mx , RMQ[ p - len1 + 1 ][ q - len2 + 1 ][ id1 ][ id2 ] ) ;
		    int u = mx ;            
            if ( u >= mid ) { l = mid ; }
            else { r = mid ; }
        }
        while ( 1 ) {
			int p , q ;
		    p = xx2 - r + 1 ;
		    q = yy2 - r + 1 ;
		    int id1 = stid[ p - xx1 + 1 ] ;
		    int id2 = stid[ q - yy1 + 1 ] ;
		    int len1 = (1<<id1) ;
		    int len2 = (1<<id2) ;
		    short mx = 0 ;
		    mx = max ( mx , RMQ[ xx1 ][ yy1 ][ id1 ][ id2 ] ) ;
		    mx = max ( mx , RMQ[ xx1 ][ q - len2 + 1 ][ id1 ][ id2 ] ) ;
		    mx = max ( mx , RMQ[ p - len1 + 1 ][ yy1 ][ id1 ][ id2 ] ) ;
		    mx = max ( mx , RMQ[ p - len1 + 1 ][ q - len2 + 1 ][ id1 ][ id2 ] ) ;
		    int u = mx ;            
            if ( u >= r ) { break ; }
        	r -- ;
        }
        if ( r < 0 ) { r = 0 ; }
        printf ( "%d\n" , r ) ;
        //cout << r << "\n" ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}