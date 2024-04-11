#include <cstdio>
#include <string>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 100010;

int f[maxn], u[maxn];

int getf( int n ) {
  if ( u[n] ) {
    return f[n];
  }

  int& res = f[n];
  u[n] = 1;
  res = 0;

  set<int> ss;

  for ( int k=2; k*(k-1) / 2 < n; k++ ) {
    int l = n - k*(k-1) / 2;
    if ( l % k == 0 ) {
      int x = l / k;
      int cur = 0;
      forn( q, k )
        cur ^= getf( x+q );
      ss.insert( cur ); 
    }
  } 

//  printf( "n=%d, ss.size() = %d\n", n, ss.size() );

  if ( ss.size() == 0 ) return res = 0;
  else
    if ( *ss.begin() > 0 ) return res = 0;
    else {
      set<int>::iterator prev = ss.begin(), it = prev;
      it++;
      for ( ; it != ss.end(); it++ ) {
        if ( (*it) > (*prev)+1 ) return res = (*prev) + 1;
        prev = it;
      }
      return res = (*prev) + 1;  
    }

  return -1;
}

int main()
{
  int n;
  scanf( "%d", &n );
  int z = getf( n );
  if ( z ) {
  for ( int k=2; k*(k-1) / 2 < n; k++ ) {
    int l = n - k*(k-1) / 2;
    if ( l % k == 0 ) {
      int x = l / k;
      int cur = 0;
      forn( q, k )
        cur ^= getf( x+q );
      if ( cur == 0 ) {
        printf( "%d\n", k );
        return 0;
      }
    }
  } 
  }
  else printf( "-1\n" );
  return 0;
}