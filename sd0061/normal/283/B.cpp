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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 400005
using namespace std;

int n , a[N] , d[N];
long long f[N];
vector<int> e[N];
void work()
{
  int i ;
  long long x , y , z ;
  scanf("%d",&n);
  for (i = 2 ; i <= n ;i ++)
  {
    scanf("%d",&a[i]);
    if (i + a[i] <= n)
    {
      e[i + a[i] + n].pb(i);
      ++ d[i];
    }
    if (i - a[i] > 0)
    {
      e[i - a[i]].pb(i + n);
      ++ d[i + n];
    }
  }
  queue<int> q;
  for (i = 2 ; i <= n << 1 ; ++ i) if (!d[i])
     q.push(i);
  while (!q.empty())
  {
    x = q.front() , q.pop();
    f[x] += x > n ? a[x - n] : a[x];
    for (i = 0 ;i < e[x].size() ; ++ i)
    {
      y = e[x][i];
      f[y] = f[x];
      if(!-- d[y])
        q.push(y);
    }
  }
  for (i = 2 ; i <= n ;i ++)
    if (!f[i + n])
      puts("-1");
    else
      printf("%I64d\n" , f[i + n] + i - 1);
}

int main()
{
  //int _;cin>>_;while(_--)
    work();
  return 0;
}