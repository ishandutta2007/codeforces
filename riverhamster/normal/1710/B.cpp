#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;
const ll INF = 1e18;

struct item {
  int p, v, id;
} a[N];
int p[N], pc = 0;
ll h[N], pmx[N], smx[N];
int n, lim;
bool ans[N];

ll ai[N * 2], si[N * 2];

void build(ll *t) {
  for (int i = 0; i < pc; ++i)
    t[pc + i] = h[i];
  for (int i = pc - 1; i; --i)
    t[i] = max(t[i << 1], t[i << 1 | 1]);
}
ll rmax(ll *t, int l, int r) {
  ll ans = -INF;
  for (l += pc, r += pc; l != r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, t[l++]);
    if (r & 1) ans = max(ans, t[--r]);
  }
  return ans;
}

void single() {
  read(n, lim);
  fill(pmx, pmx + n + 1, 0);
  fill(smx, smx + n + 1, 0);
  fill(h, h + n + 1, 0);
  pc = 0;
  for (int i = 0; i < n; ++i)
    read(a[i].p, a[i].v), a[i].id = i, p[pc++] = a[i].p;
  sort(p, p + pc);
  pc = unique(p, p + pc) - p;
  sort(a, a + n, [](item a, item b) { return a.p < b.p; });
  ll sum = 0;
  priority_queue<ll, vector<ll>, greater<ll>> S;
  for (int i = 0, j = 0; i < pc; ++i) {
    while (j < n && a[j].p <= p[i]) {
      sum += a[j].v + a[j].p;
      S.push(a[j].v + a[j].p);
      ++j;
    }
    while (!S.empty() && S.top() - p[i] < 0)
      sum -= S.top(), S.pop();
    h[i] += sum - p[i] * ll(S.size());
  }
  S = decltype(S)(); sum = 0;
  for (int i = pc - 1, j = n - 1; i >= 0; --i) {
    while (j >= 0 && a[j].p > p[i]) {
      sum += a[j].v - a[j].p;
      S.push(a[j].v - a[j].p);
      --j;
    }
    while (!S.empty() && S.top() + p[i] <= 0)
      sum -= S.top(), S.pop();
    h[i] += sum + p[i] * ll(S.size());
  }
  // for (int i = 0; i < pc; ++i)
  //   printf("%lld ", h[i]);
  // puts("");

  for (int i = 0; i < pc; ++i)
    pmx[i + 1] = max(pmx[i], h[i]);
  for (int i = pc - 1; i; --i)
    smx[i - 1] = max(smx[i], h[i]);
  for (int i = 0; i < pc; ++i)
    h[i] -= p[i];
  build(si);
  for (int i = 0; i < pc; ++i)
    h[i] += 2 * p[i];
  build(ai);

  for (int i = 0; i < n; ++i) {
    int lb = lower_bound(p, p + pc, a[i].p - a[i].v) - p;
    int rb = upper_bound(p, p + pc, a[i].p + a[i].v) - p - 1;
    int mid = lower_bound(p, p + pc, a[i].p) - p;
    ll lmx = rmax(si, lb, mid + 1) + a[i].p - a[i].v;
    ll rmx = rmax(ai, mid, rb + 1) - a[i].p - a[i].v;
    // DBG("%d %d : lmx %lld rmx %lld\n", a[i].p, a[i].v, lmx, rmx);
    ans[a[i].id] = lmx <= lim && rmx <= lim && pmx[lb] <= lim && smx[rb] <= lim;
  }
  for (int i = 0; i < n; ++i)
    putchar(ans[i] + '0');
  putchar('\n');
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) single();
  return 0;
}