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

set< pair<pii,int> > ss;
int n, mx, reg, x, y;

int main()
{
  scanf( "%d %d %d", &n, &mx, &reg );
  forn( i, n )
  {
    scanf( "%d %d", &x, &y );
    ss.insert( make_pair( pii( -y, x ), i+1 ) );
  }

  int cur = mx;
  bool used = true;
  int dmg = 0;
  vector<pii> ans;
  int time = 0;

  while ( cur > 0 )
  {
    cur -= dmg;
    cur = min( mx, cur+reg );
    if ( dmg <= reg && !used )
    {
      printf( "NO\n" );
      return 0;
    }

    if ( cur <= 0 ) break;

    used = false;
    for ( set< pair<pii,int> >::iterator sit = ss.begin(); sit != ss.end(); sit++ )
      if ( sit->first.second*mx >= cur * 100 )
      {
        dmg += -sit->first.first;
        ans.pb( pii( time, sit->second ) );
        ss.erase( sit );
        used = true;
        break;
      }        

    time++;
  }

  printf( "YES\n" );
  printf( "%d %d\n", time, ans.size() );
  forn( i, ans.size() ) 
    printf( "%d %d\n", ans[i].first, ans[i].second );
}