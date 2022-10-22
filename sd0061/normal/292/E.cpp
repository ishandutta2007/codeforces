#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define N 100005
#define fi first
#define se second
int n , m ;
int A[N] , B[N];
#define MID int mid = (l + r) >> 1;
#define Left p << 1 , l , mid
#define Right p << 1 | 1, mid + 1 , r
#define LL p << 1
#define RR p << 1 | 1
pair<int ,int> NUL = make_pair(-1 , -1);
struct stree
{
  pair<int ,int > f;
}t[N << 2];


void Buildtree(int p ,int l ,int r)
{
  t[p].f = NUL;
  if (l == r)
    return;
  MID;
  Buildtree(Left) , Buildtree(Right);
}

void pushdown(int p , int l, int r)
{
  if (t[p].f != NUL)
  {
    t[LL].f = t[RR].f = t[p].f;
    t[p].f = NUL;
  }
}

void Put(int p , int l , int r , int top , int bot , pair<int , int > w)
{
  if (top <= l && r <= bot)
  {
    t[p].f = w;
    return;
  }
  pushdown(p , l , r);
  MID;
  if (top <= mid)
    Put(Left , top , bot , w);
  if (bot > mid)
    Put(Right , top , bot , w);
}

pair<int ,int> Query(int p , int l , int r , int x)
{
  if (x <= l && r <= x)
    return t[p].f;
  pushdown(p , l , r);
  MID;
  if (x <= mid)
    return Query(Left , x);
  else return Query(Right , x);
}

void work()
{
  int i , x , y , z,  k;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&A[i]);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&B[i]);
  Buildtree(1 , 1 , n);
  while (m --)
  {
    scanf("%d",&i);
    if (i == 1)
    {
      scanf("%d%d%d",&x,&y,&k);
      z = y + k - 1;
      Put(1 , 1 , n , y , z , make_pair(x , y));
    }
    else
    {
      scanf("%d",&x);
      pair<int ,int> h = Query(1 , 1 , n , x);
      if (h == NUL)
        printf("%d\n" , B[x]);
      else
      {
        printf("%d\n" , A[x - h.se + h.fi]);
      }
    }

  }
}

int main()
{
    work();
  return 0;
}