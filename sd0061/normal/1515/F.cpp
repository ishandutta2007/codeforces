#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int N = 300005;
int n, m, c;
int f[N], s[N];
int64 a[N];
set<int> edges[N];
set<pair<int64, int>> asphalt;
vector<pair<int, int>> E;

int getf(int x) { return x == f[x] ? x : f[x] = getf(f[x]); }

int main() {
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int w;
    scanf("%d", &w);
    a[i] = w;
    asphalt.insert(make_pair(w, i));
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    E.emplace_back(x, y);
    edges[x].insert(i);
    edges[y].insert(i);
  }
  vector<int> res;

  while (asphalt.size() > 1) {
    auto [w, x] = *asphalt.rbegin();
    asphalt.erase(make_pair(w, x));
    // cout << x << ' ' << w << endl;
    assert(getf(x) == x);
    int e = -1;
    do {
      e = edges[x].empty() ? -1 : *edges[x].begin();
      edges[x].erase(e);
    } while (e != -1 && getf(E[e].first) == getf(E[e].second));

    if (e == -1) {
      puts("NO");
      return 0;
    }
    res.push_back(e);

    int y = getf(E[e].first) == x ? getf(E[e].second) : getf(E[e].first);
    int64 u = a[y];
    asphalt.erase(make_pair(u, y));
    // cout << "-->  " << y << ' ' << u << endl;
    if (w + u < c) {
      puts("NO");
      return 0;
    }

    if (edges[x].size() < edges[y].size()) {
      swap(edges[x], edges[y]);
    }
    while (!edges[y].empty()) {
      auto it = edges[y].begin();
      edges[x].insert(*it);
      edges[y].erase(it);
    }
    a[x] = w + u - c;
    asphalt.insert(make_pair(a[x], x));
    a[y] = 0;
    f[y] = x;
  }
  puts("YES");
  for (int i = 0; i < res.size(); ++i) {
    printf("%d\n", res[i] + 1);
  }
}