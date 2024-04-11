#include <bits/stdc++.h>

using namespace std;

string query(vector<int> d) {
  cout << "?";
  for (auto x : d) {
    cout << " " << x;
  }
  cout << endl;
  string verdict;
  cin >> verdict;
  return verdict;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> layer(n);
  vector<vector<int>> down(n);
  vector<bool> found(n + 1);
  found[0] = found[n] = true;
  layer[0].push_back(0);
  for (int i = 1; i < n; ++i) {
    down[0].push_back(i);
  }
  while (true) {
    bool changed = false;
    vector<int> p;
    for (int i = 0; i <= n; ++i) {
      if (found[i]) {
        p.push_back(i);
      }
    }
    for (int first = 0; first < 2; ++first) {
      vector<int> small(n);
      vector<int> large(n);
      for (int i = first; i + 1 < (int) p.size(); i += 2) {
        if (layer[p[i]].empty() || p[i + 1] == p[i] + 1) {
          continue;
        }
        if (p[i + 1] == p[i] + 2) {
          swap(layer[p[i] + 1], down[p[i]]);
          found[p[i] + 1] = true;
          continue;
        }
        changed = true;
        int mid = (p[i] + p[i + 1]) >> 1;
        for (auto x : layer[p[i]]) {
          small[x] = mid - p[i] - 1;
          large[x] = mid - p[i];
        }
      }
      string in_small = query(small);
      string in_large = query(large);
      for (int i = first; i + 1 < (int) p.size(); i += 2) {
        if (layer[p[i]].empty() || p[i + 1] <= p[i] + 2) {
          continue;
        }
        int mid = (p[i] + p[i + 1]) >> 1;
        vector<int> new_down;
        for (auto x : down[p[i]]) {
          if (in_small[x] == '1') {
            new_down.push_back(x);
          } else if (in_large[x] == '1') {
            layer[mid].push_back(x);
          } else {
            down[mid].push_back(x);
          }
        }
        swap(down[p[i]], new_down);
        found[mid] = true;
      }
    }
    if (!changed) {
      break;
    }
  }
  vector<int> parent(n);
  for (int first = 1; first <= 3; ++first) {
    for (int i = 0; 1 << i < n; ++i) {
      vector<int> d(n);
      for (int j = first; j < n; j += 3) {
        if (!layer[j].empty()) {
          for (auto x : layer[j - 1]) {
            if (x >> i & 1) {
              d[x] = 1;
            }
          }
        }
      }
      string verdict = query(d);
      for (int j = first; j < n; j += 3) {
        if (!layer[j].empty()) {
          for (auto x : layer[j]) {
            if (verdict[x] == '1') {
              parent[x] |= 1 << i;
            }
          }
        }
      }
    }
  }
  cout << "!" << endl;
  for (int i = 1; i < n; ++i) {
    cout << parent[i] + 1 << " " << i + 1 << endl;
  }
  return 0;
}