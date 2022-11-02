#include <cstdio>
#include <iostream>
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

int n, m, rc, cs, s[15000010];

void seg( int a, int b )
{
//  printf( "[%d - %d]\n", a, b );
  s[a]++;
  s[b+1]--;
}

int main()
{
  scanf( "%d %d", &n, &m );
  ll ans = 0;

  int mh = 0, s1, s2;
  for ( int i=1; i<=n; i++ )
  {
    rc = m;
    s1 = i-1;
    if ( ((ll)i*i) <= rc ) 
    {
      rc = i*i;
      s2 = -1;
    }
    else
      s2 = (int)(sqrt((double)i*i-rc-1) + 1e-7);
//    printf( "i = %d : rc = %d, s1=%d, s2=%d\n", i, rc, s1, s2 );
    ans += (rc-(s1-s2))*2;
    seg( i+s2+1, i+s1 );
    seg( i-s1, i-s2-1 );

    mh = max( mh, i+s1+1 );
  }

//  cout << ans << endl;

  int bal = 0;
  forn( i, mh+2 )
  {
    bal += s[i];
    if ( bal > 0 ) ans++;
  }

  cout << ans << endl;

  return 0;
}