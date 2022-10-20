#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <functional>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;
const int M = 1e9 + 7;

void inc(int &x, int y) { if ((x += y) >= M) x -= M; }

int tr[N], stamp[N], cur = 1;
void insert(int p, int v) {
  for (; p < N; p += p & -p) {
    if (stamp[p] != cur) tr[p] = 0, stamp[p] = cur;
    inc(tr[p], v);
  }
}
int query(int p, ll v = 0) {
  for (; p; p &= p - 1) {
    if (stamp[p] != cur) tr[p] = 0, stamp[p] = cur;
    v += tr[p];
  }
  return v % M;
}

pair<int, int> a[N], disc[N];
int p[N], ip[N];
int f[N], g[N];

void solvecase() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i].first), a[i].second = -i;
    disc[i] = a[i];
  }
  sort(disc + 1, disc + 1 + n);
  for (int i = 1; i <= n; ++i) {
    p[i] = lower_bound(disc + 1, disc + 1 + n, a[i]) - disc;
    ip[p[i]] = i;
  }
  ++cur;
  for (int i = 1; i <= n; ++i) {
    int v = query(p[i], 1);
    f[i] = v;
    insert(p[i], v);
  }
  ++cur;
  for (int i = n; i >= 1; --i) {
    int v = (query(n, 1) - query(p[i]) + M) % M;
    g[i] = v;
    insert(p[i], v);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = (ans + (ll)f[i] * g[i]) % M;
  p[n + 1] = 0;
  vector<int> smx = {n + 1};
  for (int i = n; i >= 1; --i)
    if (p[i] > p[smx.back()]) smx.push_back(i);
  for (int i = 1, li = smx.size(); i < li; ++i) {
    int lb = p[smx[i - 1]] + 1, rb = p[smx[i]];
    vector<int> candidate;
    for (int j = lb; j <= rb; ++j) {
      if (ip[j] <= smx[i]) candidate.push_back(ip[j]);
    }
    sort(all(candidate), greater<>());
    ++cur;
    for (int j : candidate) {
      int v = (query(n, j == smx[i]) - query(p[j]) + M) % M;
      ans = (ans - (ll)f[j] * v) % M;
      insert(p[j], v);
    }
  }
  ans = (ans + M) % M;
  printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T = 1;
  read(T);
  while (T--)
    solvecase();
  return 0;
}