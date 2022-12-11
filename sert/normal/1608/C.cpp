#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif

struct K {
  int a, b, i;
};
bool cmpA(const K &k1, const K &k2) { return k1.a > k2.a; };
bool cmpB(const K &k1, const K &k2) { return k1.b > k2.b; };

void dfsOrd(int v, vector<bool> &u, const vector<vector<int>> &es, vector<int> &ord) {
  if (u[v]) return;
  u[v] = true;
  for (int w : es[v])
    dfsOrd(w, u, es, ord);
  ord.push_back(v);
}

void dfsBak(int v, const vector<vector<int>> &es, string &ans) {
  if (ans[v] == '1') return;
  ans[v] = '1';
  for (int w : es[v])
    dfsBak(w, es, ans);
}

void solve() {
  int n;
  cin >> n;
  vector<K> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].a;
    v[i].i = i;
  }
  for (int i = 0; i < n; i++) cin >> v[i].b;
  sort(v.begin(), v.end(), cmpA);
  vector<vector<int>> es(n);
  vector<vector<int>> eo(n);
  for (int i = 1; i < n; i++) {
    es[v[i - 1].i].push_back(v[i].i);
    eo[v[i].i].push_back(v[i - 1].i);
  }
  sort(v.begin(), v.end(), cmpB);
  for (int i = 1; i < n; i++) {
    es[v[i - 1].i].push_back(v[i].i);
    eo[v[i].i].push_back(v[i - 1].i);
  }
  vector<bool> u(n, false);
  vector<int> ord;
  for (int i = 0; i < n; i++) {
    dfsOrd(i, u, es, ord);
  }
  string ans(n, '0');
  dfsBak(ord.back(), eo, ans);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  cin >> t;
  while (t--) {
    solve();
  }
}