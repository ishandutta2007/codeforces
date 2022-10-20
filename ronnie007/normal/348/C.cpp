#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAGIC 400

int n , m , q ;
long long a[ MAXN ] ;

int len[ MAXN ] ;
vector < int > v[ MAXN ] ;

int f[ MAXN ][ MAGIC + 2 ] ;

int cnt_heavy ;
vector < int > heavy ;
bool is_heavy[ MAXN ] ;

long long init_sm[ MAXN ] ;
long long to_heavy[ MAGIC + 2 ] ;
long long from_heavy[ MAGIC + 2 ] ;
int rv[ MAXN ] ;

bool used[ MAXN ] ;

void calc_f ( ) {
    for ( int i = 0 ; i < cnt_heavy ; ++ i ) {
        for ( int j = 0 ; j < len[ heavy[ i ] ] ; ++ j ) {
            used[ v[ heavy[ i ] ][ j ] ] = true ;
        }
        for ( int j = 1 ; j <= m ; ++ j ) {
            int cnt = 0 ;
            for ( int t = 0 ; t < len[ j ] ; ++ t ) {
                cnt += used[ v[ j ][ t ] ] ;
            }
            f[ j ][ i ] = cnt ;
        }
        for ( int j = 0 ; j < len[ heavy[ i ] ] ; ++ j ) {
            used[ v[ heavy[ i ] ][ j ] ] = false ;
        }
    }
}

void input ( ) {
    cin >> n >> m >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> len[ i ] ;
        v[ i ].resize ( len[ i ] ) ;
        for ( int j = 0 ; j < len[ i ] ; ++ j ) {
            cin >> v[ i ][ j ] ;
            init_sm[ i ] += a[ v[ i ][ j ] ] ;
        }
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
        is_heavy[ i ] = ( len[ i ] >= MAGIC ) ;
        if ( is_heavy[ i ] == true ) {
            heavy.push_back ( i ) ;
            rv[ i ] = heavy.size ( ) - 1 ;
        }
    }
    cnt_heavy = heavy.size ( ) ;
    calc_f ( ) ;
}

void solve ( ) {
    char c ;
    int id , x ;
    while ( q -- ) {
        cin >> c ;
        if ( c == '+' ) {
            cin >> id >> x ;
            if ( is_heavy[ id ] == false ) {
                for ( int i = 0 ; i < len[ id ] ; ++ i ) {
                    a[ v[ id ][ i ] ] += x ;
                }
                for ( int i = 0 ; i < cnt_heavy ; ++ i ) {
                    to_heavy[ i ] += 1LL * x * f[ id ][ i ] ;
                }
            }
            else {
                from_heavy[ rv[ id ] ] += x ;
            }
        }
        else {
            cin >> id ;
            long long ans = 0 ;
            if ( is_heavy[ id ] == false ) {
                for ( int i = 0 ; i < len[ id ] ; ++ i ) {
                    ans += a[ v[ id ][ i ] ] ;
                }
                for ( int i = 0 ; i < cnt_heavy ; ++ i ) {
                    ans += 1LL * from_heavy[ i ] * f[ id ][ i ] ;
                }
            }
            else {
                ans = init_sm[ id ] + to_heavy[ rv[ id ] ] ;
                for ( int i = 0 ; i < cnt_heavy ; ++ i ) {
                    ans += 1LL * from_heavy[ i ] * f[ id ][ i ] ;
                }
            }
            cout << ans << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}