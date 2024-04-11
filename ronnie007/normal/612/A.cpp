#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n , p , q ;
string a ;

void input ( ) {
	cin >> n >> p >> q ;
    cin >> a ;
}

void solve ( ) {
	int i , j , t ;
    for ( i = 0 ; i <= n ; i ++ ) {
    	if ( i * p > n ) { break ; }
    	if ( ( ( n - i * p ) % q ) == 0 ) {
        	int br1 = i ;
            int br2 = ( ( n - i * p ) / q ) ;
            cout << br1 + br2 << "\n" ;
            j = 0 ;
            while ( br1 != 0 ) {
            	for ( t = 0 ; t < p ; t ++ ) {
                	cout << a[ j + t ] ;
                }
                cout << "\n" ;
                j += p ;
                br1 -- ;
            }
            while ( br2 != 0 ) {
            	for ( t = 0 ; t < q ; t ++ ) {
                	cout << a[ j + t ] ;
                }
                cout << "\n" ;
                j += q ;
                br2 -- ;
            }
            return ;
        }
    }
    cout << "-1\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}