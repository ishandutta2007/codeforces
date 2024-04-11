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

struct vec {
  int x, y;
  vec() : x(0), y(0) {}
  vec(int _x, int _y) : x(_x), y(_y) {}
  vec(vec &a, vec &b) { x = b.x - a.x; y = b.y - a.y; }
};
ll operator*(const vec &a, const vec &b) {
  return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

const int N = 5005;
const long double Pi = acosl(-1);
vec a[N];
vector<int> p;

int main() {
  File("c");
  int n;
  gi(n);
  for (int i = 1; i <= n; ++i) gi(a[i].x, a[i].y);
  p = {1, 2};
  for (int i = 3; i <= n; ++i) {
    if (vec(a[p.back()], a[i]) * vec(a[p.back()], a[p[i - 3]]) > 0) p.push_back(i);
    else if (vec(a[p.front()], a[i]) * vec(a[p.front()], a[p[1]]) > 0) p.insert(p.begin(), i);
    else for (auto it = next(p.begin()); it != p.end(); ++it)
      if (vec(a[i], a[*it]) * vec(a[i], a[*prev(it)]) > 0 && (next(it) == p.end() || vec(a[*it], a[*next(it)]) * vec(a[*it], a[i]) > 0) && (prev(it) == p.begin() || vec(a[*(it - 1)], a[i]) * vec(a[*(it - 1)], a[*(it - 2)]) > 0)) {
        p.insert(it, i);
        break;
      }
  }
  if ((int)p.size() != n) return puts("-1"), 0;
  for (int x : p) wi(x), SP;
  EL;
  // for (int i = 1; i < n - 1; ++i) {
  //   vec A = vec(a[p[i]], a[p[i - 1]]);
  //   vec B = vec(a[p[i]], a[p[i + 1]]);
  //   assert(A * B > 0);
  //   long double a1 = atan2(A.y, A.x);
  //   long double a2 = atan2(B.y, B.x);
  //   long double d = min({fabs(a1 - a2), fabs(a1 - a2 + 2 * Pi), fabs(a1 - a2 - 2 * Pi)});
  //   assert(d < Pi / 2);
  // }
  return 0;
}