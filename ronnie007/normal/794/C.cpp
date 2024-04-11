#include<bits/stdc++.h>
using namespace std ;

int n ;
int len1 , len2 ;
string a , b ;

string ans ;

void input ( ) {
    cin >> a >> b ;
    n = a.size ( ) ;
    len1 = ( n + 1 ) / 2 ;
    len2 = n - len1 ;
    sort ( a.begin ( ) , a.end ( ) ) ;
    sort ( b.begin ( ) , b.end ( ) , greater < char > ( ) ) ;
    a.resize ( len1 ) ;
    b.resize ( len2 ) ;
}

void solve ( ) {
    ans.resize ( n ) ;
    int pos0 , pos1 ;
    pos0 = 0 ; pos1 = n - 1 ;
    int l0 , r0 ;
    int l1 , r1 ;
    l0 = 0 ; r0 = len1 - 1 ;
    l1 = 0 ; r1 = len2 - 1 ;
    int turn = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( turn == 0 ) {
            if ( b[ l1 ] > a[ l0 ] ) {
                ans[ pos0 ++ ] = a[ l0 ++ ] ;
            }
            else {
                ans[ pos1 -- ] = a[ r0 -- ] ;
            }
        }
        else {
            if ( b[ l1 ] > a[ l0 ] ) {
                ans[ pos0 ++ ] = b[ l1 ++ ] ;
            }
            else {
                ans[ pos1 -- ] = b[ r1 -- ] ; 
            }
        }
        turn ^= 1 ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}