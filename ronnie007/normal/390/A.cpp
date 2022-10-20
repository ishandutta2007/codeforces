#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n ;
int brh[ 1007 ] ;
int brv[ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
	solve ( ) ;
    return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	int x , y ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		brv[ x ] ++ ;
		brh[ y ] ++ ;
	}
}

void solve ( ) {
	int i ;
	int sm1 = 0 ;
	int sm2 = 0 ;
	int ans = 0 ;
	for ( i = 1000 ; i >= 0 ; i -- ) {
		sm1 += min ( brv[ i ] , 1 ) ;
		sm2 += min ( brh[ i ] , 1 ) ;
	}
	ans = min ( sm1 , sm2 ) ;
	printf ( "%d\n" , ans ) ;
}