#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;

char s[110];
int k, n;
bool u[110];

bool solve() {
  vector<pii> vv;
  forn( i, n ) {
    int j = n - 1 - i;
    if ( s[i] != '?' )
      if ( s[j] != '?' )
        if ( s[i] != s[j] ) return false;
        else u[ s[i]-'a' ] = true;
      else {
        s[j] = s[i];
        u[ s[i]-'a' ] = true;
      }
    else
      if ( s[j] != '?' ) {
        s[i] = s[j];
        u[ s[i]-'a' ] = true;
      } 
      else if ( i <= j ) vv.pb( pii( i, j ) );
  }

  int ik = k-1;
  for ( int i=(int)vv.size()-1; i>=0; i-- ) {
    while ( ik > 0 && u[ik] ) ik--;
    s[ vv[i].first ] = s[ vv[i].second ] = 'a' + ik;
    u[ik] = true;
  }
  
  forn( q, k ) if ( !u[q] ) return false;

  printf( "%s\n", s );

  return true;
}

int main() {
  scanf( "%d", &k );
  scanf( "%s", s );
  n = strlen( s );

  if ( !solve() ) printf( "IMPOSSIBLE\n" );

  return 0;
}