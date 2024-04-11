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
const int MAXN = 1<<17;

int x[MAXN], y[MAXN];
int st[MAXN];
int in[MAXN];
int tmp[MAXN];
int ans1, ans2;
int ans;

bool cmp(int a, int b)
{
  return x[a] < x[b];
}

inline int dis(int x, int y)
{
  return x*x + y*y;
}

void up(int a, int b)
{
  if(dis(x[a]-x[b], y[a]-y[b]) < ans)
  {
    ans = dis(x[a]-x[b], y[a]-y[b]);
    ans1 = a;
    ans2 = b;
  }
}

void f(int l, int r)
{
  if(r-l  == 1)
  {
    return;
  }
  int i, j, mid, k, z;
  int xm;
  mid = (r+l)>>1;
  xm = x[in[mid]];
  f(l, mid);
  f(mid, r);
  i = l;
  j = mid;
  k = 0;
  while(k < r-l)
  {
    if(i == mid)
      tmp[k++] = in[j++];
    else if(j == r)
      tmp[k++] = in[i++];
    else if(y[in[i]] < y[in[j]])
      tmp[k++] = in[i++];
    else
      tmp[k++] = in[j++];
  }
  for(i = 0; i < r-l; i++)
    in[l+i] = tmp[i];
  j = k = 0;
  for(i = l; i < r; i++)
  {
    if((x[in[i]] - xm) * (x[in[i]] - xm) < ans)
    {
      tmp[k] = in[i];
      while((y[tmp[k]] - y[tmp[j]]) * (y[tmp[k]] - y[tmp[j]]) >= ans)
        j++;
      for(z = j; z < k; z++)
        up(tmp[z], tmp[k]);
      k++;
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, i;
  cin>>n;
  for(i = 0; i < n; i++)
  {
    scanf("%d%d", &x[i], &y[i]);
    if(x[i] < 0)
    {
      x[i] = -x[i];
      st[i] += 1;
    }
    if(y[i] < 0)
    {
      y[i] = -y[i];
      st[i] += 2;
    }
  }
  for(i = 0; i < n; i++)
    in[i] = i;
  sort(in, in+n, cmp);
  ans = 1<<30;
  f(0, n);
  cout<<ans1+1<<" "<<st[ans1]+1<<" "<<ans2+1<<" "<<(st[ans2]^3)+1<<endl;
  return 0;
}