#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 1000007

int n , k ;
int a[ MAXN ] ;

int pref[ MAXN ] ;

struct tuhla {
	int l , r ;
    int val ;
};
vector < struct tuhla > v ;
struct tuhla w ;
string parse ( int x ) {
	int i ;
    string ret ;
    ret.clear ( ) ;
    for ( i = 30 ; i >= 0 ; i -- ) {
    	int u = (1<<i) ;
       	int b = 0 ;
        if ( (u&x) != 0 ) { b = 1 ; }
        ret += char ( b + '0' ) ; 
    }
    return ret ;
}
void add ( string s ) {
	int i ;
    int pos = 1 ;
    for ( i = 0 ; i <= 30 ; i ++ ) {
    	v[ pos ].val ++ ;
        if ( s[ i ] == '0' ) {
        	if ( v[ pos ].l == 0 ) {
            	v.push_back ( w ) ;
                v[ pos ].l = v.size ( ) - 1 ;
            }
            pos = v[ pos ].l ;
        }
        else {
        	if ( v[ pos ].r == 0 ) {
            	v.push_back ( w ) ;
                v[ pos ].r = v.size ( ) - 1 ;
            }
            pos = v[ pos ].r ;
        }
    }
    v[ pos ].val ++ ;
}
int query ( string s ) {
	int i ;
    int pos = 1 ;
    int ret = 0 ;
    int sm = 0 ;
    for ( i = 0 ; i <= 30 ; i ++ ) {
		int u = (1<<(30-i)) ;
        if ( ( sm + u ) < k ) {
        	sm += u ;
            if ( s[ i ] == '1' ) {
        		if ( v[ pos ].l == 0 ) {
					return ret ;                
    	        }
        	    pos = v[ pos ].l ;            
           }
           else {
				if ( v[ pos ].r == 0 ) {
					return ret ;                
    	        }
	            pos = v[ pos ].r ;           
           }
        }
        else {
            if ( s[ i ] == '0' ) {
				ret += v[ v[ pos ].r ].val ;
        		if ( v[ pos ].l == 0 ) {
					return ret ;
    	        }                
                pos = v[ pos ].l ;
           }
           else {
                ret += v[ v[ pos ].l ].val ;
				if ( v[ pos ].r == 0 ) {
					return ret ;
    	        }                
	            pos = v[ pos ].r ;           
           }        	
        }
    }
   	return ret ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
		pref[ i ] = ( pref[ i - 1 ] ^ a[ i ] ) ;
    }
}

void solve ( ) {
	v.resize ( 2 ) ;
	int i ;
    long long ans = 0 ;
    string init ;
    for ( i = 0 ; i <= 30 ; i ++ ) { init += '0' ; }
    add ( init ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
    	string cur = parse ( pref[ i ] ) ;
        ans += query ( cur ) ;
        add ( cur ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}