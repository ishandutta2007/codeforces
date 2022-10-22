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
#define N 200005
#define ll long long
#define LL p<<1,top,mid
#define RR p<<1|1,mid + 1,bot
#define MID int mid = (t[p].l + t[p].r) >> 1

int n,m,b[N];
ll a[N] , ans;
struct stree
{
  int l,r;
  int sum,flag;
}t[N << 2];

void Pushup(int p)
{
  t[p].sum = t[p<<1].sum + t[p<<1|1].sum;
}
void Pushdown(int p)
{
  if (t[p].flag && t[p].l != t[p].r)
  {
    t[p<<1].flag += t[p].flag;
    t[p<<1|1].flag += t[p].flag;
    t[p<<1].sum += t[p].flag * (ll)(t[p<<1].r - t[p<<1].l + 1);
    t[p<<1|1].sum += t[p].flag * (ll)(t[p<<1|1].r - t[p<<1|1].l + 1);
    t[p].flag = 0;
  }
}

int Query(int p,int top,int bot)
{
  if (t[p].l >= top && t[p].r <= bot)
    return t[p].sum;
  Pushdown(p);
  MID;
  int ans = 0;
  if (top <= mid)ans += Query(p<<1 , top , bot);
  if (bot > mid) ans += Query(p<<1|1, top , bot);
  return ans;
}

void Add(int p,int top,int bot,ll val)
{
  if (t[p].l >= top && t[p].r <= bot)
  {
    t[p].flag += val;
    t[p].sum += (ll)val * (t[p].r - t[p].l + 1);
    return;
  }
  Pushdown(p);
  MID;
  if (top <= mid) Add(p<<1,top,bot,val);
  if (bot > mid)  Add(p<<1|1,top,bot,val);
  Pushup(p);
}
void Buildtree(int p,int top,int bot)
{
  t[p].l = top , t[p].r = bot;
  if (top < bot)
  {
    MID;
    Buildtree(LL);
    Buildtree(RR);
    Pushup(p);
  }
  else t[p].sum = 0;
}
int main()
{
  char c;int i,x,y;ll z;
  scanf("%d %d\n",&n,&m);
  for (int i = 1 ;i <= n ;i ++)
    scanf("%I64d\n",&a[i]);
  sort(a + 1 , a + 1 + n);Buildtree(1,1,n);
  while(m --)
  {
    scanf("%d%d",&x,&y);
    Add(1,x,y,1);
  }
  for (i = 1 ; i <= n ; i ++)
    b[i] = Query(1 , i ,i);
  sort(b + 1 , n + 1 + b);
  ll ans = 0;
  for (i = 1 ; i <= n ;i ++)
    ans += (ll)a[i] * b[i];
  cout << ans << endl;
  return 0;
}