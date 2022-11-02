#include <cstdio>
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
             
const int di[] = { -1, +1, -1, +1 };
const int dj[] = { -1, -1, +1, +1 };

map<int,pii> mm;

int n, s1, s2, best, bi, bj;
vector<pii> vv, ans;

int aa( int x )
{
  return x < 0 ? -x : x;
}

bool diff( int a, int b )
{
  return (a^b) & 1;
}

void test( int ai, int aj )
{
  int z = max( aa( s1 + ai ), aa( s2 + aj ) );
  if ( z < best )
  {
    best = z;
    bi = ai;
    bj = aj;
  }
}

bool cmp( pii a, pii b )
{
  return atan2( 1.0*a.second, 1.0*a.first ) < atan2( 1.0*b.second, 1.0*b.first ) - 1e-6;
}

int main()
{
  forn( x, 200 ) if ( x )
    forn( y, x+1 )
      if ( mm.find( x*x+y*y ) == mm.end() )
        mm[ x*x+y*y ] = pii( x, y );

  scanf( "%d", &n );
  if ( n == 3 )
  {
    printf( "YES\n0 0\n1 0\n0 2\n" );
    return 0;
  }

  int cnt = 0;
  map<int,pii>::iterator it;
  s1 = 0, s2 = 0;

  for ( it = mm.begin(); it != mm.end() && cnt < n; it++, cnt++ )
  {
    vv.pb( it->second );
    s1 += it->second.first;
    s2 += it->second.second;
  }

  if ( diff( s1, s2 ) )
  {
    
    if ( diff( it->second.second, it->second.first ) )
    {
      for ( int q=(int)vv.size()-1; q>=0; q-- )
        if ( !diff( vv[q].second, vv[q].first ) )
        {
          vv[q] = it->second;
          break;
        }
    }
    else
    {
      for ( int q=(int)vv.size()-1; q>=0; q-- )
        if ( diff( vv[q].second, vv[q].first ) )
        {
          vv[q] = it->second;
          break;
        }
    }
  }

  s1 = 0, s2 = 0;

  for ( int i=(int)vv.size()-1; i>=0; i-- )
  {
    best = (int)1e9;
    forn( q, 4 )
    {
      test( vv[i].first * di[q], vv[i].second * dj[q] );
      test( vv[i].second * di[q], vv[i].first * dj[q] );
    }

    s1 += bi;
    s2 += bj;
    ans.pb( pii( bi, bj ) );
  }

  fprintf( stderr, "s1 = %d, s2 = %d\n", s1, s2 );

  sort( ans.begin(), ans.end(), cmp );

  int cx = 0, cy = 0;
  printf( "YES\n" );
  forn( q, ans.size() )
  {
 //   printf( "-> %d %d\n", ans[q].first, ans[q].second );
    printf( "%d %d\n", cx, cy );
    cx += ans[q].first, cy += ans[q].second;
  }

  return 0;
}