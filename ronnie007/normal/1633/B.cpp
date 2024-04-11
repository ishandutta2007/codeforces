#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int x = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        x += ( a[ i ] == '0' ) ;
    }
    int y = n - x ;
    if ( x != y ) {
        cout << min ( x , y ) << "\n" ;
    }
    else {
        cout << x - 1 << "\n" ;
    }
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}