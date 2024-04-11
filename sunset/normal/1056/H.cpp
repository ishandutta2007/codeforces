#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 567;

bool solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(m);
  for (int i = 0; i < m; ++i) {
    int s;
    scanf("%d", &s);
    a[i].resize(s);
    for (int j = 0; j < s; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
    }
  }
  vector<vector<pair<int, pair<int, int>>>> go(n);
  for (int i = 0; i < m; ++i) {
    if (a[i].size() > BLOCK) {
      vector<int> id(n, -1);
      for (int j = 0; j < a[i].size(); ++j) {
        id[a[i][j]] = j;
      }
      for (int j = 0; j < m; ++j) {
        if (j != i) {
          int last = n;
          for (auto x : a[j]) {
            if (~id[x]) {
              if (last < id[x] - 1) {
                return false;
              }
              last = id[x];
            }
          }
        }
      }
    } else {
      for (int j = 0; j + 1 < a[i].size(); ++j) {
        go[a[i][j]].emplace_back(a[i][j + 1], make_pair(i, j));
      }
    }
  }
  vector<int> id(n);
  int tt = 0;
  for (int i = 0; i < n; ++i) {
    int old = ++tt;
    sort(go[i].begin(), go[i].end());
    for (int ll = 0, rr = 0; ll < go[i].size(); ll = rr) {
      while (rr < go[i].size() && go[i][rr].first == go[i][ll].first) {
        ++rr;
      }
      ++tt;
      for (int j = ll; j < rr; ++j) {
        int x = go[i][j].second.first, ptr = go[i][j].second.second;
        for (int k = ptr + 1; k < a[x].size(); ++k) {
          if (id[a[x][k]] >= old && id[a[x][k]] < tt) {
            return false;
          }
          id[a[x][k]] = tt;
        }
      }
    }
  }
  return true;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    puts(solve() ? "Robot" : "Human");
  }
  return 0;
}