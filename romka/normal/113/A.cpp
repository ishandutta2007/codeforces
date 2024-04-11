#include <cstdio>
#include <sstream>
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
#define foreach( it,a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

char s[100010];
vector<int> v;
int ip, ip2, n;

bool next_token() {
  ip = ip2;
  while ( ip < n && (s[ip] < 'a' || s[ip] > 'z') ) ip++;
  if ( ip == n ) return false;
  ip2 = ip;
  while ( ip2 < n && s[ip2] >= 'a' && s[ip2] <= 'z' ) ip2++;
  return true;
}

char z;

int get_type() {
  int len = ip2 - ip;
  z = s[ip2];
  s[ip2] = 0;
//  printf( "gettype of |%s| - |%s|, len = %d\n", s+ip, s+ip2, len );
  if ( strcmp( s + ip + len - 6, "initis" ) == 0 ) return 20; 
  if ( strcmp( s + ip + len - 6, "inites" ) == 0 ) return 21;
  if ( strcmp( s + ip + len - 4, "lios" ) == 0 ) return 0;
  if ( strcmp( s + ip + len - 5, "liala" ) == 0 ) return 1;
  if ( strcmp( s + ip + len - 3, "etr" ) == 0 ) return 10;
  if ( strcmp( s + ip + len - 4, "etra" ) == 0 ) return 11;
  return -1;
}

bool solve() {
  forn( i, v.size() )
    if ( v[i] == -1 ) return false;
  if ( v.size() == 1 ) return true;
  forn( i, v.size() )
    forn( j, i )
      if ( v[i] % 10 != v[j] % 10 ) return false;
  forn( i, (int)v.size()-1 )
    if ( v[i] > v[i+1] ) return false;
  int cnt = 0;
  forn( i, v.size() )
    cnt += v[i] / 10 == 1;
  return cnt == 1;
}

int main()
{
  gets( s );
  n = strlen( s );
  while ( next_token() ) {
    v.pb( get_type() );
    s[ip2] = z;
  }

//  forn( i, v.size() ) printf( "%d\n", v[i] );

  if ( solve() ) printf( "YES\n" );
  else printf( "NO\n" );
  return 0;
}