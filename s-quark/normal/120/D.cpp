#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

int a[64][64];
vector<int> s(3), t(3);

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  int i, j, k1, k2;
  int ans = 0;
  cin>>n>>m;
  FOR(i, 0, n)
    FOR(j, 0, m)
      cin>>a[i][j];
  cin>>s[0]>>s[1]>>s[2];
  sort(s.begin(), s.end());
  FOR(k1, 1, n)
    FOR(k2, k1+1, n)
    {
      t[0] = t[1] = t[2] = 0;
      FOR(i, 0, k1)
        FOR(j, 0, m)
          t[0] += a[i][j];
      FOR(i, k1, k2)
        FOR(j, 0, m)
          t[1] += a[i][j];
      FOR(i, k2, n)
        FOR(j, 0, m)
          t[2] += a[i][j];
      sort(t.begin(), t.end());
      ans += (s==t);
    }
  FOR(k1, 1, m)
    FOR(k2, k1+1, m)
    {
      t[0] = t[1] = t[2] = 0;
      FOR(i, 0, n)
        FOR(j, 0, k1)
          t[0] += a[i][j];
      FOR(i, 0, n)
        FOR(j, k1, k2)
          t[1] += a[i][j];
      FOR(i, 0, n)
        FOR(j, k2, m)
          t[2] += a[i][j];
      sort(t.begin(), t.end());
      ans += (s==t);
    }
  cout<<ans<<endl;
  return 0;
}