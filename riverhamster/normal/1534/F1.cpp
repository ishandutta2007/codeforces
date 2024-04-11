#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)

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

const int N = 400005;

vector<int> pos[N];
char s[N];
int pre_id[N];
int a[N];

int dfn[N], low[N], scc[N], dfc = 0, stk[N], top = 0, scc_cnt;
bool instk[N];
vector<int> G[N], RG[N];
int r_ind[N];
bool key[N], vis[N];
int key_id[N], key_cnt;

struct range {
  int l, r;
  bool operator<(const range &r) const { return l < r.l; }
} ran[N];

void tarjan(int x) {
  dfn[x] = low[x] = ++dfc;
  stk[++top] = x; instk[x] = true;
  for (int v : G[x])
    if (!dfn[v]) tarjan(v), low[x] = min(low[x], low[v]);
    else if (instk[v]) low[x] = min(low[x], dfn[v]);
  if (low[x] == dfn[x]) {
    int tp;
    do {
      tp = stk[top--];
      instk[tp] = false;
      scc[tp] = scc_cnt;
    } while (tp != x);
    ++scc_cnt;
  }
}

void scc_dp() {
  vector<int> ord;
  for (int i = 0; i < scc_cnt; ++i)
    if (!r_ind[i]) ord.push_back(i);
  for (int i = 0; i < scc_cnt; ++i) {
    int x = ord[i];
    if (vis[x]) key[x] = false;
    if (key[x]) vis[x] = true;
    for (int v : RG[x]) {
      --r_ind[v];
      if (vis[x] || key[x]) vis[v] = true;
      if (!r_ind[v]) ord.push_back(v);
    }
  }
  for (int i = 0; i < scc_cnt; ++i)
    if (key[i]) key_id[i] = key_cnt++;
  for (auto i = rbegin(ord); i != rend(ord); ++i) {
    int x = *i;
    ran[x].l = key[x] ? key_id[x] : numeric_limits<int>::max();
    ran[x].r = key[x] ? key_id[x] : numeric_limits<int>::min();
    for (int v : RG[x]) {
      ran[x].l = min(ran[x].l, ran[v].l);
      ran[x].r = max(ran[x].r, ran[v].r);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j)
      if (s[j] == '#') pos[j].push_back(n - 1 - i);
  }
  for (int i = 0; i < m; ++i)
    read(a[i]);
  for (int i = 0; i < m; ++i)
    reverse(all(pos[i]));
  pre_id[0] = 0;
  for (int i = 1; i <= m; ++i)
    pre_id[i] = pre_id[i - 1] + pos[i - 1].size();
  for (int i = 0; i < m; ++i)
    for (auto it = begin(pos[i]); it != end(pos[i]); ++it) {
      int id = pre_id[i] + (it - begin(pos[i]));
      if (it != begin(pos[i])) G[id].push_back(id - 1);
      if (next(it) != end(pos[i]) && it[1] == *it + 1) G[id].push_back(id + 1);
      if (i != 0) {
        auto t = upper_bound(all(pos[i - 1]), *it);
        if (t != begin(pos[i - 1])) G[id].push_back(pre_id[i - 1] - 1 + (t - begin(pos[i - 1])));
      }
      if (i + 1 != m) {
        auto t = upper_bound(all(pos[i + 1]), *it);
        if (t != begin(pos[i + 1])) G[id].push_back(pre_id[i + 1] - 1 + (t - begin(pos[i + 1])));
      }
    }
  int nc = pre_id[m];
  for (int i = 0; i < nc; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 0; i < m; ++i)
    if (a[i])
      key[scc[pre_id[i] + a[i] - 1]] = true;
  for (int i = 0; i < nc; ++i)
    for (int v : G[i])
      if (scc[i] != scc[v]) RG[scc[i]].push_back(scc[v]), ++r_ind[scc[v]];
  scc_dp();
  sort(ran, ran + scc_cnt);
  int max_r = -1, nmax_r = 0, res = 0;
  for (int i = 0; i < scc_cnt && max_r + 1 < key_cnt; ++i) {
    nmax_r = max(nmax_r, ran[i].r);
    if (i + 1 == scc_cnt || ran[i + 1].l > max_r + 1)
      ++res, max_r = nmax_r;
  }
  printf("%d\n", res);
  return 0;
}