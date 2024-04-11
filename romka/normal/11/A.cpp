#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
  int n, d, x;
  scanf( "%d %d", &n, &d );
  scanf( "%d", &x );
  ll prev = x;
  ll ans = 0;

  forn( i, n-1 )
  {
    scanf( "%d", &x );
    if ( x <= prev )
    {
      ll cnt = (prev-x) / d;
      ans += cnt;
      x += d*cnt;
      if ( x <= prev )
      {
        ans++;
        x += d;
      }
    }
    prev = x;
  } 

  cout << ans << endl;
}