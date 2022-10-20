#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

int n ;
string a ;

int f[ 2 ] ;
int w[ 2 ] ;

void input ( ) {
     cin >> a ;
     n = a.size ( ) ;
}


void solve ( ) {
    f[ 0 ] = f[ 1 ] = 0 ;
    w[ 0 ] = w[ 1 ] = 0 ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        if ( a[ i ] == '0' ) {
            ++ f[ 0 ] ;
            f[ 0 ] = max ( f[ 0 ] , 1 + f[ 1 ] ) ;
            ++ w[ 0 ] ;
            w[ 0 ] = max ( w[ 0 ] , 1 + w[ 1 ] ) ;
        }
        else {
            int mx = 1 + max ( w[ 0 ] , w[ 1 ] ) ;
            ++ f[ 1 ] ;
            if ( mx > max ( f[ 0 ] , f[ 1 ] ) ) {
                ++ w[ 1 ] ;
            }
            else {
                w[ 0 ] = mx ;
                a[ i ] = '0' ;
            }
        }
    }
    cout << a << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}