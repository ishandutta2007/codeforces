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
#define N 5005
#define LL long long
char s[N] , t[N];
int f[N][N] , Q = 1e9 + 7;

void work()
{
  int i , j , n , m;
  scanf("%s%s", s + 1 , t + 1);
  n = strlen(s + 1) , m = strlen(t + 1);
  for (i = 1 ; s[i] ; ++ i)
    for (j = 1 ; t[j] ; ++ j)
    {
      f[i][j] = f[i][j - 1];
      if (s[i] == t[j])
        f[i][j] += f[i - 1][j - 1] + 1;
      f[i][j] %= Q;
    }
  int ans = 0;
  for (i = 1 ; s[i] ; ++ i)
    ans += f[i][m] , ans %= Q;
  cout << ans << endl;

}

int main()
{
  work();
  return 0;
}