#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#define LOG 20


int n , m ;
int prv[ MAXN ] ;
int root ;
vector < int > tree[ MAXN ] ;
vector < int > total[ MAXN ] ;
vector < int > v[ MAXN ] ;

int out_deg[ MAXN ] ;
int in_deg[ MAXN ] ;


vector < int > chain[ MAXN ] ;
vector < int > chain_dag[ MAXN ] ;
int id_chain[ MAXN ] ;


int tpsz ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int used[ MAXN ] ;

vector < int > ord ;

void init_tree ( int vertex ) {
    st[ vertex ] = ++ tpsz ;
    for ( auto x : tree[ vertex ] ) {
        init_tree ( x ) ;
    }
    en[ vertex ] = tpsz ;
}

bool is_parent ( int x , int y ) {
    return ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> prv[ i ] ;
        if ( prv[ i ] == 0 ) {
            root = i ;
        }
        else {
            tree[ prv[ i ] ].push_back ( i ) ;
            total[ prv[ i ] ].push_back ( i ) ;
        }
    }
}

bool dfs ( int vertex ) {
    used[ vertex ] = 2 ;
    for ( auto x : total[ vertex ] ) {
        if ( used[ x ] == 0 ) {
            bool ret = dfs ( x ) ;
            if ( ret == false ) { return false ; }
        }
        else if ( used[ x ] == 2 ) { return false ; }
    }
    used[ vertex ] = 1 ;
    return true ;
}

void topsort ( int vertex ) {
    used[ vertex ] = 1 ;
    for ( auto x : chain_dag[ vertex ] ) {
        if ( used[ x ] == 0 ) {
            topsort ( x ) ;
        }
    }
    ord.push_back ( vertex ) ;
}

void solve ( ) {
    init_tree ( root ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        total[ x ].push_back ( y ) ;
        ++ out_deg[ x ] ;
        ++ in_deg[ y ] ;
        if ( out_deg[ x ] > 1 ) {
            cout << "0\n" ;
            return ;
        }
        if ( is_parent ( y , x ) == true ) {
            cout << "0\n" ;
            return ;
        }
        if ( is_parent ( x , y ) == true && prv[ y ] != x ) {
            cout << "0\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            bool ret = dfs ( i ) ;
            if ( ret == false ) {
                cout << "0\n" ;
                return ;
            }
        }
    }
    int mx_id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( in_deg[ i ] == 0 ) {
            ++ mx_id ;
            int aux = i ;
            while ( 1 ) {
                chain[ mx_id ].push_back ( aux ) ;
                id_chain[ aux ] = mx_id ;
                if ( v[ aux ].size ( ) == 0 ) { break ; }
                aux = v[ aux ][ 0 ] ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = 0 ;
        for ( auto x : tree[ i ] ) {
            chain_dag[ id_chain[ i ] ].push_back ( id_chain[ x ] ) ;
        }
    }
    topsort ( id_chain[ root ] ) ;
    int sz = ord.size ( ) ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        int len = chain[ ord[ i ] ].size ( ) ;
        for ( int j = 0 ; j < len ; ++ j ) {
            cout << chain[ ord[ i ] ][ j ] << " " ;
        }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}