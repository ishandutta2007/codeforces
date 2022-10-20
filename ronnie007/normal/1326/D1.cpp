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
#include<random>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int ans = 0 ;
    int pos = 0 ;
    int type = 0 ;
    string sv ;
    
    for ( int i = 1 ; i <= n ; ++ i ) {
        int l = 1 ;
        int r = n ;
        while ( l < i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        r = i + ( i - l ) ;
        if ( r > n ) { r = n ; }        
        while ( l < i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        if ( l == i && r == i ) {
            if ( 2 * ( i - 1 ) + 1 <= n && ans < 2 * ( i - 1 ) + 1 ) {
                ans = 2 * ( i - 1 ) + 1 ;
                pos = i ;
                type = 0 ;
            }
        }


        l = 1 ;
        r = n ;
        while ( l <= i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        r = i + 1 + ( i - l ) ;
        if ( r > n ) { r = n ; }
        while ( l <= i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        if ( l == i + 1 ) {
            if ( 2 * i <= n && ans < 2 * i ) {
                ans = 2 * i ;
                pos = i ;
                type = 1 ;
            }
        }
    }


    for ( int i = n ; i >= 1 ; -- i ) {
        int l = 1 ;
        int r = n ;
        while ( r > i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        l = i - ( r - i ) ;
        if ( l < 1 ) { l = 1 ; }
        while ( r > i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        if ( l == i && r == i ) {
            if ( 2 * ( n - i ) + 1 <= n && ans < 2 * ( n - i ) + 1 ) {
                ans = 2 * ( n - i ) + 1 ;
                pos = i ;
                type = 2 ;
            }
        }


        l = 1 ;
        r = n ;
        while ( r >= i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        l = i - 1 - ( r - i ) ;
        if ( l < 1 ) { l = 1 ; }        
        while ( r >= i && a[ l - 1 ] == a[ r - 1 ] ) {
            ++ l ; -- r ;
        }
        if ( r == i - 1 ) {
            if ( 2 * ( n - i + 1 ) <= n && ans < 2 * ( n - i + 1 ) ) {
                ans = 2 * ( n - i + 1 ) ;
                pos = i ;
                type = 3 ;
            }
        }        
    }
    if ( type <= 1 ) {
        for ( int i = 1 ; i <= pos ; ++ i ) {
            cout << a[ i - 1 ] ;
        }
        if ( type == 0 ) {
            for ( int i = pos - 1 ; i >= 1 ; -- i ) {
                cout << a[ i - 1 ] ;
            }
        }
        else {
            for ( int i = pos ; i >= 1 ; -- i ) {
                cout << a[ i - 1 ] ;
            }
        }
        cout << "\n" ;
    }
    else {
        for ( int i = n ; i >= pos ; -- i ) {
            cout << a[ i - 1 ] ;
        }
        if ( type == 2 ) {
            for ( int i = pos + 1 ; i <= n ; ++ i ) {
                cout << a[ i - 1 ] ;
            }
        }
        else {
            for ( int i = pos ; i <= n ; ++ i ) {
                cout << a[ i - 1 ] ;
            }
        }
        cout << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}