#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) {
      b[a[i]]++;
    }
    vector<int> ans;
    auto mex = [&](int p) {
      int r = 0;
      while (b[r]) {
        r++;
      }
      b[a[p]]--;
      a[p] = r;
      b[a[p]]++;
      ans.push_back(p);
    };
    for (int t = 0; t < n; ++t) {
      for (int i = 0; i < n; ++i) {
        if (!b[i]) {
          mex(i);
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[j] == i) {
          mex(j);
        }
      }
      if (a[i] != i) {
        mex(i);
      }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int) ans.size(); ++i) {
      if (i) {
        cout << " ";
      }
      cout << ans[i] + 1;
    }
    cout << "\n";
  }
  return 0;
}