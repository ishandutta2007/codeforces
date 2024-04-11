#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std ;

#define MAXN 50007

int n ;

struct tuhla {
    int x , y , z ;
    int id ;
};
tuhla a[ MAXN ] ;
vector < pair < int , int > > v ;

bool cmp ( tuhla p1 , tuhla p2 ) {
    if ( p1.z != p2.z ) { return p1.z < p2.z ; }
    if ( p1.y != p2.y ) { return p1.y < p2.y ; }
    return p1.x < p2.x ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].z ) ;
        a[ i ].id = i ;
    }
    sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
    stack < int > st ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( st.empty ( ) == true ) { st.push ( i ) ; }
        else {
            if ( a[ st.top ( ) ].z == a[ i ].z && a[ st.top ( ) ].x <= a[ i ].x && a[ st.top ( ) ].y <= a[ i ].y ) {
                v.push_back ( { a[ st.top ( ) ].id , a[ i ].id } ) ;
                st.pop ( ) ;
            }
            else {
                st.push ( i ) ;
            }
        }
    }
    int lst = -1 ;
    while ( st.empty ( ) == false ) {
        int aux1 = st.top ( ) ;
        st.pop ( ) ;
        if ( st.empty ( ) == true ) {
            v.push_back ( { a[ lst ].id , a[ aux1 ].id } ) ;
            break ;
        }
        int aux2 = st.top ( ) ;
        st.pop ( ) ;
        if ( a[ aux1 ].z == a[ aux2 ].z ) {
            v.push_back ( { a[ aux1 ].id , a[ aux2 ].id } ) ;
        }
        else {
            st.push ( aux2 ) ;
            if ( lst == -1 ) { lst = aux1 ; }
            else { v.push_back ( { a[ lst ].id , a[ aux1 ].id } ) , lst = -1 ; }
        }
    }
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}