#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (auto&& e : x) {
    cin >> e;
  }
  set<int> se(begin(x), end(x));
  using P = pair<int, int>;
  priority_queue< P, vector<P>, greater<P> > pq;
  for (int e : x) {
    for (int z : {e - 1, e + 1}) {
      if (not se.count(z)) {
        pq.emplace(1, z);
      }
    }
  }
  long long res = 0;
  vector<int> y;
  while ((int)y.size() < m) {
    int d, z;
    tie(d, z) = pq.top();
    pq.pop();
    if (se.count(z)) {
      continue;
    }
    res += d;
    y.push_back(z);
    se.insert(z);
    for (int w : {z - 1, z + 1}) {
      if (not se.count(w)) {
        pq.emplace(d + 1, w);
      }
    }
  }
  cout << res << '\n';
  for (int i = 0; i < m; ++i) {
    cout << y[i] << " \n"[i == m - 1];
  }
}