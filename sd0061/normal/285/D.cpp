#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
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
#define N 17
#define M 100005
#define LL long long
int n , f , u;
long long ans;
const int Q = 1e9 + 7;

void dfs(int k)
{
  if (k > n)
  {
    ++ ans;
    return;
  }
  for (int i = 1 ; i <= n ;i ++)
    if (~f & (1 << i))
    {
      int x = (k + i - 2) % n + 1;
      if (u & (1 << x)) continue;
      f |= (1 << i) , u |= (1 << x);
      dfs(k + 1);
      f &= ~(1 << i) , u &= ~(1 << x);
    }
}

void work()
{
  ans = 0;
  dfs(1);
  for (int i = 1 ; i <= n ; ++ i)
    ans *= i , ans %= Q;
  printf(",%I64d" , ans);
}
int a[] = {1,18,1800,670320,734832000,890786230,695720788,150347555};
int main()
{
  cin >> n;
  if (n & 1) cout << a[n>>1];
  else cout << 0;
  return 0;
}