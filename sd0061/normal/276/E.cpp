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
#define N 100005
typedef long long LL;
int n , m , cnt , bel[N] , s[N] , dep[N];
vector<int> link[N] , e[N] , c[N];
int lowbit(int x) {return x & (-x);}

void add(int p , int x , int w)
{
  for (int i = x ; i <= s[p] ; i += lowbit(i))
    c[p][i] += w;
}

int sum(int p , int x)
{
  int S = 0;
  for (int i = x ; i > 0 ; i -= lowbit(i))
    S += c[p][i];
  return S;
}

void work()
{
  int i , j , x , y , w;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i < n ;i ++)
    scanf("%d%d",&x,&y) , e[x].pb(y) , e[y].pb(x);
  for (i = 0 ; i < e[1].size() ; ++ i)
  {
    x = e[1][i] , bel[x] = ++ cnt , link[cnt].pb(x) , dep[x] = 1 ,y = 1;
    while (e[x].size() == 2)
    {
      for (j = 0 ; j < e[x].size() ; ++ j)
        if (e[x][j] != y)
        {
          y = x , x = e[x][j];
          bel[x] = cnt , link[cnt].pb(x) , dep[x] = dep[y] + 1;
        }
    }
    s[cnt] = link[cnt].size() + 1;
  }
  for (i = 1 ; i <= cnt ; ++ i)
    c[i].resize(s[i] + 1);
  c[0].resize(n + 2) , s[0] = n + 1;
  int w1 = 0;
  while (m --)
  {
    scanf("%d",&i);
    if (i == 0)
    {
      scanf("%d%d%d",&x , &w , &j) , y = bel[x];
      if (j < dep[x])
      {
        add(y , dep[x] - j , w);
        add(y , min(dep[x] + j + 1 , s[y]), -w);
      }
      else
      {
        w1 += w;
        add(0 , 1 , w);
        add(0 , j - dep[x] + 1 , -w);
        if (x != 1)
          add(y , j - dep[x] + 1 , w) , add(y , min(dep[x] + j + 1 , s[y]) , -w) ;
      }
    }
    else
    {
      scanf("%d",&x) , y = bel[x];
      if (x == 1) printf("%d\n" , w1);
      else printf("%d\n",sum(y , dep[x]) + sum(0 , dep[x]));
    }
  }
  return;
}

int main()
{
  //while (scanf("%d%d",&n ,&m) , n || m)
    work();
  return 0;
}