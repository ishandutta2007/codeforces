#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define N 105
int n , m , a[N] , ans = 1 << 30 , ansx;
map<string , int> hash;
vector<int> b[N];
bool f[N];
void dfs(int k)
{
  if (k > n)
  {
    int i , j , sum = 0 , l;
    for (i = 1 ; i <= n ; ++ i)
      for (j = i + 1 ; j <= n ; ++ j)
        sum += a[i] > a[j];
    a[n + 1] = 1 << 30;
    for (l = 1 ; l <= m ; ++ l)
    {
      for (i = 1 , j = 0 ; j < b[l].size() ; ++ j)
        if (a[i] == b[l][j])
          ++ i;
      if (i > n)
      {
        if (sum < ans || sum == ans && l < ansx)
          ans = sum , ansx = l;
      }
    }
    return;
  }
  for (int i = 1 ; i <= n ; ++ i) if (!f[i])
  {
    f[i] = 1 , a[k] = i;
    dfs(k + 1);
    f[i] = 0 , a[k] = 0;
  }
}

int main()
{
    int i , j , x , y , z;
    string str;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        cin >> str , hash[str] = i;
    scanf("%d",&m);
    for (i = 1 ; i <= m ; ++ i)
    {
      scanf("%d",&x) , b[i].resize(x);
      for (j = 0 ; j < x ; ++ j)
        cin >> str , b[i][j] = (hash.count(str) ? hash[str] : 0);
    }
    dfs(1);
    if (ans == 1 << 30)
        puts("Brand new problem!");
    else
    {
      printf("%d\n" , ansx);
      printf("[:");
      for (i = 1 ; i <= n * (n - 1) / 2 - ans + 1 ; ++ i) putchar('|');
      printf(":]");
    }
    return 0;
}