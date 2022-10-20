#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
using namespace std ;

#define MAXK 17
#define MAXN 5007

long long k ;
int n[ MAXN ] ;
int a[ MAXK ][ MAXN ] ;
long long init[ MAXK ] ;
long long sm = 0 ;

map < long long , pair < int , int > > ZX ;


pair < int , pair < int , int > > dp[ (1<<MAXK) ] ;
vector < pair < int , int > > fnl ;
bool pos[ (1<<MAXK) ] ;


vector < pair < int , int > > lst_call ;
long long nwmask ;

pair < int , int > format[ MAXN ] ;

bool vis[ MAXK ][ MAXN ] ;


bool sim ( int mask , int st , int val , bool fl ) {
    int hh = val ;
    int aux = st ;
    nwmask = mask ;
    lst_call.clear ( ) ;
    while ( 1 ) {
        nwmask |= ( 1 << ( aux - 1 ) ) ;
        vis[ aux ][ ZX[ val ].second ] = true ;
        long long diff = sm - ( init[ aux ] - val ) ;
        if ( ZX.find ( diff ) == ZX.end ( ) ) { return false ; }
        pair < int , int > ret = ZX[ diff ] ;
        if ( ret.first != st && ( nwmask & ( 1 << ( ret.first - 1 ) ) ) != 0 ) { return false ; }
        if ( ret.first == st && diff != hh ) { return false ; }
        if ( fl == true ) {
            lst_call.push_back ( { val , diff } ) ;
        }
        val = diff ;
        aux = ret.first ;
        if ( ret.first == st ) { break ; }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d" , &k ) ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        scanf ( "%d" , &n[ i ] ) ;
        for ( int j = 1 ; j <= n[ i ] ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            ZX[ a[ i ][ j ] ] = { i , j } ;
            sm += a[ i ][ j ] ;
            init[ i ] += a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    if ( ( sm % k ) != 0 ) { printf ( "No\n" ) ; return ; }
    sm /= k ;
    for ( int i = 1 ; i <= (1<<k) ; ++ i ) { pos[ i ] = false ; }

    pos[ 0 ] = true ;
    for ( int i = 0 ; i < (1<<k) - 1 ; ++ i ) {
        if ( pos[ i ] == false ) { continue ; }
        for ( int j = 1 ; j <= k ; ++ j ) {
            if ( ( i & ( 1 << ( j - 1 ) ) ) != 0 ) { continue ; }
            for ( int t = 1 ; t <= n[ j ] ; ++ t ) {
                ///if ( vis[ j ][ t ] == true ) { continue ; }
                bool ret = sim ( i , j , a[ j ][ t ] , false ) ;
                if ( ret == true && pos[ nwmask ] == false ) {
                    pos[ nwmask ] = true ;
                    dp[ nwmask ] = { i , { j , a[ j ][ t ] } } ;
                }
            }
            break ;
        }
        /**
        for ( int j = 1 ; j <= k ; ++ j ) {
            for ( int t = 1 ; t <= n[ j ] ; ++ t ) {
                vis[ j ][ t ] = false ;
            }
        }
        **/
    }
    if ( pos[ (1<<k) - 1 ] == false ) { printf ( "No\n" ) ; return ; }
    int lst_mask = (1<<k) - 1 ;
    while ( lst_mask > 0 ) {
        sim ( dp[ lst_mask ].first , dp[ lst_mask ].second.first , dp[ lst_mask ].second.second , true ) ;
        lst_mask = dp[ lst_mask ].first ;
        while ( lst_call.empty ( ) == false ) {
            fnl.push_back ( lst_call.back ( ) ) ;
            lst_call.pop_back ( ) ;
        }
    }
    printf ( "Yes\n" ) ;
    int sz = fnl.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        pair < int , int > ret1 = ZX[ fnl[ i ].second ] ;
        pair < int , int > ret2 = ZX[ fnl[ i ].first ] ;
        format[ ret1.first ] = { fnl[ i ].second , ret2.first } ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        printf ( "%d %d\n" , format[ i ].first , format[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
/**
15
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
**/