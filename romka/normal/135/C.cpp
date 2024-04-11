#include <iostream>
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
#define foreach( it, a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

char s[100010];

int main()
{
  gets( s );
  int n = strlen( s );
  int c0 = 0, c1 = 0, c2 = 0;
  forn( i, n ) {
    if ( s[i] == '0' ) c0++;
    if ( s[i] == '1' ) c1++;
    if ( s[i] == '?' ) c2++;
  }

  vector<string> ans;
  if ( n&1 ) {
    if ( c0 + c2 > c1 ) ans.pb( "00" );
    if ( c1 + c2 > c0 + 1 ) ans.pb( "11" );
  } else { 
    if ( c0 + c2 > c1 + 1 ) ans.pb( "00" );
    if ( c1 + c2 > c0 + 1 ) ans.pb( "11" );
  }

    int k = n >> 1;
    if ( c0 + c2 >= k && c0 <= k ) {
      int n0 = k-c0;
      int n1 = c2 - n0;
      if ( (s[n-1] == '?' && n0 > 0) || s[n-1] == '0' ) ans.pb( "10" );
      if ( (s[n-1] == '?' && n1 > 0) || s[n-1] == '1' ) ans.pb( "01" );
    }

  sort( ans.begin(), ans.end() );

  forn( i, ans.size() )
    printf( "%s\n", ans[i].c_str() );

  return 0;
}