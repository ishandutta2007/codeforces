#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  string res, tmp;
  for (int i = 0; i < n; i++) {
    if (s[i] != '1') res += s[i];
    else tmp += s[i];
  }
  int i = 0;
  while (res[i] == '0') i++;
  res.insert(i, tmp);
  cout << res << '\n';
  return 0;
}