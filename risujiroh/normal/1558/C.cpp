#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
      --e;
    }

    {
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        if ((i ^ a[i]) & 1) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        cout << "-1\n";
        continue;
      }
    }

    vector<int> ans;

    auto go = [&](int len) {
      assert(len & 1);
      ans.push_back(len);
      reverse(begin(a), begin(a) + len);
    };

    for (int i = n; i-- > 1;) {
      int j = find(begin(a), end(a), i) - begin(a);

      if (~i & 1) {
        go(j + 1);
      } else {
        go(j);
        go(j + 2);
        go(3);
        go(i + 2);
      }
    }

    assert(is_sorted(begin(a), end(a)));

    int m = size(ans);
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << ans[i] << " \n"[i + 1 == m];
    }
  }
}