#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    map<char, int> cnt0, cnt;
    for (int i = 0; i < k; i++) { cnt0[s[i]]++; if (cnt0.size() >= 2) break; }
    for (int i = k; i < n; i++) { cnt[s[i]]++; if (cnt.size() >= 2) break; }
    if (cnt0.size() >= 2) {
      cout << s[k-1] << endl;
    } else if (cnt.size() != 1) {
      cout << s.substr(k-1) << endl;
    } else {
      int u = (cnt.begin()->second + k - 1) / k;
      char c = cnt.begin()->first;
      cout << s[k-1];
      while (u--) cout << c;
      cout << endl;
    }
  }
}