#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

int n ;

struct tuhla {
	int x , y ; 
	int homex , homey ;
};

struct tuhla a[ 17 ] ;
struct tuhla b[ 17 ] ;

struct tuhla rot ( struct tuhla p ) {
	struct tuhla ret ;
	struct tuhla h ;
	h.x = p.homex - ( p.y - p.homey ) ;
	h.y = p.homey + ( p.x - p.homex ) ;
	h.homex = p.homex ;
	h.homey = p.homey ;
	ret = h ;
	return ret ;
}

int dist ( struct tuhla p1 , struct tuhla p2 ) {
	return ( ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y ) ) ;
}


bool isSQUARE ( ) {
	int ind[ 17 ] ;
	int i ;
	for ( i = 0 ; i < 4 ; i ++ ) ind[ i ] = i ;
	if ( dist ( b[ ind[ 0 ] ] , b[ ind[ 1 ] ] ) != 0 && 
         dist ( b[ ind[ 1 ] ] , b[ ind[ 3 ] ] ) != 0 && 
		dist ( b[ ind[ 0 ] ] , b[ ind[ 1 ] ] ) == dist ( b[ ind[ 1 ] ] , b[ ind[ 2 ] ] ) &&
		dist ( b[ ind[ 1 ] ] , b[ ind[ 2 ] ] ) == dist ( b[ ind[ 2 ] ] , b[ ind[ 3 ] ] ) &&
		dist ( b[ ind[ 2 ] ] , b[ ind[ 3 ] ] ) == dist ( b[ ind[ 3 ] ] , b[ ind[ 0 ] ] ) &&
        dist ( b[ ind[ 1 ] ] , b[ ind[ 3 ] ] ) == dist ( b[ ind[ 0 ] ] , b[ ind[ 2 ] ] ) ) return true ; 

	while ( next_permutation ( ind , ind + 4 ) ) {
        if (dist ( b[ ind[ 0 ] ] , b[ ind[ 1 ] ] ) != 0 && 
            dist ( b[ ind[ 1 ] ] , b[ ind[ 3 ] ] ) != 0 && 
		dist ( b[ ind[ 0 ] ] , b[ ind[ 1 ] ] ) == dist ( b[ ind[ 1 ] ] , b[ ind[ 2 ] ] ) &&
		dist ( b[ ind[ 1 ] ] , b[ ind[ 2 ] ] ) == dist ( b[ ind[ 2 ] ] , b[ ind[ 3 ] ] ) &&
		dist ( b[ ind[ 2 ] ] , b[ ind[ 3 ] ] ) == dist ( b[ ind[ 3 ] ] , b[ ind[ 0 ] ] ) &&
        dist ( b[ ind[ 1 ] ] , b[ ind[ 3 ] ] ) == dist ( b[ ind[ 0 ] ] , b[ ind[ 2 ] ] ) ) return true ;
	}
	if ( dist ( b[ ind[ 0 ] ] , b[ ind[ 1 ] ] ) != 0 && 
         dist ( b[ ind[ 1 ] ] , b[ ind[ 3 ] ] ) != 0 && 
		dist ( b[ ind[ 0 ] ] , b[ ind[ 1 ] ] ) == dist ( b[ ind[ 1 ] ] , b[ ind[ 2 ] ] ) &&
		dist ( b[ ind[ 1 ] ] , b[ ind[ 2 ] ] ) == dist ( b[ ind[ 2 ] ] , b[ ind[ 3 ] ] ) &&
		dist ( b[ ind[ 2 ] ] , b[ ind[ 3 ] ] ) == dist ( b[ ind[ 3 ] ] , b[ ind[ 0 ] ] ) &&
        dist ( b[ ind[ 1 ] ] , b[ ind[ 3 ] ] ) == dist ( b[ ind[ 0 ] ] , b[ ind[ 2 ] ] ) ) return true ; 

	return false ;
}



void input ( ) ;
void solve ( ) ;



int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	return 0 ;
}

void solve ( ) {
	int i , j , t , z ;
	for ( i = 0 ; i < 4 ; i ++ ) {
		b[ i ] = a[ i ] ; 
	}
	int ans = -1 ; 
	for ( i = 0 ; i <= 4 ; i ++ ) {
		for ( j = 0 ; j <= 4 ; j ++ ) {
			for ( t = 0 ; t <= 4 ; t ++ ) {
				for ( z = 0 ; z <= 4 ; z ++ ) {
					int u ;
					b[ 0 ] = a[ 0 ] ;
					for ( u = 0 ; u < i ; u ++ ) b[ 0 ] = rot ( b[ 0 ] ) ;

					b[ 1 ] = a[ 1 ] ;
					for ( u = 0 ; u < j ; u ++ ) b[ 1 ] = rot ( b[ 1 ] ) ;

					b[ 2 ] = a[ 2 ] ;
					for ( u = 0 ; u < t ; u ++ ) b[ 2 ] = rot ( b[ 2 ] ) ;

					b[ 3 ] = a[ 3 ] ;
					for ( u = 0 ; u < z ; u ++ ) b[ 3 ] = rot ( b[ 3 ] ) ;

						if ( i == 2 && j == 0 && t == 1 && z == 0 ) {
                            // printf ( "%d %d\n" , b[ 0 ].x , b[ 0 ].y ) ;
                            //  printf ( "%d %d\n" , b[ 1 ].x , b[ 1 ].y ) ;
                            // printf ( "%d %d\n" , b[ 2 ].x , b[ 2 ].y ) ;
                            // printf ( "%d %d\n" , b[ 3 ].x , b[ 3 ].y ) ;
						}
					if ( isSQUARE ( ) == true ) {

						if ( ans == -1 || ans > i + j + t + z ) ans = i + j + t + z ;
					}
				}
			}
        }
	}
	printf ( "%d\n" , ans ) ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < 4 ; j ++ ) {
			scanf ( "%d%d%d%d" , &a[ j ].x , &a[ j ].y , &a[ j ].homex , &a[ j ].homey ) ;
		}
		//printf ( "\n" ) ;
        //	a[ 0 ] = rot ( a[ 0 ] ) ;
        //	printf ( "ROT a[ 0 ] = %d %d \n" , a[ 0 ].x , a[ 0 ].y ) ;
		//printf ( "-------\n" ) ;
		solve ( ) ;
	}
}