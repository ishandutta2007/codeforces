#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 205
int n , c[N] , d[N] , temp[N];
vector<int> e[N];
bool f[N];
void work()
{
  int i , j , k , l ,  x , ans = 1 << 30;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
    cin >> c[i];
  for (i = 1 ; i <= n ; ++ i)
  {
    cin >> temp[i];
    for (j = 1 ; j <= temp[i] ; ++ j)
      cin >> x , e[x].push_back(i);
  }

  for (j = 1 ; j <= 3 ; ++ j)
  {
    int sum = 0 , cnt = 0;
    memset(f , 0 , sizeof(f));
    memcpy(d , temp , sizeof(temp));
    for (i = 1 ; i <= n ; ++ i)
      if (c[i] == j && d[i] == 0)
      {
        f[i] = 1 , ++ cnt;
        for (k = 0 ; k < e[i].size() ; ++ k)
          -- d[e[i][k]];
      }

    for (k = j ; cnt < n; k = k % 3 + 1, ++ sum)
    {
      while (1)
      {
        int tmp2 = cnt;
        for (i = 1 ; i <= n ; ++ i) if (!f[i] && !d[i] && c[i] == k)
        {
          f[i] = 1 , ++ cnt;
          for (l = 0 ; l < e[i].size() ; ++ l)
            -- d[e[i][l]];
        }
        if (cnt == tmp2) break;
      }
      if (cnt == n)
        break;
    }
    ans = min(sum , ans);
  }
  cout << ans + n << endl;
}

int main()
{
 // int _; scanf("%d",&_) ; while (_ --)
    work();
  return 0;
}