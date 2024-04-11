#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1000007 ;

int n , m ;
vector < int > v[ MAXN ] ;
vector < int > rv[ MAXN ] ;
int used[ MAXN ] , comp[ MAXN ] ;
stack < int > st ;

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == 0 ) {
            dfs ( x ) ;
        }
    }
    st.push ( vertex ) ;
}

void rev_dfs ( int vertex , int col ) {
    comp[ vertex ] = col ;
    for ( auto x : rv[ vertex ] ) {
        if ( comp[ x ] == 0 ) {
            rev_dfs ( x , col ) ;
        }
    }
}

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = comp[ i ] = 0 ;
        v[ i ].clear ( ) ; rv[ i ].clear ( ) ;
    }
    for ( int i = 1 , x , y ; i <= m ; ++ i ) {
        cin >> x >> y ;
        if ( x != y ) {
            v[ x ].push_back ( y ) ;
            rv[ y ].push_back ( x ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            dfs ( i ) ;
        }
    }
    int tp = 0 ;
    while ( st.empty ( ) == false ) {
        int x = st.top ( ) ;
        st.pop ( ) ;
        if ( comp[ x ] > 0 ) { continue ; }
        rev_dfs ( x , ++ tp ) ;
    }
    if ( tp == 1 ) {
        cout << "No\n" ;
        return ;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt += ( comp[ i ] == 1 ) ;
    }
    cout << "Yes\n" ;
    cout << n - cnt << " " << cnt << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( comp[ i ] != 1 ) { cout << i << " " ; }
    }
    cout << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( comp[ i ] == 1 ) { cout << i << " " ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}