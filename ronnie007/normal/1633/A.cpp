#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( ( n % 7 ) == 0 ) {
        cout << n << "\n" ;
    }
    else {
        n /= 10 ;
        n *= 10 ;
        while ( ( n % 7 ) != 0 ) {
            ++ n ;
        }
        cout << n << "\n" ; 
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