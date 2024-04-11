#include <bits/stdc++.h>

using namespace std;

int main() {
  auto query = [&](vector<int> s, vector<int> t, int v) {
    cout << s.size() << "\n";
    for (int i = 0; i < (int) s.size(); ++i) {
      if (i) {
        cout << " ";
      }
      cout << s[i] + 1;
    }
    cout << "\n";
    cout << t.size() << "\n";
    for (int i = 0; i < (int) t.size(); ++i) {
      if (i) {
        cout << " ";
      }
      cout << t[i] + 1;
    }
    cout << "\n";
    cout << v + 1 << endl;
    int res;
    cin >> res;
    return res;
  };
  int n;
  cin >> n;
  vector<int> without_root;
  for (int i = 1; i < n; ++i) {
    without_root.push_back(i);
  }
  vector<int> sz(n);
  sz[0] = n;
  for (int i = 1; i < n; ++i) {
    sz[i] = query({0}, without_root, i);
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&](const int &x, const int &y) {
    return sz[x] < sz[y];
  });
  vector<pair<int, int>> ans;
  set<int> subtree;
  for (auto x : p) {
    if (sz[x] != 1) {
      while (!subtree.empty()) {
        vector<int> seq(subtree.begin(), subtree.end());
        if (!query({0}, seq, x)) {
          break;
        }
        int l = 0, r = (int) seq.size();
        while (l + 1 < r) {
          int mid = l + r + 1 >> 1;
          if (query({0}, vector<int>(seq.begin() + l, seq.begin() + mid), x)) {
            r = mid;
          } else {
            l = mid;
          }
        }
        ans.emplace_back(x, seq[l]);
        subtree.erase(seq[l]);
      }
    }
    subtree.insert(x);
  }
  cout << "ANSWER" << endl;
  for (auto p : ans) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }
  return 0;
}