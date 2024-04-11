#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, p;
  cin >> s >> p;

  vector<bool> u(s.length(), false);
  string res;

  for (char ch : p) {
    int pos = -1;
    for (int i = 0; i < static_cast<int>(s.length()); i++) {
      if (s[i] == ch && !u[i]) {
        pos = i;
      }
    }
    if (pos == -1) {
      cout << "NO\n";
      return;
    }
    u[pos] = true;
  }

  for (size_t i = 0; i < u.size(); i++) {
    if (u[i]) res.push_back(s[i]);
  }

  cout << (res == p ? "YES\n" : "NO\n");
}

int main() {
#ifdef SERT
  freopen("../a.in", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}