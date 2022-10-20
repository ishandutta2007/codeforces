#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 5007
#define MOD 1000000007

int n , k ;
int a[ MAXN ] ;
pair < int , int > aux[ MAXN ] ;

int on_left[ MAXN ] ;
int on_right[ MAXN ] ;

pair < long long , long long > ans ;

vector < int > w[ MAXN ] ;

pair < long long , long long > right_only ( ) {
    long long cnt = 0 ;
    long long pr = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = w[ i ].size ( ) ;
        long long h = 0 ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( on_right[ w[ i ][ j ] ] > 0 ) { ++ h ; }
        }
        if ( h > 0 ) {
            ++ cnt ;
            pr = ( pr * h ) % MOD ;
        }
    }
    return { cnt , pr } ;
}

bool fl = false ;

pair < long long , long long > calc ( int en , int id ) {
    int sz = w[ id ].size ( ) ;
    long long f[ 2 ][ 2 ] ;
    long long nw[ 2 ][ 2 ] ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            f[ i ][ j ] = 0 ;
        }
    }
    f[ 0 ][ 0 ] = 1 ;
    if ( a[ en ] == id ) {
        if ( sz == 0 ) { return { 0 , 0 } ; }
        long long r = 0 ;
        long long ret = 0 ;
        int cnt = 0 ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( on_right[ w[ id ][ i ] ] > en ) { ++ r ; }
        }
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( on_left[ w[ id ][ i ] ] == en ) {
                ++ cnt ;
                ret += r - ( on_right[ w[ id ][ i ] ] > en ) ;
            }
        }
        if ( cnt == 0 ) { return { 0 , 0 } ; }
        if ( ret == 0 ) { return { 1 , cnt } ; }
        return { 2 , ret } ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                nw[ j ][ t ] = f[ j ][ t ] ;
            }
        }
        if ( on_left[ w[ id ][ i ] ] <= en && on_left[ w[ id ][ i ] ] != 0 ) {
            nw[ 1 ][ 1 ] = ( nw[ 1 ][ 1 ] + f[ 0 ][ 1 ] ) % MOD ;
            nw[ 1 ][ 0 ] = ( nw[ 1 ][ 0 ] + f[ 0 ][ 0 ] ) % MOD ;
        }
        if ( on_right[ w[ id ][ i ] ] > en ) {
            nw[ 1 ][ 1 ] = ( nw[ 1 ][ 1 ] + f[ 1 ][ 0 ] ) % MOD ;
            nw[ 0 ][ 1 ] = ( nw[ 0 ][ 1 ] + f[ 0 ][ 0 ] ) % MOD ;
        }
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                f[ j ][ t ] = nw[ j ][ t ] ;
            }
        }
    }
    if ( f[ 1 ][ 1 ] > 0 ) {
        return { 2 , f[ 1 ][ 1 ] } ;
    }
    else if ( f[ 1 ][ 0 ] + f[ 0 ][ 1 ] > 0 ) {
        return { 1 , ( f[ 1 ][ 0 ] + f[ 0 ][ 1 ] ) % MOD } ;
    }
    return { 0 , 1 } ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        scanf ( "%d%d" , &aux[ i ].first , &aux[ i ].second ) ;
        w[ aux[ i ].first ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        int lft = aux[ i ].second ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            lft -= ( a[ j ] == aux[ i ].first ) ;
            if ( lft == 0 ) { on_left[ i ] = j ; break ; }
        }
        lft = aux[ i ].second ;
        for ( int j = n ; j >= 1 ; -- j ) {
            lft -= ( a[ j ] == aux[ i ].first ) ;
            if ( lft == 0 ) { on_right[ i ] = j ; break ; }
        }
    }
}

void solve ( ) {
    ans = right_only ( ) ;
    for ( int en = 1 ; en <= n ; ++ en ) {
        pair < long long , long long > aux ;
        aux.first = 0 , aux.second = 1 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            pair < long long , long long > ret = calc ( en , i ) ;
            aux.first += ret.first ;
            aux.second = ( aux.second * ret.second ) % MOD ;
        }
        if ( aux.second == 0 ) { continue ; }
        if ( ans.first < aux.first ) {
            ans.first = aux.first ;
            ans.second = 0 ;
        }
        if ( ans.first == aux.first ) {
            ans.second += aux.second ;
            if ( ans.second >= MOD ) { ans.second -= MOD ; }
        }
    }
    printf ( "%I64d %I64d\n" , ans.first , ans.second ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}