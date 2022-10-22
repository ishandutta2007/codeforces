#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 35
using namespace std;
typedef long long LL;

#define sqr(x) ((x)*(x))
int n , m , d;
char s[N][N];
bool lower[N] , upper[N];

void work()
{
  int i , j , k , l , f = 0;
  scanf("%d%d%d",&n,&m,&d);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , s[i] + 1);

  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
    {
      if (s[i][j] == 'S')
      {
        ++ f;
        for (k = 1 ; k <= n ; ++ k)
          for (l = 1 ; l <= m ; ++ l)
            if (s[k][l] != 'S' && sqr(i - k) + sqr(j - l) <= sqr(d))
              upper[s[k][l] - 'a'] = 1;
      }
      else
        lower[s[i][j] - 'a'] = 1;
    }
  int ans = 0;
  scanf("%d\n",&n);
  while (n --)
  {
    i = getchar();
    if (isupper(i))
    {
      if (!f || !lower[i - 'A']) {puts("-1");return;}
      ans += !upper[i - 'A'];
    }
    else
    {
      if (!lower[i - 'a']) {puts("-1");return;}
    }
  }
  printf("%d", ans);
}

int main()
{
    work();
  return 0;
}