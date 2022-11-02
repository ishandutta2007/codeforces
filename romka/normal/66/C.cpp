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

char s[110];
int ip, n;

string nextToken()
{
  string res = "";
  while ( ip < n && s[ip] != '\\' )
    res += s[ip++];
  ip++;
  return res;
}

int nc, cur;
map<string,int> mm[10010];

bool isFile( const string& s )
{
  forn( i, s.size() )
    if ( s[i] == '.' ) return true;

  return false;
}

pii dfs( int i )
{
  pii res( 0, 0 );
  
  for ( map<string,int>::iterator it = mm[i].begin(); it != mm[i].end(); it++ )
  {
    pii z = dfs( it->second );
    res.first += z.first;
    res.second += z.second;
    if ( isFile( it->first ) ) res.second++;
    else res.first++;
  }

  return res;
}

int main()
{
  nc = 1;
  while ( scanf( "%s", s ) != EOF )
  {
    n = strlen( s );
    ip = 0;
    cur = 0;
    while ( ip < n )
    {
      string ct = nextToken();
      if ( mm[cur].find( ct ) == mm[cur].end() ) mm[cur][ct] = nc++;
      cur = mm[cur][ct];  
    }
  }

  int cd = 0, cf = 0;
  for ( map<string,int>::iterator it = mm[0].begin(); it != mm[0].end(); it++ )
    for ( map<string,int>::iterator jt = mm[it->second].begin(); jt != mm[it->second].end(); jt++ )
  {
    pii z = dfs( jt->second );
    if ( z.first > cd ) cd = z.first;
    if ( z.second > cf ) cf = z.second;
  }

  printf( "%d %d\n", cd, cf );

  return 0;
}