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

#define MAXN 500007

int n , k ;
int a[ MAXN ] ;
int br[ 2 * MAXN ] ;

int cur ;

void add ( int x ) {
	br[ x ] ++ ;
    if ( br[ x ] == 1 ) { cur ++ ; }
}

void del ( int x ) {
	br[ x ] -- ;
    if ( br[ x ] == 0 ) { cur -- ; }
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int i , j ;
    j = 1 ;
    add ( a[ 1 ] ) ;
    int ans1 , ans2 ;
    ans1 = ans2 = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	while ( j <= n && cur <= k ) {
        	j ++ ;
            add ( a[ j ] ) ;
        }
        del ( a[ j ] ) ;
        j -- ;
        if ( ( ans2 - ans1 + 1 ) <= ( j - i + 1 ) ) {
        	ans1 = i ;
            ans2 = j ;
        }
        del ( a[ i ] ) ;
    }
    printf ( "%d %d\n" , ans1 , ans2 ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}