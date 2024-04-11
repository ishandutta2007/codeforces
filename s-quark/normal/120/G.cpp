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

string s[128];
int c[128];
int a[128][2];
int d[128][128];
int q[100000];
int ans[128][128];
int ansn[128];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, t;
  int m;
  int i, j, k;
  int head, tail;
  int x, y;
  cin>>n>>t;
  for(i = 0; i < n; i++)
  {
    cin>>a[i][0]>>a[i][1]>>j>>k;
    a[i][0] += k;
    a[i][1] += j;
  }
  cin>>m;
  for(i = 0; i < m; i++)
    cin>>s[i]>>c[i];
  head = tail = 0;
  for(i = 0; i < m; i++)
    q[tail++] = i;
  k = 0;
  for(i = 0; head < tail; i++)
  {
    if(i == n)
    {
      i = 0;
      k ^= 1;
    }
    j = t;
    while(j && head < tail)
    {
      x = q[head++];
      y = max(1, c[x]-a[i][k]-d[i][x]);
      if(j >= y)
      {
        j -= y;
        ans[i][ansn[i]++] = x;
      }
      else
      {
        d[i][x] += j;
        j = 0;
        q[tail++] = x;
      }
    }
  }
  for(i = 0; i < n; i++)
  {
    cout<<ansn[i];
    for(j = 0; j < ansn[i]; j++)
      cout<<" "<<s[ans[i][j]];
    cout<<endl;
  }
  return 0;
}