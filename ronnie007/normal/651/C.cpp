#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;

map < pair < int , int > , int > ZX1 ;
map < int , int > ZX2 ;
map < int , int > ZX3 ;

long long ans = 0 ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        ans += ZX2[ a[ i ].first ] ;
        ans += ZX3[ a[ i ].second ] ;
        ans -= ZX1[ a[ i ] ] ;
        ZX2[ a[ i ].first ] ++ ;
        ZX3[ a[ i ].second ] ++ ;
        ZX1[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
	printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}