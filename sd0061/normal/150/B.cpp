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
#define N 105
#define LL long long
int n , m , k;
LL Q = 1e9 + 7;

void work()
{
  LL ans; int i , j;
  cin >> n >> m >> k;
  if (k == 1 || k > n)
  {
    ans = 1;
    for (i = 1 ; i <= n ; ++ i)
      ans *= m , ans %= Q;
    cout << ans << endl;
    return;
  }
  if (k == n)
  {
    ans = 1;
    for (i = 1 ; i <= (n + 1) >> 1 ; ++ i)
      ans *= m , ans %= Q;
    cout << ans << endl;
    return;
  }
  cout << (k & 1 ? m * m : m) % Q << endl;
}

int main()
{
  work();
  return 0;
}