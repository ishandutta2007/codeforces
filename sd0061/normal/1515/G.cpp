#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int N = 200005;

int n, m;
vector<pair<int, int>> e[N];
int64 res[N];
namespace tarjan {
int low[N], ord[N];
int scnt, bel[N];
bool in_stack[N];
int64 depth[N], loop[N];
std::stack<int> stack;
void dfs(int x, int&& ncnt) {
  low[x] = ord[x] = ++ncnt;
  in_stack[x] = 1;
  stack.push(x);
  for (auto& [y, w] : e[x]) {
    if (!ord[y]) {
      depth[y] = depth[x] + w;
      dfs(y, std::move(ncnt));
      low[x] = std::min(low[x], low[y]);
    } else if (in_stack[y]) {
      low[x] = std::min(low[x], ord[y]);
      loop[x] = __gcd(loop[x], depth[x] - depth[y] + w);
    }
  }
  if (low[x] == ord[x]) {
    while (true) {
      int i = stack.top();
      stack.pop();
      in_stack[i] = false;
      bel[i] = scnt;
      res[scnt] = __gcd(res[scnt], loop[i]);
      if (i == x) {
        break;
      }
    }
    ++scnt;
  }
}
void GetSCC() {
  std::fill(ord, ord + n, 0);
  scnt = 0;
  for (int i = 0; i < n; ++i) {
    if (!ord[i]) {
      dfs(i, 0);
    }
  }
}

}  // namespace tarjan

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x, --y;
    e[x].emplace_back(y, z);
  }
  tarjan::GetSCC();
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, s, t;
    scanf("%d%d%d", &x, &s, &t);
    --x;
    bool f = 0;
    if (s == 0) {
      f = 1;
    } else {
      int64 l = res[tarjan::bel[x]];
      if (!l) {
        f = 0;
      } else {
        f = ((t - s) % __gcd(l, 1LL * t) == 0);
      }
    }
    // printf("%d %lld - ", p, cnt[bel[x]]);
    puts(f ? "YES" : "NO");
  }
}