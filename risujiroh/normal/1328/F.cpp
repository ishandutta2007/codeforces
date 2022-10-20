#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  map<int, int> mp;
  for (auto&& e : a) {
    cin >> e;
    ++mp[e];
  }
  for (auto e : mp) {
    if (e.second >= k) {
      cout << "0\n";
      exit(0);
    }
  }
  sort(begin(a), end(a));
  long long res = 1e18;
  {
    int r = k;
    while (r < n and a[r - 1] == a[r]) {
      ++r;
    }
    long long cur = 0;
    for (int i = 0; i < r; ++i) {
      cur += a[r - 1] - a[i];
      if (i < r - k and a[i] < a[r - 1]) {
        --cur;
      }
    }
    res = min(res, cur);
  }
  {
    int l = n - k;
    while (l and a[l - 1] == a[l]) {
      --l;
    }
    long long cur = 0;
    for (int i = l; i < n; ++i) {
      cur += a[i] - a[l];
      if (i >= l + k and a[i] > a[l]) {
        --cur;
      }
    }
    res = min(res, cur);
  }
  vector<long long> cum(n + 1);
  for (int i = n; i--; ) {
    cum[i] = a[i] + cum[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    long long cur = i * a[i] - (cum[0] - cum[i]);
    cur += (cum[i] - cum[n]) - (n - i) * a[i];
    cur -= n - k;
    res = min(res, cur);
  }
  cout << res << '\n';
}