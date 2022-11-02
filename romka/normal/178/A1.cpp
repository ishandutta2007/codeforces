#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
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

int n, a[100010];

int main()
{
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);
  ll ans = 0;
  forn(i, n - 1) {
    int t = 0;
    while (i + (1<<(t+1)) < n) t++;
    ans += a[i];
    a[i + (1<<t)] += a[i];
    a[i] = 0;
    printf("%I64d\n", ans);
  }
  return 0;
}