#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

#define MAXN 2007

int n ;
pair < int , int > a[ MAXN ] ;

struct tuhla {
	int first ;
	int second ;
	int third ;
};

vector < struct tuhla > v ;

int gcd ( int x , int y ) {
	if ( y == 0 ) { return x ; }
	return ( gcd ( y , x % y ) ) ;
}

bool f ( struct tuhla p1 , struct tuhla p2 ) {
	if ( p1.first != p2.first ) { return ( p1.first < p2.first ) ; }
	if ( p1.second != p2.second ) { return ( p1.second < p2.second ) ; }
	return ( p1.third < p2.third ) ;
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
	sort ( a , a + n ) ;
}
 
void solve ( )  {
	int i , j ;
	int x , y ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i + 1 ; j < n ; j ++ ) {
			x = ( a[ j ].second - a[ i ].second ) ;
			y = ( a[ i ].first - a[ j ].first ) ;
			int u = gcd ( abs ( x ) , abs ( y ) ) ;
			x /= u ;
			y /= u ;
			struct tuhla q ;
			q.first = x ;
			q.second = y ;
			q.third = 0 - x * a[ i ].first - y * a[ i ].second ;
			v.push_back ( q ) ;
        }
    }
	sort ( v.begin ( ) , v.end ( ) , f ) ;
	long long tot ;
	tot = n ;
	tot *= ( n - 1 ) ;
	tot *= ( n - 2 ) ;
	tot /= 6 ;
	long long br = 1 ;
	int sz = v.size ( ) ;
	for ( i = 1 ; i < sz ; i ++ ) {
		if ( v[ i ].first == v[ i - 1 ].first && v[ i ].second == v[ i - 1 ].second && v[ i ].third == v[ i - 1 ].third ) {
			br ++ ;
        }
		else {
			long long l , r , mid ;
			l = 0 ;
			r = n ;
			while ( r - l > 7 ) {
				mid = ( l + r ) / 2 ;
				if ( mid * ( mid - 1 ) / 2 <= br ) { l = mid ; }
				else { r = mid ; }
            }
			for ( mid = l ; mid <= r ; mid ++ ) {
				if ( mid * ( mid - 1 ) / 2 == br ) { break ; }
            }
			tot -= ( mid * ( mid - 1 ) * ( mid - 2 ) / 6 ) ;
			//tot -= ( ( br + 1 ) * br * ( br - 1 ) / 6 ) ;
			br = 1 ;
        }
    }
	if ( br != 0 ) {
		long long l , r , mid ;
		l = 0 ;
		r = n ;
		while ( r - l > 7 ) {
			mid = ( l + r ) / 2 ;
			if ( mid * ( mid - 1 ) / 2 <= br ) { l = mid ; }
			else { r = mid ; }
		}
		for ( mid = l ; mid <= r ; mid ++ ) {
			if ( mid * ( mid - 1 ) / 2 == br ) { break ; }
		}
		tot -= ( mid * ( mid - 1 ) * ( mid - 2 ) / 6 ) ;
		//tot -= ( ( br + 1 ) * br * ( br - 1 ) / 6 ) ;
		br = 1 ;
    }
	printf ( "%I64d\n" , tot ) ;
}