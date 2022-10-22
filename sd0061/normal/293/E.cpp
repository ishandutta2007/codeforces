//K
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
int n , L , W , pre[N] , mcnt;
struct edge
{
  int x , w , next;
}e[N << 1];
bool f[N];
int s[N];
long long ans ;

pair<int , int> Find(int x , int fa , int cnt)
{
  s[x] = 1; int m = 0;
  pair<int , int> res = make_pair(1 << 30 , -1);
  for (int i = pre[x] ; ~i ; i = e[i].next)
    if (!f[e[i].x] && e[i].x != fa)
    {
      res = min(res , Find(e[i].x , x , cnt));
      m = max(s[e[i].x] , m);
      s[x] += s[e[i].x];
    }
  m = max(m , cnt - s[x]);
  return res = min(res , make_pair(m , x));
}

pair<int , int> ds[N] , tds[N];
int s1 , s2;
void Getdis(int x , int fa , int d1 , int d2)
{
  tds[s2 ++] = make_pair(d2 , d1);
  for (int i = pre[x] ; ~i ; i = e[i].next)
    if (!f[e[i].x] && e[i].x != fa)
      Getdis(e[i].x , x , d1 + 1 , d2 + e[i].w);
}
int C[N];
void add(int x , int w)
{
  for (int i = x ; i <= L + 1 ; i += i & -i)
    C[i] += w;
}
int sum(int x)
{
  int res = 0;
  for (int i = x ; i ; i -= i & -i)
    res += C[i];
  return res;
}

long long count(pair<int , int>* P , int num)
{
  long long res = 0;
  sort(P , P + num);
  int i , j;
  for (int i = 0 ; i < num ; ++ i)
    add(P[i].se + 1 , 1) , res -= (P[i].se * 2 <= L && P[i].fi * 2 <= W);
  for (i = 0 , j = num - 1 ; i < num ; ++ i)
  {
    while (j >= 0 && P[i].fi + P[j].fi > W)
      add(P[j].se + 1 , -1) , -- j;
    if (L - P[i].se >= 0)
      res += sum(L - P[i].se + 1);
  }
  while (j >= 0)
    add(P[j].se + 1 , -1) , -- j;

  return res >> 1;
}

void divide(int x , int cnt)
{
  int i;
  s1 = 1 , ds[0] = (make_pair(0 , 0));
  x = Find(x , 0 , cnt).se;
  f[x] = 1;
  for (i = pre[x] ; ~i ; i = e[i].next)
    if (!f[e[i].x])
    {
      Getdis(e[i].x , x , 1 , e[i].w);
      s[e[i].x] = s2;
      ans -= count(tds , s2);
      while (s2)
        ds[s1 ++] = tds[-- s2];
      //ds.insert(ds.end() , tds.begin() ,  tds.end());
    }
  ans += count(ds , s1);
  for (i = pre[x] ; ~i ; i = e[i].next)
    if (!f[e[i].x])
      divide(e[i].x , s[e[i].x]);
}

void work()
{
  int i , x , y , z;
  scanf("%d%d%d",&n,&L,&W);
  memset(pre , -1 , sizeof(pre)) , mcnt = 0;
  for (i = 1 ; i < n ; ++ i)
  {
    scanf("%d%d",&x,&z);
    e[mcnt] = (edge) {i + 1 , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (edge) {x , z , pre[i + 1]} , pre[i + 1] = mcnt ++;
  }
  memset(f , 0 , sizeof(f));
  ans = 0;
  divide(1 , n);
  printf("%I64d\n" , ans);
}

int main()
{
  work();
  return 0;
}