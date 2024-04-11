#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , m ;
int x , y , d ;

void solve ( ) {
    cin >> n >> m ;
    cin >> x >> y >> d ;
    if ( x - d <= 1 && y - d <= 1 ) {
        cout << "-1\n" ;
        return ;
    }
    if ( x + d >= n && y + d >= m ) {
        cout << "-1\n" ;
        return ;
    }
    if ( y - d <= 1 && y + d >= m ) {
        cout << "-1\n" ;
        return ;
    }
    if ( x - d <= 1 && x + d >= n ) {
        cout << "-1\n" ;
        return ;
    }
    cout << n - 1 + m - 1 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}