#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  map<string, int> mp;
  string ans, pal;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if (mp[t]) {
      ans += t;
    }
    mp[s] = 1;
    if (s == t) pal = s;
  }
  string rans = ans;
  reverse(rans.begin(), rans.end());
  ans += pal;
  ans += rans;
  cout << ans.size() << "\n" << ans << "\n";
}