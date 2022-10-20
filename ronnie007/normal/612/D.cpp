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

#define inf 1000000007

int n , k ;
vector < pair < int , int > > v ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d%d" , &x , &y ) ;
        v.push_back ( make_pair ( x , -1 ) ) ;
        v.push_back ( make_pair ( y , 1 ) ) ;
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
}

void solve ( ) {
	int i ;
    int lst = -inf ;
    int br = 0 ;
    vector < pair < int , int > > ans ;
    for ( i = 0 ; i < 2 * n ; i ++ ) {
    	br -= v[ i ].second ;
        if ( br >= k && lst == -inf ) { lst = v[ i ].first ; }
        if ( br < k && lst != -inf ) {
        	ans.push_back ( make_pair ( lst , v[ i ].first ) ) ;
            lst = -inf ;
        }
    }
    int sz = ans.size ( ) ;
    cout << sz << "\n" ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	cout << ans[ i ].first << " " << ans[ i ].second << "\n" ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}