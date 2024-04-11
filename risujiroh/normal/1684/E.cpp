#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++freq[a];
    }

    int mex = 0;
    int r = n;
    while (freq.count(mex)) {
      ++mex;
      --r;
    }
    int c = 0;
    for (int _ = k; _--;) {
      if (r == 0) break;
      ++c;
      ++mex;
      while (freq.count(mex)) {
        ++mex;
        --r;
      }
    }

    vector<int> v;
    for (auto it = freq.upper_bound(mex); it != end(freq); ++it) {
      v.push_back(it->second);
    }
    sort(begin(v), end(v));
    int ans = int(size(v));
    for (int e : v) {
      if (c < e) {
        break;
      } else {
        --ans;
        c -= e;
      }
    }
    cout << ans << '\n';
  }
}