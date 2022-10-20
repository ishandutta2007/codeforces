#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <unistd.h>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

template<size_t N>
struct DSU {
  int fa[N];
  void clear() { memset(fa, 0, sizeof(fa)); }
  int find(int x) { return !fa[x] ? x : fa[x] = find(fa[x]); }
  bool join(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    fa[x] = y;
    return true;
  }
};

const int N = 55;
const int MAXE = 280;
const int INF = 0x3f3f3f3f;

struct edge {
  int u, v, w;
  edge() = default;
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
  bool operator<(const edge &rhs) const { return w < rhs.w; }
};

vector<edge> S, E1, E2, E;
vector<edge> special;

DSU<N> D;

int fa[5];
int find(int x) {
  while (fa[x]) x = fa[x];
  return x;
}

int res = INF;

bool I[MAXE], T[MAXE];
pair<int, int> d[MAXE];
int pre[MAXE];
int deg[MAXE], lim[MAXE];
int wt[MAXE];
bool vis[MAXE];
int n, k;

void flip(int u) {
  I[u] ^= 1;
  if (I[u]) ++deg[E[u].u], ++deg[E[u].v];
  else --deg[E[u].u], --deg[E[u].v];
}

vector<pair<int, int>> G;

int augment() {
  memset(pre, -1, sizeof(pre));
  int ec = E.size();
  for (int i = 0; i < ec; ++i)
    wt[i] = I[i] ? -E[i].w : E[i].w;
  bool up = true;
  for (int i = 0; i < ec && up; ++i) {
    up = false;
    for (const auto &[x, y] : G) {
      pair<int, int> tp = {d[x].first + wt[y], d[x].second + 1};
      if (tp < d[y])
        d[y] = tp, pre[y] = x, up = true;
    }
  }
  pair<int, int> val = {INF, INF};
  int u = -1;
  for (int i = 0; i < ec; ++i)
    if (T[i] && d[i] < val) val = d[i], u = i;
  if (val.first > 1e8) return INF;
  do flip(u); while ((u = pre[u]) != -1);
  return val.first;
}

int MI(int val) {
  memset(deg, 0, sizeof(deg));
  memset(I, 0, sizeof(I));
  for (const auto &e : special)
    ++deg[e.u], ++deg[e.v];
  for (int i = 0; i < k; ++i)
    if (deg[i] > lim[i]) return INF;
  int card = special.size();
  const int ec = E.size();
  while (true) {
    D.clear();
    for (const auto &e : special)
      D.join(e.u, e.v);
    for (int i = 0; i < ec; ++i)
      if (I[i]) D.join(E[i].u, E[i].v);

    fill(d, d + ec, make_pair(INF, 0));
    memset(T, 0, sizeof(T));
    for (int i = 0; i < ec; ++i)
      if (!I[i] && D.find(E[i].u) != D.find(E[i].v))
        d[i] = {E[i].w, 0};
    for (int i = 0; i < ec; ++i)
      if (!I[i] && deg[E[i].u] < lim[E[i].u] && deg[E[i].v] < lim[E[i].v])
        T[i] = true;

    G.clear();
    for (int i = 0; i < ec; ++i) {
      if (!I[i]) continue;
      D.clear();
      for (const auto &e : special)
        D.join(e.u, e.v);
      --deg[E[i].u]; --deg[E[i].v];
      for (int j = 0; j < ec; ++j)
        if (j != i && I[j]) D.join(E[j].u, E[j].v);
      for (int j = 0; j < ec; ++j)
        if (!I[j] && D.find(E[j].u) != D.find(E[j].v)) G.emplace_back(i, j);
      for (int j = 0; j < ec; ++j)
        if (!I[j] && deg[E[j].u] < lim[E[j].u] && deg[E[j].v] < lim[E[j].v]) G.emplace_back(j, i);
      ++deg[E[i].u]; ++deg[E[i].v];
    }

    int ret = augment();
    if (ret == INF) break;
    val += ret; ++card;
  }

  if (card < n - 1) return INF;
  return val;
}

void DFS(vector<edge>::const_iterator it, int sum = 0) {
  if (it == end(S)) {
    res = min(res, MI(sum));
    return;
  }
  int fu = find(it->u), fv = find(it->v);
  DFS(next(it), sum);
  if (fu != fv) {
    fa[fu] = fv;
    special.push_back(*it);
    DFS(next(it), sum + it->w);
    special.pop_back();
    fa[fu] = 0;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, k);
  for (int i = 0; i < k; ++i)
    read(lim[i]);
  fill(lim + k, lim + n, INF);
  for (int u = 0; u < n; ++u)
    for (int v = u + 1; v < n; ++v) {
      int wt;
      read(wt);
      if (u < k && v < k) S.emplace_back(u, v, wt);
      else if (u < k && v > k) E1.emplace_back(u, v, wt);
      else E2.emplace_back(u, v, wt);
    }

  sort(all(E2));
  for (const auto &e : E2)
    if (D.join(e.u, e.v)) E.push_back(e);
  E.insert(E.end(), all(E1));

  DFS(begin(S));

  printf("%d\n", res);
  return 0;
}