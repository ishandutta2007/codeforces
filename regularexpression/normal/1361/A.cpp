#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    --t[i];
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (const int& x, const int& y) {
    return t[x] < t[y];
  });
  set<int> have;
  for (int i = 0; i < n; ++i)
    have.insert(i);
  for (int x : p) {
    for (int y : g[x])
      have.erase(t[y]);
    if (*have.begin() != t[x]) {
      cout << "-1\n";
      return 0;
    }
    for (int y : g[x])
      have.insert(t[y]);
  }
  for (auto x : p)
    cout << x + 1 << " ";
  return 0;
}