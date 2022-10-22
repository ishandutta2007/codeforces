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

void work()
{
  int n, m, x, y, a, b, k;
  scanf ("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
  int g = __gcd (a, b);
  a /= g; b /= g;
  k = min (n / a, m / b);
  a *= k; b *= k;
  int px = x - (a + 1) / 2, py = y - (b + 1) / 2;
  if (px < 0) px = 0;
  if (py < 0) py = 0;
  if (px + a > n) px = n - a;
  if (py + b > m) py = m - b;
  printf ("%d %d %d %d\n", px, py, px + a, py + b);
}


int main()
{
    work();
  return 0;
}