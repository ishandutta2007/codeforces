#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int n , a , b ;
string s ;
vector < int > v ;

void solve ( ) {
    cin >> a >> b ;
    cin >> s ;
    n = s.size ( ) ;
    int cons = 0 ;
    v.clear ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( s[ i ] == '.' ) { ++ cons ; }
        else {
            if ( cons > 0 ) { v.push_back ( cons ) ; }
            cons = 0 ;
        }
    }
    if ( cons > 0 ) { v.push_back ( cons ) ; }
    bool bad = false ;
    int init = 0 , split = 0 , splitlen ;
    for ( auto x : v ) {
        if ( b <= x && x < a ) { bad = true ; break ; }
        if ( a <= x && x < 2 * b ) { ++ init ; }
        if ( 2 * b <= x ) { ++ split ; splitlen = x ; }
    }
    if ( bad == true || split >= 2 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( split == 0 ) {
        if ( ( init % 2 ) == 1 ) {
            cout << "YES\n" ;
            return ;
        }
        cout << "NO\n" ;
        return ;
    }
    for ( int lft = 0 ; lft + a <= splitlen ; ++ lft ) {
        int oth = splitlen - lft - a ;
        if ( ( b <= lft && lft < a ) || lft >= 2 * b ) { continue ; }
        if ( ( b <= oth && oth < a ) || oth >= 2 * b ) { continue ; }
        int aux = init ;
        if ( a <= lft && lft < 2 * b ) { ++ aux ; }
        if ( a <= oth && oth < 2 * b ) { ++ aux ; }
        if ( ( aux % 2 ) == 0 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}