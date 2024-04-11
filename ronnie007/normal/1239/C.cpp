#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n , p ;
int a[ MAXN ] ;
long long ans[ MAXN ] ;

pair < int , int > srt[ MAXN ] ;
bool fl[ MAXN ] ;

queue < int > q ;
priority_queue < int > pq ;

void input ( ) {
    scanf ( "%d%d" , &n , &p ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        srt[ i ] = { a[ i ] , i } ;
    }
    sort ( srt + 1 , srt + n + 1 ) ;
}

void solve ( ) {
    for ( int stpos = 1 ; stpos <= n ; ++ stpos ) {
        if ( fl[ srt[ stpos ].second ] == true ) { continue ; }
        long long aux = srt[ stpos ].first ;
        q.push ( srt[ stpos ].second ) ;
        pq.push ( - srt[ stpos ].second ) ;
        int pos = stpos ;
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            aux += p ;
            ans[ x ] = aux , fl[ x ] = true ;
            while ( pos < n && srt[ pos + 1 ].first <= aux ) {
                pq.push ( - srt[ pos + 1 ].second ) ;
                if ( - srt[ pos + 1 ].second == pq.top ( ) ) { q.push ( srt[ pos + 1 ].second ) ; }
                ++ pos ;
            }
            if ( -pq.top ( ) == x ) {
                while ( pq.empty ( ) == false && fl[ - pq.top ( ) ] == true ) { pq.pop ( ) ; }
                if ( pq.empty ( ) == false ) { q.push ( - pq.top ( ) ) ; }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%I64d " , ans[ i ] ) ;
    }

}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}