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

const int N = 200005;
char s[N], t[N];
int l[N], r[N];

int cnt[N * 4][2], tag[N * 4];
void up(int x) {
  cnt[x][0] = cnt[x << 1][0] + cnt[x << 1 | 1][0];
  cnt[x][1] = cnt[x << 1][1] + cnt[x << 1 | 1][1];
}
void Tag(int x, int c, int l, int r) { cnt[x][c] = r - l + 1; cnt[x][c ^ 1] = 0; tag[x] = c; }
void down(int x, int l, int r) {
  if (tag[x] != -1) {
    int mid = (l + r) >> 1;
    Tag(x << 1, tag[x], l, mid);
    Tag(x << 1 | 1, tag[x], mid + 1, r);
    tag[x] = -1;
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    cnt[x][0] = t[l] == '0';
    cnt[x][1] = t[l] == '1';
    tag[x] = -1;
    return;
  }
  tag[x] = -1;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  up(x);
}
void modify(int x, int l, int r, int ql, int qr, int c) {
  if (ql <= l && r <= qr) return Tag(x, c, l, r);
  int mid = (l + r) >> 1;
  down(x, l, r);
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, c);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, c);
  up(x);
}
int query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return cnt[x][0];
  int mid = (l + r) >> 1, res = 0;
  down(x, l, r);
  if (ql <= mid) res += query(x << 1, l, mid, ql, qr);
  if (qr > mid) res += query(x << 1 | 1, mid + 1, r, ql, qr);
  return res;
}
bool check(int x, int l, int r) {
  if (l == r) return '0' + cnt[x][1] == s[l];
  int mid = (l + r) >> 1;
  down(x, l, r);
  return check(x << 1, l, mid) && check(x << 1 | 1, mid + 1, r);
}

int main() {
  File("b");
  int T;
  gi(T);
  while (T--) {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1; i <= q; ++i) gi(l[i], r[i]);
    build(1, 1, n);
    bool ok = true;
    for (int i = q; i >= 1; --i) {
      int len = r[i] - l[i] + 1;
      int c0 = query(1, 1, n, l[i], r[i]);
      if (c0 * 2 > len) modify(1, 1, n, l[i], r[i], 0);//, puts("SET 0");
      else if (c0 * 2 == len) { ok = false; break; }
      else modify(1, 1, n, l[i], r[i], 1);//, puts("SET 1");
    }
    if (!ok) { puts("NO"); continue; }
    else puts(check(1, 1, n) ? "YES" : "NO");
  }
  return 0;
}