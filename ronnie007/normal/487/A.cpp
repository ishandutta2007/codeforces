#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

struct tuhla {
	int hp ;
	int atk ;
	int def ;
};

struct tuhla a , b ;

int ch , ca , cd ;

void input ( ) ;
void solve ( ) ;


int f ( int x , int y ) {
	struct tuhla u = a ;
	u.atk += x ;
	u.def += y ;
	if ( u.atk <= b.def ) return 10000000 ;
	struct tuhla k = b ;
	while ( 1 ) {
		k.hp -= max ( 0 , u.atk - k.def ) ;
		u.hp -= max ( 0 , k.atk - u.def ) ;
		if ( k.hp <= 0 ) break ;
    }
	if ( u.hp > 0 ) return 0 ;
	return ( 1 - u.hp ) ;
}


int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d%d" , &a.hp , &a.atk , &a.def ) ;
	scanf ( "%d%d%d" , &b.hp , &b.atk , &b.def ) ;
	scanf ( "%d%d%d" , &ch , &ca , &cd ) ;
}

void solve ( )  {
	int i , j ;
	int p ;
	int ans = 10000000 ;
	int cur ;
	for ( i = 0 ; i <= 300 ; i ++ ) {
		for ( j = 0 ; j <= 300 ; j ++ ) {
			p = f ( i , j ) ;
			cur = i * ca + j * cd + p * ch ;
			ans = min ( ans , cur ) ;
        }
    }
	printf ( "%d\n" , ans ) ;
}