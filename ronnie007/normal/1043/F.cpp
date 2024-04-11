#include<iostream>
#include<stdio.h>
using namespace std ;

#define MOD 1000000007

#define MAXN 300007
int n ;
int a[ MAXN ] ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

int cnt[ MAXN ] ;
int dv[ MAXN ] ;
long long ways[ MAXN ] ;


long long fastpow ( long long val , long long x ) {
  long long ret = 1 ;
  while ( x != 0 ) {
    if ( ( x % 2 ) == 0 ) { val = ( val * val ) % MOD ; x /= 2 ; }
    else { ret = ( ret * val ) % MOD ; x -- ; }
  }
  return ret ;
}

void init ( ) {
  fac[ 0 ] = inv[ 0 ] = 1 ;
  int i , j ;
  for ( i = 1 ; i <= n ; i ++ ) {
    fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    inv[ i ] = fastpow ( fac[ i ] , MOD - 2 ) ;
  }
  for ( i = MAXN - 1 ; i >= 1 ; i -- ) {
    for ( j = i ; j < MAXN ; j += i ) {
      dv[ i ] += cnt[ j ] ;
    }
  }
}

long long get_comb ( int tot , int take ) {
  if ( take > tot ) { return 0 ; }
  long long ret = ( fac[ tot ] * inv[ take ] ) % MOD ;
  ret = ( ret * inv[ tot - take ] ) % MOD ;
  return ret ;
}

bool f ( int sr ) {
  int i , j ;
  for ( i = 0 ; i < MAXN ; i ++ ) {
    ways[ i ] = 0 ;
  }
  for ( i = MAXN - 1 ; i >= 1 ; i -- ) {
    long long aux = get_comb ( dv[ i ] , sr ) ;
    for ( j = 2 * i ; j < MAXN ; j += i ) {
      aux = ( aux - ways[ j ] + MOD ) % MOD ;
    }
    ways[ i ] = aux ;
  }
  return ( ways[ 1 ] > 0 ) ;
}

void input ( ) {
  scanf ( "%d" , &n ) ;
  int i ;
  for ( i = 1 ; i <= n ; i ++ ) {
    scanf ( "%d" , &a[ i ] ) ;
    cnt[ a[ i ] ] ++ ;
  }
}

void solve ( ) {
  init ( ) ;
  int l , r , mid ;
  l = 1 ;
  r = n ;
  if ( f ( r ) == false ) { printf ( "-1\n" ) ; return ; }
  while ( r - l > 3 ) {
    mid = ( l + r ) / 2 ;
    if ( f ( mid ) == false ) { l = mid ; }
    else { r = mid ; }
  }
  while ( f ( l ) == false ) { l ++ ; }
  printf ( "%d\n" , l ) ;
}

int main ( ) {
  input ( ) ;
  solve ( ) ;
  return 0 ;
}