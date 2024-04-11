#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
#define N 200005
#define M 1000005
int n , m , a[N] , Q;
struct stree
{
  int d ,  w;
}t[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1;
#define ID id(l , r)
#define Left l , mid
#define Right mid + 1 , r

void pushup(int l , int r)
{
  MID; int p = ID , LL = id(Left) , RR = id(Right);
  if (t[p].d & 1)
    t[p].w = t[LL].w ^ t[RR].w;
  else t[p].w = t[LL].w | t[RR].w;
}
void pushdown(int l , int r)
{

}

void update(int l , int r , int x , int w)
{
  if (x <= l && r <= x) {int p = ID;
    t[p].w = w;
    return;}MID;pushdown(l , r);
  if (x <= mid) update(Left , x , w);
  if (x > mid) update(Right , x , w);
  pushup(l , r);
}

void Build(int l , int r , int d)
{
  t[ID].d = d;
  if (l == r) {t[ID].w = a[l];return;}
  MID;Build(Left , d + 1);Build(Right , d + 1);pushup(l , r);
}

void work()
{
  int i , x , y , c , ans = 0;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= 1 << n ; ++ i)
    scanf("%d",&a[i]);
  Build(1 , 1 << n , n + 1);
  while (m --)
  {
    scanf("%d%d",&x,&y);
    update(1 , 1 << n , x , y);
    printf("%d\n" , t[id(1 , 1 << n)].w);
  }
}

int main()
{
    work();
  return 0;
}