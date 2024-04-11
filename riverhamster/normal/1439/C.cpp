#include <bits/stdc++.h>
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
int a[N];
struct node {
  ll s;
  int mn, cov;
}t[N * 4];
void tag(int x, int v, int len) {
  t[x].cov = v;
  t[x].mn = v;
  t[x].s = 1LL * v * len;
}
void down(int x, int lenl, int lenr) {
  if (t[x].cov) tag(x << 1, t[x].cov, lenl), tag(x << 1 | 1, t[x].cov, lenr), t[x].cov = 0;
}
void up(int x) {
  t[x].s = t[x << 1].s + t[x << 1 | 1].s;
  t[x].mn = min(t[x << 1].mn, t[x << 1 | 1].mn);
}
int Find(int x, int l, int r, int v) {
  if (t[x].mn > v) return -1;
  if (l == r) return l;
  int mid = (l + r) >> 1;
  down(x, mid - l + 1, r - mid);
  if (t[x << 1].mn <= v) return Find(x << 1, l, mid, v);
  if (t[x << 1 | 1].mn <= v) return Find(x << 1 | 1, mid + 1, r, v);
  return -1;
}
void Assign(int x, int l, int r, int ql, int qr, int v) {
  // if (x == 1) printf("Assign [%d, %d] : %d\n", ql, qr, v);
  if (ql <= l && r <= qr) return tag(x, v, r - l + 1);
  int mid = (l + r) >> 1;
  down(x, mid - l + 1, r - mid);
  if (ql <= mid) Assign(x << 1, l, mid, ql, qr, v);
  if (qr > mid) Assign(x << 1 | 1, mid + 1, r, ql, qr, v);
  up(x);
}
int cnt, w, lt;
void Eat(int x, int l, int r) {
  // printf("%d[%d, %d] s %lld\n", x, l, r, t[x].s);
  if (lt <= l && t[x].s <= w) {
    cnt += r - l + 1;
    w -= t[x].s;
    return;
  }
  int mid = (l + r) >> 1;
  down(x, mid - l + 1, r - mid);
  if (lt <= mid && t[x << 1].mn <= w) Eat(x << 1, l, mid);
  if (t[x << 1 | 1].mn <= w) Eat(x << 1 | 1, mid + 1, r);
}
void build(int x, int l, int r) {
  if (l == r) {
    t[x].mn = t[x].s = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
  up(x);
}

int main(){
  int n, q;
  gi(n); gi(q);
  for (int i = 1; i <= n; ++i) gi(a[i]);
  build(1, 1, n);
  while (q--) {
    int t, x, y;
    gi(t); gi(x); gi(y);
    if (t == 1) {
      int p = Find(1, 1, n, y);
      if (p != -1 && p <= x) Assign(1, 1, n, p, x, y);
    }
    else {
      w = y; cnt = 0; lt = x;
      Eat(1, 1, n);
      wi(cnt), EL;
    }
  }
  return 0;
}