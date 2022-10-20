#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <queue>
#include <list>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

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

const int N = 250005;

vector<pair<int, int>> G[N];
int dfn[N], dfs_id = 0;

struct dual_heap {
  priority_queue<int, vector<int>, greater<int>> in;
  priority_queue<int> out;
  ll sum;

  int in_cnt() { return in.size(); }
  int out_cnt() { return out.size(); }
  void push(int x) {
    if ((in.empty() && out.empty()) || (in.empty() && x >= out.top()) || x >= in.top())
      in.push(x), sum += x;
    else out.push(x);
  }
  void move_in() { assert(!out.empty()); sum += out.top(); in.push(out.top()); out.pop(); }
  void move_out() { assert(!in.empty()); sum -= in.top(); out.push(in.top()); in.pop(); }
  ll min_in() { return in.top(); }
};

dual_heap H[N];

int fa[N], faw[N];
int ord[N], ordc = 0;
int lim;
ll res = 0;
vector<int> deg_v[N];
bool del[N];
ll dp[N][2];

list<int> undel;

void preDFS(int x) {
  ord[++ordc] = x;
  for (const auto &[v, w] : G[x]) {
    if (v == fa[x]) continue;
    fa[v] = x; faw[v] = w;
    preDFS(v);
  }
}

void del_node(int x) {
  del[x] = true;
  for (const auto &[v, w] : G[x])
    if (del[v])
      res -= w;
    else
      H[v].push(w);
}

void DFS(int x) {
  dfn[x] = lim;
  vector<ll> aug;
  ll sum = 0;
  for (const auto &[v, w] : G[x]) {
    if ((int)G[v].size() <= lim) break;
    if (v == fa[x]) continue;
    DFS(v);
    aug.push_back(dp[v][1] - dp[v][0]);
    sum += dp[v][0];
  }
  sort(begin(aug), end(aug));
  while (H[x].in_cnt() < lim && H[x].out_cnt())
    H[x].move_in();
  while (H[x].in_cnt() > lim)
    H[x].move_out();
  int icnt = H[x].in_cnt();
  ll min_in = H[x].in_cnt() ? H[x].min_in() : 0x3f3f3f3f3f3f3f3fLL;
  for (auto it = aug.rbegin(); it != aug.rend(); ++it) {
    if (*it > 0 && (icnt < lim || *it > min_in)) {
      ++icnt;
      min_in = min(min_in, *it);
      sum += *it;
    }
    if (icnt > lim)
      H[x].move_out(), --icnt, min_in = min(*it, H[x].in_cnt() ? H[x].min_in() : 0x3f3f3f3f3f3f3f3fLL);
  }
  dp[x][0] = sum + H[x].sum;
  if (icnt < lim)
    dp[x][1] = dp[x][0] + faw[x];
  else
    dp[x][1] = dp[x][0] - min_in + faw[x];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    read(u, v, w);
    G[u].emplace_back(v, w); G[v].emplace_back(u, w);
    res += w;
  }
  for (int i = 1; i <= n; ++i)
    sort(G[i].begin(), G[i].end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
      return G[a.first].size() > G[b.first].size();
    });
  for (int i = 1; i <= n; ++i)
    deg_v[G[i].size()].push_back(i);
  preDFS(1);
  undel.resize(n);
  copy(ord + 1, ord + 1 + n, undel.begin());
  printf("%lld", res);

  for (int i = 1; i < n; ++i) {
    lim = i;
    for (int x : deg_v[i])
      del_node(x);
    ll sum = res;
    for (auto it = undel.begin(); it != undel.end(); ) {
      if (del[*it]) {
        ++it;
        undel.erase(prev(it));
        continue;
      }
      if (dfn[*it] == i) {
        ++it;
        continue;
      }
      DFS(*it);
      sum -= dp[*it][0];
      ++it;
    }
    printf(" %lld", sum);
  }
  putchar('\n');
  return 0;
}