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
int n , m , a[N] , Q;
pair<int , int> q[N];
struct stree
{
  int cnt;
  LL sum[5];
}t[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1;
#define ID id(l , r)
#define Left l , mid
#define Right mid + 1 , r

void pushup(int l , int r)
{
  MID; int p = ID , LL = id(Left) , RR = id(Right) , x = t[LL].cnt % 5;
  t[p].cnt = t[LL].cnt + t[RR].cnt;
  for (int i = 0 ; i < 5 ; ++ i)
    t[p].sum[i] = t[LL].sum[i] + t[RR].sum[(i - x + 5) % 5];
}
void pushdown(int l , int r)
{
}

void update(int l , int r , int x , int w)
{
  if (x <= l && r <= x) {int p = ID;
    t[p].cnt += w;
    t[p].sum[0] += a[x - 1] * w;
    return;}MID;pushdown(l , r);
  if (x <= mid) update(Left , x , w);
  if (x > mid) update(Right , x , w);
  pushup(l , r);
}

void work()
{
  int i , x , y;
  char str[10];
  scanf("%d",&m);
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%s" , str);
    if (*str == 'a')
      q[i].first = 1 , scanf("%d" , &q[i].second) , a[n ++] = q[i].second;
    if (*str == 'd')
      q[i].first = 2 , scanf("%d" , &q[i].second) , a[n ++] = q[i].second;
    if (*str == 's')
      q[i].first = 3 ;
  }
  sort(a , a + n) , n = unique(a , a + n) - a;
  for (i = 1 ; i <= m ; ++ i)
  {
    if (q[i].first == 3)
      printf("%I64d\n" , t[id(1 , n)].sum[2]);
    else
    {
      x = lower_bound(a , a + n , q[i].second) - a + 1;
      if (q[i].first == 1)
        y = 1;
      else y = -1;
      update(1 , n , x , y);
    }
  }

}

int main()
{
    work();
  return 0;
}