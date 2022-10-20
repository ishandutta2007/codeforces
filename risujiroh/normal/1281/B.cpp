#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, c;
    cin >> s >> c;
    int n = s.size();
    vector<char> mn(n + 1, 'z' + 1);
    for (int i = n; i--; ) {
      mn[i] = min(s[i], mn[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] != mn[i]) {
        int mi = i;
        for (int j = i; j < n; ++j) {
          if (s[j] <= s[mi]) {
            mi = j;
          }
        }
        swap(s[i], s[mi]);
        break;
      }
    }
    if (s < c) {
      cout << s << '\n';
    } else {
      cout << "---\n";
    }
  }
}