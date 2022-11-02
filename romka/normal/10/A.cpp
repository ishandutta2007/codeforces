#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include <set>
#include <string.h>
#include <string>
#include <memory.h>
#include <ctime>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back

int n, p1, p2, p3, t1, t2, l, r;

int main()
{
  scanf( "%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2 );

  long long ans = 0;
  int rw = 0;
  forn( i,n )
  {
    scanf( "%d %d", &l, &r );
    if ( i )
    {
      int cur = l - rw;
      ans += min( cur, t1 ) * p1;
      cur -= min( cur, t1 );
      ans += min( cur, t2 ) * p2;
      cur -= min( cur, t2 );
      ans += cur * p3;
    }

    ans += ( r-l ) * p1;
    rw = r;
  }

  cout << ans << endl;
}