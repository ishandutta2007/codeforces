#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int prv[ MAXN ] ;

int lst[ MAXN ] ;

struct Tree {
    int br ;
    int IL , IR ;
    Tree *pl , *pr ;
    Tree ( int x , int y ) {
        this->IL = x ;
        this->IR = y ;
        this->br = 0 ;
        this->pl = this->pr = NULL ;
    }
    int getk ( int k ) {
        if ( this->br < k ) { return this->IR + 1 ; }
        if ( this->IL == this->IR ) { return this->IL ; }
        if ( this->pl->br >= k ) { return this->pl->getk ( k ) ; }
        return this->pr->getk ( k - this->pl->br ) ;
    }
};

Tree *root[ MAXN ] ;

void create_full ( Tree * &ret , int l , int r ) {
    ret = new Tree ( l , r ) ;
    if ( l == r ) { return ; }
    int mid = ( l + r ) / 2 ;
    create_full ( ret->pl , l , mid ) ;
    create_full ( ret->pr , mid + 1 , r ) ;
}

Tree* update ( Tree *w , int l , int r , int pos , int val ) {
    if ( pos < l || r < pos ) { return w ; }
    if ( l == r ) {
        Tree *ret = new Tree ( l , r ) ;
        ret->br = val ;
        return ret ;
    }
    int mid = ( l + r ) / 2 ;
    Tree *ret = new Tree ( l , r ) ;
    ret->pl = update ( w->pl , l , mid , pos , val ) ;
    ret->pr = update ( w->pr , mid + 1 , r , pos , val ) ;
    ret->br = ( ret->pl->br + ret->pr->br ) ;
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        prv[ i ] = lst[ a[ i ] ] ;
        lst[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) { lst[ i ] = n + 1 ; }
    create_full ( root[ n + 1 ] , 1 , n ) ;
    for ( i = n ; i >= 1 ; i -- ) {
        int id = lst[ a[ i ] ] ;
        if ( id != ( n + 1 ) ) {
            Tree *aux = update ( root[ i + 1 ] , 1 , n , id , 0 ) ;
            root[ i ] = update ( aux , 1 , n , i , 1 ) ;
        }
        else {
            root[ i ] = update ( root[ i + 1 ] , 1 , n , i , 1 ) ;
        }
        lst[ a[ i ] ] = i ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        int pos = 0 ;
        int ans = 0 ;
        while ( pos < n ) {
            int h = root[ pos + 1 ]->getk ( i + 1 ) - 1 ;
            pos = h ;
            ans ++ ;
        }
        printf ( "%d " , ans ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}