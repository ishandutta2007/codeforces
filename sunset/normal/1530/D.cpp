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
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++d[--a[i]];
    }
    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
      if (!d[i]) {
        leaves.push_back(i);
      }
    }
    cout << n - leaves.size() << "\n";
    if (leaves.empty()) {
      for (int i = 0; i < n; ++i) {
        if (i) {
          cout << " ";
        }
        cout << a[i] + 1;
      }
      cout << "\n";
    } else if ((int) leaves.size() == 1) {
      int i = leaves[0];
      while (d[i] < 2) {
        i = a[i];
      }
      int j = i;
      while (a[j] != i) {
        j = a[j];
      }
      a[j] = leaves[0];
      for (int i = 0; i < n; ++i) {
        if (i) {
          cout << " ";
        }
        cout << a[i] + 1;
      }
      cout << "\n";
    } else {
      vector<int> b(n, -1);
      vector<bool> e(n);
      vector<int> links;
      for (int i = 0; i < n; ++i) {
        if (!e[a[i]]) {
          e[a[i]] = true;
          b[i] = a[i];
        } else {
          links.push_back(i);
        }
      }
      vector<int> s(n);
      for (int i : leaves) {
        s[i] |= 2;
      }
      for (int i : links) {
        s[i] |= 1;
      }
      vector<int> foo;
      vector<int> bar;
      vector<int> baz;
      for (int i = 0; i < n; ++i) {
        if (s[i] == 1) {
          foo.push_back(i); 
        } else if (s[i] == 2) {
          bar.push_back(i);
        } else if (s[i] == 3) {
          baz.push_back(i);
        }
      }
      if ((int) baz.size() == 1) {
        b[foo[0]] = baz[0];
        b[baz[0]] = bar[0];
        for (int i = 1; i < (int) foo.size(); ++i) {
          b[foo[i]] = bar[i];
        }
      } else {
        for (int i = 0; i < (int) baz.size(); ++i) {
          b[baz[i]] = baz[(i + 1) % baz.size()];
        }
        for (int i = 0; i < (int) foo.size(); ++i) {
          b[foo[i]] = bar[i];
        }
      }
      for (int i = 0; i < n; ++i) {
        if (i) {
          cout << " ";
        }
        cout << b[i] + 1;
      }
      cout << "\n";
    }
  }
  return 0;
}