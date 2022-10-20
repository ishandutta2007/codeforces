#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int m, n, k, t;
  cin >> m >> n >> k >> t;
  vector<int> a(m);
  for (auto&& e : a) {
    cin >> e;
  }
  sort(rbegin(a), rend(a));
  vector<int> l(k), r(k), d(k);
  for (int j = 0; j < k; ++j) {
    cin >> l[j] >> r[j] >> d[j];
    --l[j];
  }
  auto chk = [&](int mid) -> bool {
    vector<int> imos(n + 1);
    for (int j = 0; j < k; ++j) {
      if (d[j] > a[mid - 1]) {
        ++imos[l[j]];
        --imos[r[j]];
      }
    }
    for (int i = 0; i < n; ++i) {
      imos[i + 1] += imos[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += imos[i] > 0;
    }
    return n + 1 + 2 * sum <= t;
  };
  int ok = 0, ng = m + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}