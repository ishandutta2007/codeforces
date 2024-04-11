#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto&& e : s) cin >> e;
  sort(begin(s), end(s));
  vector<bool> used(w);
  for (int l = 0; l < h;) {
    int r = l;
    while (r < h and s[r] == s[l]) ++r;
    for (int j = 0; j < w; ++j)
      if (s[l][j] == '#') {
        if (used[j]) {
          cout << "No\n";
          exit(0);
        }
        used[j] = true;
      }
    l = r;
  }
  cout << "Yes\n";
}