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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 200005
int n , m , k;
LL ans = 0 , Q = 1e9 + 9;

LL power(int b)
{
  LL a = 2 , res = 1;
  while (b)
  {
    if (b & 1) res *= a , res %= Q;
    b >>= 1 , a *= a , a %= Q;
  }
  return res;
}

void work()
{
  int i , j , x , y;
  cin >> n >> m >> k;
  x = n / k;
  if (m <= n - x)
    printf("%d" , m);
  else
  {
    j = m - n + x;
    y = n - x - (k - 1) * j;
    ans = power(j + 1) * k % Q - k * 2 + y + Q + Q;
    ans %= Q;
    cout << ans << endl;
  }

}

int main()
{
    work();
  return 0;
}