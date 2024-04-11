#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cassert>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

const int maxn = 100010;

int n, a[maxn], s[maxn];
int fforw[maxn], fback[maxn];

int getsum( int a, int b )
{
  int res = s[b];
  if ( a > 0 ) res -= s[a-1];
  return res;
}

int aa( int x )
{
  return x < 0 ? -x : x;
}

int main()
{
  scanf( "%d", &n );
  forn( i,n ) scanf( "%d", &a[i] );

  s[0] = a[0];
  for ( int i=1; i<n; i++ ) s[i] = a[i] + s[i-1];

  fback[n-1] = aa( a[n-1] );
  for ( int i=n-2; i>=0; i-- )
    fback[i] = max( -getsum( i, n-1 ), a[i] + fback[i+1] );

  fforw[0] = aa( a[0] );
  for ( int i=1; i<n; i++ )
    fforw[i] = max( -getsum( 0, i ), a[i] + fforw[i-1] );

  int ans = aa( getsum( 0, n-1 ) );
  forn( i, n-1 )
  {
    int v1 = -getsum( 0, i ) + fback[i+1];
    int v2 = fforw[i] + ( -getsum( i+1, n-1 ) );

    ans = max( ans, max( v1, v2 ) );
  }

  printf( "%d\n", ans );
}