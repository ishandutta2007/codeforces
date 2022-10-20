#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <queue>
#include <unistd.h>
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

int rep[N], lf[N], siz[N];
int find(int x) { return !rep[x] ? x : rep[x] = find(rep[x]); }

using pii = pair<int, int>;
pair<int, int> bit[N];
void insert(int p, pii v) {
  for (; p < N; p += p & -p)
    bit[p].first += v.first, bit[p].second += v.second;
}
pii query(int p) {
  pii s(0, 0);
  for (; p; p &= p - 1)
    s.first += bit[p].first, s.second += bit[p].second;
  return s;
}

vector<int> G[N];
vector<pair<int, int>> Q[N];
int fa[N];
priority_queue<pair<int, int>> h;
int L[N], R[N], dfc = 0;
int res[N];
bool vis[N];

void DFS(int u) {
  L[u] = ++dfc;
  for (int v : G[u]) {
    if (v == fa[u]) continue;
    fa[v] = u;
    DFS(v);
  }
  R[u] = dfc;
}

pii eval(int u) {
  pii r = query(R[u]), l = query(L[u] - 1);
  return {r.first - l.first, r.second - l.second};
}

void update(int u) {
  pii s = eval(u);
  h.emplace((s.second + lf[u] - 1) / (s.first + 1), u);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  lf[1] = G[1].size();
  for (int i = 2; i <= n; ++i)
    lf[i] = G[i].size() - 1;
  fill(siz + 1, siz + 1 + n, 1);
  for (int i = 2; i <= n; ++i)
    if (lf[i]) h.emplace(lf[i] - 1, i);

  DFS(1);
  int qc;
  read(qc);
  for (int i = 1; i <= qc; ++i) {
    int u, k;
    read(u, k);
    Q[k].emplace_back(u, i);
  }

  for (int k = 200000; k >= 0; --k) {
    while (!h.empty() && h.top().first >= k) {
      int u = h.top().second;
      h.pop();
      if (vis[u]) continue;
      vis[u] = true;
      pii p = eval(u);
      ++p.first;
      p.second += lf[u] - 1;
      rep[u] = fa[u];
      int f = find(u);
      insert(L[fa[u]], p);
      if (fa[f]) insert(L[fa[f]], pii(-p.first, -p.second));
      if (f != 1) update(f);
    }
    for (pii q : Q[k]) {
      pii e = eval(q.first);
      res[q.second] = max(lf[q.first], e.second - k * e.first + lf[q.first]);
    }
  }

  for (int i = 1; i <= qc; ++i)
    printf("%d\n", res[i]);
  return 0;
}