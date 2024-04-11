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

int n;
ll cnt[1230];
char s[123450];

int main()
{
  scanf( "%s", s );
  n = strlen( s );
  forn( i, n ) cnt[ s[i] ]++;

  ll ans = 0;

  forn( i, 256 ) ans += ( cnt[i] * cnt[i] );

  cout << ans << endl;

  return 0;
}