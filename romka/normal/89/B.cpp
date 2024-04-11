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

const int WDG = 1;
const int VBOX = 2;
const int HBOX = 3;

int ip;
char s[12300];
int len;
int n, k;
map<string,int> mm;
ll w[110], h[110];
int border[110], spacing[110], p[110], type[110];
vector<int> g[110];
bool u[110];

string nextToken() {
  string res = "";
  while ( ip < len && ( s[ip] == '.' || s[ip] == ',' || s[ip] == ' ' || s[ip] == '(' || s[ip] == ')' ) ) ip++;
  while ( ip < len && s[ip] != '.' && s[ip] != ',' && s[ip] != ' ' && s[ip] != '(' && s[ip] != ')' ) res += s[ip++];
  return res;
}

void dfs( int i ) {
  if ( u[i] ) return;
  u[i] = true;
  forn( j, g[i].size() )
    dfs( g[i][j] );

  if ( type[i] == WDG ) return;
  if ( g[i].size() == 0 ) {
    w[i] = h[i] = 0;
    return;
  }

  ll sw = 0, sh = 0, mw = 0, mh = 0;
  forn( j, g[i].size() ) {
    sw += w[ g[i][j] ];
    sh += h[ g[i][j] ];
    mw = max( mw, w[ g[i][j] ] );
    mh = max( mh, h[ g[i][j] ] );
  }

  if ( type[i] == VBOX ) {
    h[i] = 2LL * border[i] + (ll)( g[i].size()-1 ) * spacing[i] + sh;
    w[i] = 2LL * border[i] + mw;
  } else {
    w[i] = 2LL * border[i] + (ll)( g[i].size()-1 ) * spacing[i] + sw;
    h[i] = 2LL * border[i] + mh;
  }
}

int main()
{
  scanf( "%d", &n );
  gets( s );
  forn( i, n ) {
    gets( s );
    len = strlen(s);
    ip = 0;
    string tok = nextToken();

    if ( tok == "VBox" ) {
      tok = nextToken();
      mm[tok] = k++;
      type[k] = VBOX;
      p[k] = -1;      
    } else
    if ( tok == "HBox" ) {
      tok = nextToken();
      mm[tok] = k++;
      type[k] = HBOX;
      p[k] = -1;
    } else
    if ( tok == "Widget" ) {
      tok = nextToken();
      mm[tok] = k++;
      type[k] = WDG;
      sscanf( nextToken().c_str(), "%I64d", &w[k] );
      sscanf( nextToken().c_str(), "%I64d", &h[k] );
      p[k] = -1;
    } else {
      string name = tok;
      tok = nextToken();
      if ( tok == "pack" ) g[ mm[name]+1 ].pb( mm[ nextToken() ]+1 );
//        p[ mm[ nextToken() ] ] = mm[name];
      else
        if ( tok[4] == 'b' ) sscanf( nextToken().c_str(), "%d", &border[ mm[name]+1 ] );
        else sscanf( nextToken().c_str(), "%d", &spacing[ mm[name]+1 ] );
    }
  }

  forn( i, k+1 )
    dfs( i );

  for ( map<string,int>::iterator it = mm.begin(); it != mm.end(); it++ )
    printf( "%s %I64d %I64d\n", it->first.c_str(), w[ it->second+1 ], h[ it->second+1 ] );

  return 0;
}