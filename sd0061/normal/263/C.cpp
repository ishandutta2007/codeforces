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
using namespace std;
#define N 100005
int n;
bool f[N];
vector<int> e[N] , ans;
void work()
{
  int i , j , k , a , b ,  x , y , z;
  cin >> n;
  for (i = 1 ; i <= n << 1 ; ++ i)
  {
    scanf("%d%d",&x,&y);
    e[x].pb(y) , e[y].pb(x);
  }
  for (i = 1 ; i <= n ;i ++)
    if (e[i].size() != 4)
      break;
  if (i <= n)
  {
    puts("-1");
    return;
  }
  for (j = 0 ; j < 4 ; ++ j)
    for (k = 0 ; k < 4 ; ++ k) if (j != k)
    {
      ans.clear() , memset(f , 0 , sizeof(f));
      x = e[1][j] , y = e[1][k];
      ans.pb(1) , ans.pb(x) , ans.pb(y) ,f[1] =  f[x] = f[y] = 1;
      for (i = 1 ; i <= n - 3 ; ++ i)
      {
        for (a = 0 ; a < 4 ; ++ a)
          if (!f[e[x][a]])
            for (b = 0 ; b < 4 ; ++ b)
              if (e[y][b] == e[x][a])
                goto Yoooooooooo;
        Yoooooooooo:
        if (a >= 4) break;
        z = e[x][a] , f[z] = 1 , ans.pb(z);
        x = y , y = z;
      }
      if (i > n - 3)
      {
        for (i = 0 ;i < n ;i ++)
          printf("%d ",ans[i]);
        return;
      }
    }
  puts("-1");
}

int main()
{
  work();
  return 0;
}