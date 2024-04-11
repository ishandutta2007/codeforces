#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)

int n, c[100000];
vector<int> graph[100000];

bool is_all(int v, int p, int x) {
  bool ok = c[v] == x;
  for (auto u : graph[v]) if (u != p) ok &= is_all(u, v, x);
  return ok;
}

bool check(int v) {
  bool ok = true;
  for (auto u : graph[v]) ok &= is_all(u, v, c[u]);
  return ok;
}

int us[100000], vs[100000];
int main() {
  scanf("%d", &n);
  rep(i, n - 1) {
    int u, v; scanf("%d%d", &u, &v); u--, v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
    us[i] = u, vs[i] = v;
  }
  rep(i, n) scanf("%d", c + i);
  rep(i, n - 1) if (c[us[i]] != c[vs[i]]) {
    for (auto v : vector{us[i], vs[i]}) if (check(v)) return printf("YES\n%d\n", v + 1), 0;
    return printf("NO\n"), 0;
  }
  printf("YES\n1\n");
}