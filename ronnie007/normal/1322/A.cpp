#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int ans = 0 ;
    int aux = 0 ;
    int lst = -1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == ')' ) {
            -- aux ;
            if ( aux == 0 ) {
                lst = i ;
            }
        }
        else {
            ++ aux ;
            if ( aux == 0 ) {
                ans += ( i - lst ) ;
                lst = i ;
            }
        }
    }
    if ( aux != 0 ) { cout << "-1\n" ; }
    else { cout << ans << "\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}