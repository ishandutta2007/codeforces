#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std ;

int n ;
int xx1 , yy1 , xx2 , yy2 ;
int ans1 , ans2 , ans3 , ans4 ;

int check ( int p1 , int q1 , int p2 , int q2 ) {
	if ( p1 <= ans1 && ans3 <= p2 ) {
    	if ( q1 <= ans2 && ans4 <= q2 ) {
        	return 1 ;
        }
    }
    return 0 ;
}

void shrink_right ( ) {
	int l , r , mid ;
    int u ;
    l = xx1 ;
    r = n ;
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        printf ( "? %d %d %d %d\n" , xx1 , yy1 , mid , yy2 ) ;
        fflush ( stdout ) ;
		scanf ( "%d" , &u ) ;
        u -= check ( xx1 , yy1 , mid , yy2 ) ;
        if ( u > 0 ) { r = mid ; }
        else { l = mid ; }
    }
    while ( 1 ) {
        printf ( "? %d %d %d %d\n" , xx1 , yy1 , l , yy2 ) ;
        fflush ( stdout ) ;
		scanf ( "%d" , &u ) ;
        u -= check ( xx1 , yy1 , l , yy2 ) ;
        if ( u == 0 ) { l ++ ; }
        else { break ; }
    }
    xx2 = l ;
}
void shrink_left ( ) {
	int l , r , mid ;
    int u ;
    l = 1 ;
    r = xx2 ;
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        printf ( "? %d %d %d %d\n" , mid , yy1 , xx2 , yy2 ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &u ) ;
        u -= check ( mid , yy1 , xx2 , yy2 ) ;
        if ( u > 0 ) { l = mid ; }
        else { r = mid ; }
    }
    while ( 1 ) {
        printf ( "? %d %d %d %d\n" , r , yy1 , xx2 , yy2 ) ;
        fflush ( stdout ) ;
		scanf ( "%d" , &u ) ;
        u -= check ( r , yy1 , xx2 , yy2 ) ;
        if ( u == 0 ) { r -- ; }
        else { break ; }
    }
    xx1 = r ;    
}
void shrink_top ( ) {
	int l , r , mid ;
    int u ;
    l = yy1 ;
    r = n ;
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        printf ( "? %d %d %d %d\n" , xx1 , yy1 , xx2 , mid ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &u ) ;
        u -= check ( xx1 , yy1 , xx2 , mid ) ;
        if ( u > 0 ) { r = mid ; }
        else { l = mid ; }
    }
    while ( 1 ) {
    	printf ( "? %d %d %d %d\n" , xx1 , yy1 , xx2 , l ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &u ) ;
        u -= check ( xx1 , yy1 , xx2 , l ) ;
        if ( u == 0 ) { l ++ ; }
        else { break ; }
    }
    yy2 = l ;
}

void shrink_bottom ( ) {
	int l , r , mid ;
    int u ;
   	l = 1 ;
    r = yy2 ;
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        printf ( "? %d %d %d %d\n" , xx1 , mid , xx2 , yy2 ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &u ) ;
        u -= check ( xx1 , mid , xx2 , yy2 ) ;
        if ( u > 0 ) { l = mid ; }
        else { r = mid ; }
    }
    while ( 1 ) {
    	printf ( "? %d %d %d %d\n" , xx1 , r , xx2 , yy2 ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &u ) ;
        u -= check ( xx1 , r , xx2 , yy2 ) ;
        if ( u == 0 ) { r -- ; }
        else { break ; }
    }
    yy1 = r ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
    xx1 = 1 ;
    yy1 = 1 ;
    xx2 = n ;
    yy2 = n ;
    shrink_right ( ) ;
    shrink_left ( ) ;
    shrink_top ( ) ;
    shrink_bottom ( ) ;
    ans1 = xx1 ;
    ans2 = yy1 ;
    ans3 = xx2 ;
    ans4 = yy2 ;
    xx1 = 1 ;
    yy1 = 1 ;
    xx2 = n ;
    yy2 = n ;
    shrink_right ( ) ;
    shrink_left ( ) ;
    shrink_top ( ) ;
    shrink_bottom ( ) ;    
    printf ( "! %d %d %d %d %d %d %d %d\n" , ans1 , ans2 , ans3 , ans4 , xx1 , yy1 , xx2 , yy2 ) ;
    fflush ( stdout ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}