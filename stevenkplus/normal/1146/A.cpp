#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      ++cnt;
    }
  }

  int ans = min(n, cnt + cnt - 1);
  cout << ans << "\n";
}