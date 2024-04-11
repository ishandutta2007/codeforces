#include<bits/stdc++.h>
using namespace std ;

#define MAXN 50007

int n ;
string a ;
priority_queue < pair < int , int > > q ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int cnt = 0 ;
    bool fl = false ;
    long long ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '(' ) { ++ cnt ; }
        else if ( a[ i ] == ')' ) {
            -- cnt ;
            if ( cnt < 0 && q.empty ( ) == true ) { fl = true ; }
            else if ( cnt < 0 ) {
                pair < int , int > aux = q.top ( ) ;
                q.pop ( ) ;
                ans -= aux.first ;
                a[ aux.second ] = '(' ;
                cnt += 2 ;
            }
        }
        else {
            a[ i ] = ')' ;
            -- cnt ;
            int x , y ;
            cin >> x >> y ;
            ans += y ;
            q.push ( { y - x , i } ) ;
            if ( cnt < 0 ) {
                pair < int , int > aux = q.top ( ) ;
                q.pop ( ) ;
                ans -= aux.first ;
                a[ aux.second ] = '(' ;
                cnt += 2 ;
            }
        }
    }
    while ( cnt > 0 && q.empty ( ) == false ) {
        pair < int , int > aux = q.top ( ) ;
        q.pop ( ) ;
        ans -= aux.first ;
        a[ aux.second ] = '(' ;
        cnt += 2 ;
    }
    if ( fl == true || cnt != 0 ) { cout << "-1\n" ; }
    else {
        cout << ans << "\n" ;
        cout << a << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}