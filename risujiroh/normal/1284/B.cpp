#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 1e6;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> c(lim + 2), v;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    vector<int> a(l);
    for (auto&& e : a) {
      cin >> e;
    }
    reverse(begin(a), end(a));
    if (is_sorted(begin(a), end(a))) {
      ++c[a[0]];
      v.push_back(a.back());
    }
  }
  for (int i = lim + 1; i--; ) {
    c[i] += c[i + 1];
  }
  long long res = (long long)n * n;
  for (int e : v) {
    res -= c[e];
  }
  cout << res << '\n';
}