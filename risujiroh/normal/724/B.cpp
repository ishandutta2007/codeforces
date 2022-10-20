#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  vector good(w, vector<bool>(w, true));
  bool any = false;
  for (int i = 0; i < h; ++i) {
    vector<int> pos;
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      --a[i][j];
      if (a[i][j] != j) pos.push_back(j);
    }
    if (size(pos) > 4) {
      cout << "NO\n";
      exit(0);
    }
    if (size(pos) == 4) {
      int x = -1, y = -1;
      for (int j = 0; j < w; ++j) {
        if (a[i][a[i][j]] != j) {
          cout << "NO\n";
          exit(0);
        }
        if (j < a[i][j]) (x == -1 ? x : y) = j;
      }
      any |= true;
      for (int r = 1; r < w; ++r)
        for (int l = 0; l < r; ++l) {
          if (l == x && r == a[i][x]) continue;
          if (l == y && r == a[i][y]) continue;
          good[l][r] = false;
        }
    }
    if (size(pos) == 3) {
      any |= true;
      for (int r = 1; r < w; ++r)
        for (int l = 0; l < r; ++l) {
          if (l == pos[0] && r == pos[1]) continue;
          if (l == pos[0] && r == pos[2]) continue;
          if (l == pos[1] && r == pos[2]) continue;
          good[l][r] = false;
        }
    }
    if (size(pos) == 2)
      for (int r = 1; r < w; ++r)
        for (int l = 0; l < r; ++l) {
          if (l == pos[0] && r == pos[1]) continue;
          good[l][r] = false;
        }
  }
  for (int r = 1; r < w; ++r)
    for (int l = 0; l < r; ++l)
      if (good[l][r]) {
        cout << "YES\n";
        exit(0);
      }
  cout << (any ? "NO\n" : "YES\n");
}