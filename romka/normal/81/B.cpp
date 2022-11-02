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

int ip, n;
char s[100010];

bool nextToken( string& res ) {
  if ( ip == n ) return false;
  res = "";
  while ( ip < n && s[ip] == ' ' ) ip++;
  if ( ip == n ) return false;
  if ( s[ip] == ',' ) {
    res = ",";
    ip++;
    return true;
  }
  if ( s[ip] >= '0' && s[ip] <= '9' ) {
    while ( s[ip] >= '0' && s[ip] <= '9' ) res += s[ip++];
    return true;
  }
  if ( s[ip] == '.' ) {
    res = "...";
    ip += 3;
    return true;
  }
  return true;
}

int main()
{
  gets( s );
  n = strlen( s );
  ip = 0;

  string st;
  nextToken( st );

  printf( "%s", st.c_str() );
  string prev = st;

  while ( nextToken( st ) ) {
    if ( prev == "," || st == "..." || ( st[0] >= '0' && st[0] <= '9' && prev[0] >= '0' && prev[0] <= '9' ) ) printf( " " );
    printf( "%s", st.c_str() );
    prev = st;
  }
  return 0;
}