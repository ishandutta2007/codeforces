#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    int ansK = 1;
    for (int i = 1; i < n; ++i) {
      string a(s.substr(0, i));
      string b(s.substr(i, n - i));
      if ((n - i) % 2 == 1) {
        reverse(a.begin(), a.end());
      }
      string c = b + a;
      if (c < ans) {
        ans = c;
        ansK = i + 1;
      }
    }
    cout << ans << "\n";
    cout << ansK << "\n";
  }
}