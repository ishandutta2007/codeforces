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

int n;
pii a[1010];
string ans[1010];

int main()
{
  scanf( "%d", &n );
  forn( i, n ) 
  {
    scanf( "%d", &a[i].first );
    a[i].second = i;
  }

  sort( a, a+n );
  int p = 0;

  vector<string> cur;
  cur.pb( "" );

  for ( int i=1; i<=1000; i++ )
  {
    if ( cur.size() >= 1000 )
    {
      forn( j, cur.size() ) cur[j] += '0';
    }
    else
    {
      int k = cur.size();
      forn( j, k )
      {
        cur.pb( cur[j] + '1' );
        cur[j] += '0';
      }
    }

    int nn = 1;
    while ( p < n && a[p].first == i )
    {
      if ( (int)cur.size() < nn )
      {
        printf( "NO\n" );
        return 0;
      }
      ans[ a[p].second ] = cur[ cur.size()-nn ];
      nn++;
      p++;
    }

    cur.resize( cur.size()-nn+1 );
    if ( cur.size() > 1010 ) cur.resize( 1010 );
  }

  printf( "YES\n" );
  forn( i, n )
    printf( "%s\n", ans[i].c_str() );
}