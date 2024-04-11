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
#define N 200005
#define M 100005
#define LL long long
char s[N];
int n ;


void work()
{
  int i , j , x , m;
  scanf("%s" , s);
  n = strlen(s);

  for (i = 1 ; i << 1 <= n ; ++ i)
  {
    m = 0;
    for (j = 0 ; j + i < n ; ++ j)
    {
      if (s[j] == s[j + i])
        ++ m;
      else m = 0;

      if (m == i) break;
    }
    if (j + i >= n) continue;
    for ( ; j + i <= n ; ++ j)
      s[j] = s[j + i];
    n -= i , -- i;
  }
  puts(s);
}

int main()
{
  work();
  return 0;
}