#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 41;

void dfs(int v, const vector<vector<int>> &es, vector<bool> &u, int &num) {
  if (u[v]) return;
  u[v] = true;
  num++;
  for (int w: es[v]) dfs(w, es, u, num);
}

void solve() {  
  int n, x;
  cin >> n;
  vector<vector<int>> es(n), eo(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x > 0) {
        es[i].push_back(j);
        eo[j].push_back(i);
      }
    }
  }
  vector<bool> u1(n, false);
  vector<bool> u2(n, false);
  int a = 0, b = 0;
  dfs(0, es, u1, a);
  dfs(0, eo, u2, b);
  cout << (a == n && b == n ? "YES\n" : "NO\n");
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SERT
  for (int i = 0; i < 1; i++) solve();
#else
  solve();
#endif
}