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

int L, b, f, q, x, n;
set<pii> ss;
int ans[110], len[110];

void out( int x )
{
  x--;
  ss.erase( ss.find( pii( ans[x], x ) ) );
}

bool check( int s, int l )
{
  int wf = s + l;

  for ( set<pii>::iterator it = ss.begin(); it != ss.end(); it++ )
  {
    int s1 = max( it->first, s );
    int s2 = min( it->first + len[it->second], wf );

    if ( s2 > s1 ) return false;
  }

  if ( wf-f > L ) return false;

  return true;
}

void add( int i, int x )
{
  if ( check( 0, x+f ) )
  {
    ans[i] = 0;
    printf( "%d\n", ans[i] );
    len[i] = x;
    ss.insert( pii( ans[i], i ) );
    return;
  }

  for ( set<pii>::iterator it = ss.begin(); it != ss.end(); it++ )
    if ( check( it->first + len[it->second], b + x + f ) )
    {
      ans[i] = it->first + len[it->second] + b;
      printf( "%d\n", ans[i] );
      len[i] = x;
      ss.insert( pii( ans[i], i ) );
      return;
    }

  printf( "-1\n" );
}

int main()
{
  scanf( "%d %d %d", &L, &b, &f );
  scanf( "%d", &n );
  forn( i, n )
  {
    scanf( "%d %d", &q, &x );
    if ( q == 1 ) add( i, x );
    else out( x );
  }
  return 0;
}