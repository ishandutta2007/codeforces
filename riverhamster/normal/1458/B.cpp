#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#else
#define File(s)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
  char ch; x = 0;int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> inline void wi(T x){
  static char stk[128]; int top = 0;
  if(x == 0) putchar('0');
  if(x < 0) putchar('-'), x = -x;
  while(x) stk[++top] = x % 10, x /= 10;
  while(top) putchar(stk[top--] + '0');
}
template<class T, class ...Args>
inline void gi(T &x, Args&... args) {gi(x); gi(args...);}
template<class T, class ...Args>
inline void wi(T x, Args... args) {wi(x); SP; wi(args...);}
template<class T> void upmax(T &x, T y) {x = x > y ? x : y;}
template<class T> void upmin(T &x, T y) {x = x < y ? x : y;}

const int N = 105;
int a[N], b[N];
int f[N][N * N];

int main() {
  int n;
  gi(n);
  for (int i = 0; i < n; ++i) gi(b[i], a[i]), a[i] *= 2;
  int s = 0;
  memset(f, 0x9f, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j)
      for (int t = s; t >= 0; --t) {
        f[j + 1][t + b[i]] = max(f[j + 1][t + b[i]], f[j][t] + a[i]);
        f[j][t] += a[i] / 2;
      }
    s += b[i];
  }
  for (int j = 1; j <= n; ++j) {
    int res = 0;
    for (int t = 0; t <= s; ++t)
      res = max(res, min(t * 2, f[j][t]));
    printf("%lf ", res * 0.5);
  }
  return 0;
}