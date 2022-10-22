#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 100005
int n , m , d[N] , a[N];
map<int , int> h;
vector<int> e[N];

void dfs(int x , int f)
{
  printf("%d " , a[x]);
  for (int i = 0 ; i < e[x].size() ; ++ i)
    if (e[x][i] != f) dfs(e[x][i] , x);
}

int main()
{
   int i , x , y;
   scanf("%d",&n);
   for (i = 1 ; i <= n ; ++ i)
   {
     scanf("%d%d",&x,&y);
     if (!h.count(x)) a[++ m] = x , h[x] = m; x = h[x];
     if (!h.count(y)) a[++ m] = y , h[y] = m; y = h[y];
     e[x].push_back(y) , e[y].push_back(x);
     ++ d[x] , ++ d[y];
   }
   for (i = 1 ; i <= m ; ++ i) if (d[i] == 1)
   {
     dfs(i , -1);
     break;
   }
   return 0;
}