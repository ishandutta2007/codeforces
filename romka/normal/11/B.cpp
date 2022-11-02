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
  int x;
  scanf( "%d", &x );
  if ( x < 0 ) x = -x;

  int ans = 0;
  int cur = 0;
  for ( int i=1; cur < x; i++ )
  {
    cur += i;
    ans++;
  }

  if ( (x-cur)&1 )
    if ( ans&1 ) ans += 2;
    else ans++;

  printf( "%d\n", ans );
}