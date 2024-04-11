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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
#define LL long long
int n;
vector<int> a[N] , l[N] , r[N];

void work()
{
  int i , j , x , y , z;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
  {
    scanf("%d",&x);
    a[i].push_back(0);
    while (x --)
      scanf("%d",&j) , a[i].push_back(j);
    sort(a[i].begin() , a[i].end());
    l[i].resize(a[i].size()) , r[i].resize(a[i].size());
  }

  for (i = 1 ; i <= n ; ++ i)
  {
    x = i == 1 ? n : i - 1;
    y = 1 , z = 1;
    for (j = 1 ; j < a[i].size() ; ++ j)
    {
      while (y < a[x].size() && a[x][y] < a[i][j])
        ++ y;
      while (z < a[x].size() && a[x][z] < a[i][j - 1])
        ++ z;
      l[i][j] = y - z;
    }
  }
  for (i = 1 ; i <= n ; ++ i)
  {
    x = i == n ? 1 : i + 1;
    y = 1 , z = 1;
    for (j = 1 ; j < a[i].size() ; ++ j)
    {
      while (y < a[x].size() && a[x][y] < a[i][j])
        ++ y;
      while (z < a[x].size() && a[x][z] < a[i][j - 1])
        ++ z;
      r[i][j] = y - z;
    }
  }
  int ans = 0;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 2 ; j < a[i].size() ; ++ j)
      if (l[i][j] != r[i][j])
        ++ ans;
  cout << ans << endl;
}


int main()
{
  work();
  return 0;
}