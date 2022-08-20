#include <bits/stdc++.h>

using namespace std;

vector<bool> ask(vector<int> a) {
  if (a.empty()) {
    return vector<bool>();
  }
  cout << "Q " << a.size() / 2;
  for (auto x : a) {
    cout << " " << x;
  }
  cout << endl;
  string verdict;
  cin >> verdict;
  vector<bool> ans(a.size() / 2);
  for (int i = 0; i < (int) a.size() / 2; ++i) {
    ans[i] = verdict[i] == '1';
  }
  return ans;
}

vector<bool> query(vector<int> a) {
  int n = a.size();
  vector<bool> ans(n - 1);
  vector<int> even_query;
  for (int i = 0; i + 1 < n; i += 2) {
    even_query.push_back(a[i]);
    even_query.push_back(a[i + 1]);
  }
  vector<bool> even = ask(even_query);
  for (int i = 0; i < (int) even.size(); ++i) {
    ans[i * 2] = even[i];
  }
  vector<int> odd_query;
  for (int i = 1; i + 1 < n; i += 2) {
    odd_query.push_back(a[i]);
    odd_query.push_back(a[i + 1]);
  }
  vector<bool> odd = ask(odd_query);
  for (int i = 0; i < (int) odd.size(); ++i) {
    ans[i * 2 + 1] = odd[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = i + 1;
    }
    vector<bool> same = query(a);
    vector<int> cut(1, 1);
    for (int i = 0; i < n - 1; ++i) {
      if (!same[i]) {
        cut.push_back(a[i] + 1);
      }
    }
    int m = cut.size();
    if (m == 1) {
      cout << "A 0 0 " << n << endl;
      cout << endl;
      cout << endl;
      for (int i = 1; i <= n; ++i) {
        if (i > 1) {
          cout << " ";
        }
        cout << i;
      }
      cout << endl;
      continue;
    }
    vector<int> even, odd;
    for (int i = 0; i < m; ++i) {
      if (i & 1) {
        odd.push_back(cut[i]);
      } else {
        even.push_back(cut[i]);
      }
    }
    vector<bool> same_even = query(even), same_odd = query(odd);
    vector<int> color(m);
    color[0] = 0;
    color[1] = 1;
    for (int i = 2; i < m; ++i) {
      if (i & 1) {
        if (same_odd[i / 2 - 1]) {
          color[i] = color[i - 2];
        } else {
          color[i] = 3 - color[i - 2] - color[i - 1];
        }
      } else {
        if (same_even[i / 2 - 1]) {
          color[i] = color[i - 2];
        } else {
          color[i] = 3 - color[i - 2] - color[i - 1];
        }
      }
    }
    cut.push_back(n + 1);
    vector<vector<int>> ans(3);
    for (int i = 0; i < m; ++i) {
      for (int j = cut[i]; j < cut[i + 1]; ++j) {
        ans[color[i]].push_back(j);
      }
    }
    cout << "A " << ans[0].size() << " " << ans[1].size() << " " << ans[2].size() << endl;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < (int) ans[i].size(); ++j) {
        if (j) {
          cout << " ";
        }
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}