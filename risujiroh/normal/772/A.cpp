#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, p;
  cin >> n >> p;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  if (p >= accumulate(begin(a), end(a), 0LL)) {
    cout << "-1\n";
    exit(0);
  }
  auto chk = [&](double t) {
    double need = 0;
    for (int i = 0; i < n; ++i) {
      need += max(t * a[i] - b[i], 0.0);
    }
    return need <= t * p;
  };
  double ok = 0, ng = 1e20;
  for (int _ = 100; _--; ) {
    double mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}